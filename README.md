# ADEwatch
一个简单的arduino nano多媒体系统
可以使用按键/旋钮对系统进行控制，左中右的按键分别控制/选择/下,，旋钮可实时调节音乐音量，pic文件夹存放了一些功能示意图以及演示视频，src里存放有代码文件和库文件

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








