# ADEwatch
![屏幕截图 2023-09-05 123638](https://github.com/Emokable/ADEwatch/assets/93334525/feebadfb-d54d-46c5-ada7-19d8a1dd499d)

根据华东师范大学《创客实践》课程期末考查方案相关要求，ADEwatch是以Arduino Nano 3开发板为核心实现的智能软硬件物联网系统，本项目为本人作业上传。

ADEwatch名称取自Arduino Nano核心板,Dfplayer mp3模块,Esp8266 wifi模块的首字缩写,watch取自项目类型,即多媒体表盘.

本项目共包含三个组成部分：ADEwatch为主体硬件，ADEwatch-Core为arduino上运行的系统程序,ADEwatch-ESP是ESP-12F wifi模块的运行代码,供电可选用USB Type C,micro USB或者电池组接入面包板电源导轨.
主体功能和拓展配件均运行于arduino nano板上, esp-12F仅承担配网功能,并从互联网发送和接受数据并转发给nano板.

用户可以使用按键/旋钮对系统进行控制，左中右的按键分别控制/选择/下,，旋钮可实时调节音乐音量，pic文件夹存放了一些功能示意图以及演示视频，src里存放有代码文件和使用到的其他开源库文件

使用器材：

Arduino Nano 3     			--1 

Esp-12F	     	  	    	--1 

Oled128*64 ssd1306 i2c  --1

DFplayer mini				    --1

Micro SDcard			    	--1

Loudspeaker			      	--1 

Breadboard half-size		--3

Button	switch				  --3 

Potentiometer				    --1 

导线若干

连线方式如下图：

![adewatch模拟连线](https://github.com/Emokable/ADEwatch/assets/93334525/943ff8a8-b86f-4993-9ee6-cc8a4258337d)

功能包括：
![image](https://github.com/Emokable/ADEwatch/assets/93334525/7d5ccbbf-4541-48e4-9c87-d4270aa034cb)

S/P:音乐播放/暂停
 
Next:歌曲下一首
 
Pre:歌曲上一首
 
Time:时钟功能
 
Wea:天气温度显示
 
Ref:刷新天气信息
 
Game:按键跳跃小游戏(Jump game)
 
Ver:开发版本号,开发日期,作者显示

esp模块上实现的功能包括：wifimanager配网，心知天气api获取，ntp时间获取，阿里云mqtt上传

项目流程图如下:

![运行流程图](https://github.com/Emokable/ADEwatch/assets/93334525/f00cb495-7a1a-4878-b318-271cfcd68010)








