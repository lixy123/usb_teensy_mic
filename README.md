
说明: <br/> 
    树莓派的语音硬件很差劲。没有内置MIC,声音输出需要耳机，电流太小，不能驱动喇叭. <br/> 
    目前在树莓派上如果想要有mic和喇叭大音量功能有如下方式 <br/> 
    1.USB声卡，20-50块钱左右，好处是便宜，不需要安装驱动，缺点是质量有好有坏，需要外接模拟麦克风, 外接声音放大器, 外接附件太多，总体效果一般. <br/> 
    2.Respeaker 2-Mics Pi HAT 90块钱左右，好处是板上有数字麦克风，可以接喇叭，声音效果不错。 缺点是声音驱动比较难安装，每当升级操作系统就得重装一次，有时还装不上. 另一缺点是占用了40个引脚。 <br/> 
    3. 这里有个方法可以驱动喇叭输出声音,如果只需要声音输出倒是很方便，只需要连接树莓派的5根引脚， https://raspberrypi.stackexchange.com/questions/76188/how-to-make-pcm5102-dac-work-on-raspberry-pi-zerow <br/>
    
    
如果既想不占用引脚，又不想安装驱动麻烦，还要声音功能质量好，可以采用如下方式。 主要的原理是通过teensy模拟声卡驱动。总体价格大约160-200元左右，有些贵. 如果你Respeaker 2-Mics Pi HAT用着很满意，就不用往下看了.<br/> 
     

自做usb数字麦克风, 步骤如下 <br/> 
1.硬件准备<br/>
   A.teensy3.6版本 (体积更好，更便宜的3.2版本也可用)<br/>
   B.MSM261S4030H0 或 INMP441数字麦克风模块<br/>
   C.MAX98357A 模块 (如果不要声音输出，可不接)<br/> <br/>
2. 软件烧录至teensy <br/>
    A.下载安装软件arduino<br/>
    B. 安装 teensy 开发库，<br/>
    C. 打开源码,选择开发板，烧录<br/>
<br/>
<p>
效果图如下，查了资料，用teensy 3.2也可以，体积是如图的一半<br/>
<img src= 'https://github.com/lixy123/usb_teensy_mic/blob/master/IMG_usb_mic.jpg?raw=true' />
</p>

  <br/>
  ########################################################## <br/>
  相对于普通的usb声卡。 <br/> 
  1.普通的usb声卡不带数字麦克风. <br/>
  2.普通的usb声卡语音输出是低电流，电流不足够直接驱动喇叭. <br/>
  ########################################################## <br/>
  按如下引脚将数字麦克风接到teensy上就可以支持录音。 <br/>
  Teensy 3.6 硬件 MSM261S4030H0 或 INMP441 可用 <br/>
  GND LR <br/>
  D23 WS <br/>
  D9  CK <br/>
  D13 DA <br/>
  GND GND <br/>
  3.3V 3V <br/>
  按如下引脚将声音处理模块接到teensy上就可以直接播放数字声音，直接接喇叭，不需要放大器。 <br/>
  Teensy 3.6+ 硬件 MAX98357A 可用 <br/>
  D23 LRC <br/>
  D9  RCLK <br/>
  D22 DATA_OUT :SPEAKER <br/>
  GND GND <br/>
  3.3V 3V <br/>
  ########################################################## <br/>
 <br/>
参考资料:<br/>
    1. Teensy 打造USB纯数字麦克风 (注：此处源码没有进行声音放大，录制的声音会很小)<br/>
    https://zhuanlan.zhihu.com/p/53880083<br/>
    2. teensy 官网<br/>
    https://www.pjrc.com/store/index.html<br/>
    3.arduino 论坛<br/>
    https://www.arduino.cn/<br/>
