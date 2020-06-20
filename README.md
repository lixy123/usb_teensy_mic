
自做usb数字麦克风, 步骤如下 <br/> 
1.硬件准备<br/>
   A.teensy3.6版本<br/>
   B.MSM261S4030H0 或 INMP441数字麦克风模块<br/>
   C.MAX98357A 模块 (如果不要声音输出，可不接)<br/> <br/>
2. 软件烧录至teensy <br/>
    A.下载安装软件arduino<br/>
    B. 安装 teensy 开发库，<br/>
    C. 打开源码,选择开发板，烧录<br/>

  <br/>
  ########################################################## <br/>
  相对于普通的usb声卡。 <br/> <br/>
  1.普通的usb声卡不带数字麦克风. <br/>
  2.普通的usb声卡语音输出是低电流，电流不足够直接驱动喇叭. <br/>
   <br/>
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
