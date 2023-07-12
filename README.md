# OV-Watch-V2.3
Smart Watch, MCU: STM32F411CEU6, UI: LVGL, OS:FreeRTOS 

功能增加部分视频链接：
https://www.bilibili.com/video/BV19g4y1N7YR/

# 增加的功能说明
修改的功能包括：

1. 心率部分，硬件增加LED矩阵，增强PPG信号强度
1. 双板改为贴合，不做4层板因为立创不能做盲埋孔
1. 蓝牙改为KT6328A 
1. MPU6050电路更改，V2.2的AUX接地了，导致之前的功耗高了，现在待机功耗几百uA 
1. 删除NFC部分，因为以前的设计NFC会被PCB铺铜以及屏幕铁皮屏蔽
1. 加入游戏（2048，记忆方块，MPU6050相关游戏）

### 功能表如下图所示：

<img src=".\images\功能表.png" alt="功能表" style="zoom:100%;" />

# 新版本实物图

<img src=".\images\实物图.jpg" alt="实物图" style="zoom:100%;" />

<img src=".\images\实物图2.png" alt="实物图2" style="zoom:100%;" />

<img src=".\images\实物图3.png" alt="实物图3" style="zoom:100%;" />

<img src=".\images\心率实物图.png" alt="心率实物图" style="zoom:100%;" />

