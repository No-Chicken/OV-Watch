# OV-Watch-V2.3.2
Smart Watch, MCU: STM32F411CEU6, UI: LVGL, OS:FreeRTOS 

V2.3功能增加部分视频链接：
https://www.bilibili.com/video/BV19g4y1N7YR/

V2.2演示视频链接：
https://www.bilibili.com/video/BV1hh4y1J7TS



## 增加的功能说明
修改的功能包括：

1. 心率部分，硬件增加LED矩阵，增强PPG信号强度
1. 双板改为贴合，不做4层板因为立创不能做盲埋孔
1. 蓝牙改为KT6328A 
1. MPU6050电路更改，V2.2的AUX接地了，导致之前的功耗高了，现在待机功耗几百uA 
1. 删除NFC部分，因为以前的设计NFC会被PCB铺铜以及屏幕铁皮屏蔽
1. 加入游戏（2048，记忆方块，MPU6050相关游戏）

### 功能表如下图所示：

<div align=center>
<img src=".\images\功能表.png" alt="功能吧" style="zoom:100%;" />
</div>



## 新版本实物图

<div align=center>
<img src=".\images\实物图.jpg" alt="实物图" style="zoom:100%;" />
</div>

<div align=center>
<img src=".\images\实物图2.png" alt="实物图2" style="zoom:100%;" />
</div>

<div align=center>
<img src=".\images\实物图3.png" alt="实物图3" style="zoom:100%;" />
</div>

<div align=center>
<img src=".\images\心率实物图.png" alt="心率实物图" style="zoom:100%;" />
</div>

<div align=center>
<img src=".\images\front.jpg" alt="front" style="zoom:100%;" />
</div>

<div align=center>
<img src=".\images\back.jpg" alt="back" style="zoom:100%;" />
</div>
