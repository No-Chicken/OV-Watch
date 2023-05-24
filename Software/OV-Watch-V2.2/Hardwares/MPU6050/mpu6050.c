#include "mpu6050.h"

#define MPU_INT_PORT GPIOB
#define MPU_INT_PIN  GPIO_PIN_12

#define CLK_ENABLE __HAL_RCC_GPIOB_CLK_ENABLE();

iic_bus_t MPU_bus = 
{
	.IIC_SDA_PORT = GPIOB,
	.IIC_SCL_PORT = GPIOB,
	.IIC_SDA_PIN  = GPIO_PIN_13,
	.IIC_SCL_PIN  = GPIO_PIN_14,
};

void MPU_INT_Pin_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin : PB12 */
  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void MPU_Motion_Init(void)			
{
    MPU_Write_Byte(MPU_MOTION_DET_REG,0x01);    //set the acceleration threshold is (LSB*2)mg
    MPU_Write_Byte(MPU_MOTION_DUR_REG,0x01);    //Acceleration detection time is ()ms 
    MPU_Write_Byte(MPU_INTBP_CFG_REG,0X90);     //INT Pin active low level, reset until 50us
    MPU_Write_Byte(MPU_INT_EN_REG,0x40);       	//enable INT
}

//初始化MPU6050
//返回值:0,成功
//    其他,错误代码
u8 MPU_Init(void)
{ 
	u8 res;
	CLK_ENABLE;
	IICInit(&MPU_bus);
	
	MPU_Write_Byte(MPU_PWR_MGMT1_REG,0X80);	//复位MPU6050
  delay_ms(100);
	MPU_Write_Byte(MPU_PWR_MGMT1_REG,0X00);	//唤醒MPU6050 
	MPU_Set_Gyro_Fsr(3);										//陀螺仪传感器,±2000dps
	MPU_Set_Accel_Fsr(2);										//加速度传感器,±8g
	MPU_Set_Rate(50);												//设置采样率50Hz
	MPU_Write_Byte(MPU_INT_EN_REG,0X00);		//关闭所有中断
	MPU_Write_Byte(MPU_USER_CTRL_REG,0X00);	//IIC主模式关闭
	MPU_Write_Byte(MPU_FIFO_EN_REG,0X00);		//关闭FIFO
	MPU_Write_Byte(MPU_INTBP_CFG_REG,0X80);	//INT active low
	
	res=MPU_Read_Byte(MPU_DEVICE_ID_REG);
	if(res==MPU_ADDR)//器件ID正确
	{
		MPU_Write_Byte(MPU_PWR_MGMT1_REG,0X29);	//设置CLKSEL,PLL X轴为参考,sleep=0,cycle=1,TEMP_DIS=1//low power modes
		MPU_Write_Byte(MPU_PWR_MGMT2_REG,0X47);	//enable accelerometer,disanable gyroscope,set the wake up frequence=5Hz
		MPU_Set_Rate(200);												//设置采样率为200Hz
 	}else return 1;
	
	MPU_Motion_Init();
	MPU_INT_Pin_Init();
	
	
	return 0;
}

void MPU_Sleep()
{
	MPU_Write_Byte(MPU_PWR_MGMT1_REG,0x49);//sleep=1,cycle=0,temp_dis=1,PLL->x reference
}

void MPU_Wakeup()
{
	//low power modes
	MPU_Write_Byte(MPU_PWR_MGMT1_REG,0x29);//sleep=0,cycle=1,temp_dis=1,PLL->x reference
}

uint8_t MPU_Read_Status()
{
	return MPU_Read_Byte(MPU_INT_STA_REG);
}

//设置MPU6050陀螺仪传感器满量程范围
//fsr:0,±250dps;1,±500dps;2,±1000dps;3,±2000dps
//返回值:0,设置成功
//    其他,设置失败 
u8 MPU_Set_Gyro_Fsr(u8 fsr)
{
	return MPU_Write_Byte(MPU_GYRO_CFG_REG,fsr<<3);//设置陀螺仪满量程范围  
}
//设置MPU6050加速度传感器满量程范围
//fsr:0,±2g;1,±4g;2,±8g;3,±16g
//返回值:0,设置成功
//    其他,设置失败 
u8 MPU_Set_Accel_Fsr(u8 fsr)
{
	return MPU_Write_Byte(MPU_ACCEL_CFG_REG,fsr<<3);//设置加速度传感器满量程范围  
}
//设置MPU6050的数字低通滤波器
//lpf:数字低通滤波频率(Hz)
//返回值:0,设置成功
//    其他,设置失败 
u8 MPU_Set_LPF(u16 lpf)
{
	u8 data=0;
	if(lpf>=188)data=1;
	else if(lpf>=98)data=2;
	else if(lpf>=42)data=3;
	else if(lpf>=20)data=4;
	else if(lpf>=10)data=5;
	else data=6; 
	return MPU_Write_Byte(MPU_CFG_REG,data);//设置数字低通滤波器  
}
//设置MPU6050的采样率(假定Fs=1KHz)
//rate:4~1000(Hz)
//返回值:0,设置成功
//    其他,设置失败 
u8 MPU_Set_Rate(u16 rate)
{
	u8 data;
	if(rate>1000)rate=1000;
	if(rate<4)rate=4;
	data=1000/rate-1;
	data=MPU_Write_Byte(MPU_SAMPLE_RATE_REG,data);	//设置数字低通滤波器
 	return MPU_Set_LPF(rate/2);	//自动设置LPF为采样率的一半
}

//得到温度值
//返回值:温度值(扩大了100倍)
short MPU_Get_Temperature(void)
{
    u8 buf[2]; 
    short raw;
		float temp;
		MPU_Read_Len(MPU_ADDR,MPU_TEMP_OUTH_REG,2,buf); 
    raw=((u16)buf[0]<<8)|buf[1];  
    temp=36.53+((double)raw)/340;  
    return temp*100;;
}
//得到陀螺仪值(原始值)
//gx,gy,gz:陀螺仪x,y,z轴的原始读数(带符号)
//返回值:0,成功
//    其他,错误代码
u8 MPU_Get_Gyroscope(short *gx,short *gy,short *gz)
{
    u8 buf[6],res;  
		res=MPU_Read_Len(MPU_ADDR,MPU_GYRO_XOUTH_REG,6,buf);
		if(res==0)
		{
			*gx=((u16)buf[0]<<8)|buf[1];  
			*gy=((u16)buf[2]<<8)|buf[3];  
			*gz=((u16)buf[4]<<8)|buf[5];
		} 	
    return res;;
}
//得到加速度值(原始值)
//gx,gy,gz:陀螺仪x,y,z轴的原始读数(带符号)
//返回值:0,成功
//    其他,错误代码
u8 MPU_Get_Accelerometer(short *ax,short *ay,short *az)
{
    u8 buf[6],res;  
		res=MPU_Read_Len(MPU_ADDR,MPU_ACCEL_XOUTH_REG,6,buf);
		if(res==0)
		{
			*ax=((u16)buf[0]<<8)|buf[1];  
			*ay=((u16)buf[2]<<8)|buf[3];  
			*az=((u16)buf[4]<<8)|buf[5];
		} 	
    return res;;
}
//IIC连续写
//addr:器件地址 
//reg:寄存器地址
//len:写入长度
//buf:数据区
//返回值:0,正常
//    其他,错误代码
u8 MPU_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{
	u8 i; 
  IICStart(&MPU_bus); 
	IICSendByte(&MPU_bus,(addr<<1)|0);//发送器件地址+写命令	
	if(IICWaitAck(&MPU_bus))	//等待应答
	{
		IICStop(&MPU_bus);		 
		return 1;		
	}
    IICSendByte(&MPU_bus,reg);	//写寄存器地址
    IICWaitAck(&MPU_bus);		//等待应答
	for(i=0;i<len;i++)
	{
		IICSendByte(&MPU_bus,buf[i]);	//发送数据
		if(IICWaitAck(&MPU_bus))		//等待ACK
		{
			IICStop(&MPU_bus);	 
			return 1;		 
		}		
	}    
    IICStop(&MPU_bus);	 
	return 0;	
} 

//IIC写一个字节 
//reg:寄存器地址
//data:数据
//返回值:0,正常
//    其他,错误代码
u8 MPU_Write_Byte(u8 reg,u8 data) 				 
{ 
  IICStart(&MPU_bus); 
	IICSendByte(&MPU_bus, (MPU_ADDR<<1)|0);//发送器件地址+写命令	
	if(IICWaitAck(&MPU_bus))	//等待应答
	{
		IICStop(&MPU_bus);		 
		return 1;		
	}
	IICSendByte(&MPU_bus,reg);	//写寄存器地址
	IICWaitAck(&MPU_bus);		//等待应答 
	IICSendByte(&MPU_bus,data);//发送数据
	if(IICWaitAck(&MPU_bus))	//等待ACK
	{
		IICStop(&MPU_bus);	 
		return 1;		 
	}		 
  IICStop(&MPU_bus);	 
	return 0;
}
//IIC读一个字节 
//reg:寄存器地址 
//返回值:读到的数据
u8 MPU_Read_Byte(u8 reg)
{
	u8 res;
  IICStart(&MPU_bus); 
	IICSendByte(&MPU_bus,(MPU_ADDR<<1)|0);//发送器件地址+写命令	
	IICWaitAck(&MPU_bus);		//等待应答 
  IICSendByte(&MPU_bus,reg);	//写寄存器地址
  IICWaitAck(&MPU_bus);		//等待应答
  IICStart(&MPU_bus);
	IICSendByte(&MPU_bus,(MPU_ADDR<<1)|1);//发送器件地址+读命令	
  IICWaitAck(&MPU_bus);		//等待应答 
	res=IICReceiveByte(&MPU_bus);//读取数据,发送nACK 
	IICSendNotAck(&MPU_bus);
  IICStop(&MPU_bus);			//产生一个停止条件 
	return res;		
}

u8 MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{ 
 	IICStart(&MPU_bus); 
	IICSendByte(&MPU_bus,(addr<<1)|0);
	if(IICWaitAck(&MPU_bus))	
	{
		IICStop(&MPU_bus);		 
		return 1;		
	}
    IICSendByte(&MPU_bus,reg);	
    IICWaitAck(&MPU_bus);		
    IICStart(&MPU_bus);
		IICSendByte(&MPU_bus,(addr<<1)|1);
    IICWaitAck(&MPU_bus);		
		while(len)
		{
			if(len==1)
			{
				*buf=IICReceiveByte(&MPU_bus);
				IICSendNotAck(&MPU_bus);
			}
			else 
			{
				*buf=IICReceiveByte(&MPU_bus);	
				IICSendAck(&MPU_bus);
			}				
			len--;
			buf++; 
		}    
    IICStop(&MPU_bus);
		return 0;	
}

uint8_t MPU_Write_Multi_Byte(uint8_t addr,uint8_t length,uint8_t buff[])
{
	if(IIC_Write_Multi_Byte(&MPU_bus,MPU_ADDR<<1,addr,length,buff))
	{
		return 1;
	}
	return 0;
}

uint8_t MPU_Read_Multi_Byte(uint8_t addr, uint8_t length, uint8_t buff[])
{
	if(IIC_Read_Multi_Byte(&MPU_bus, MPU_ADDR<<1, addr, length, buff))
	{
		return 1;
	}
	return 0;
}

void MPU_Get_Angles(float * roll,float * pitch)
{
	short ax,ay,az;
	MPU_Get_Accelerometer(&ax,&ay,&az);
	*pitch = -atanf(ax/sqrtf(ay*ay+az*az));
	*roll = atanf((float)ay/(float)az);
}

uint8_t MPU_isHorizontal(void)
{
	float roll,pitch;
	MPU_Get_Angles(&roll,&pitch);
	if(roll<=0.35 && roll>=-0.35 && pitch<=0.35 && pitch>=-0.35)
	{return 1;}
	return 0;
}

