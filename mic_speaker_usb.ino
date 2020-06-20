#include <Audio.h>
//#include <Wire.h>
//#include <SPI.h>
//#include <SD.h>
//#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputUSB            usb_speaker;           //xy=111,266.0000023841858
AudioInputI2S            i2s_mic;           //xy=115,146.00000190734863
//声音放大用
AudioAmplifier           amp1;           //xy=278.00000381469727,239.0000035762787
AudioOutputI2S           i2s_speaker;           //xy=347.00000381469727,288.00000381469727
AudioOutputUSB           usb_mic;           //xy=348,156

AudioConnection          patchCord1(usb_speaker, 0, i2s_speaker, 0);
AudioConnection          patchCord1(i2s_mic, 0, amp1, 0);
AudioConnection          patchCord2(amp1, 0, usb_mic, 0);
// GUItool: end automatically generated code

//实测 teensy3.6可用,其它版本否可以见官方网站
//https://www.pjrc.com/store/index.html
//usb type: Audio
//注意选择好usb线，有的线上传程序有问题，可能是供电能力不够！
//用电: 83ma
//将 teensy通过usb线接入 window或树莓派后会出现新声卡（带麦克风+语音播放卡)
//Teensy Audio
//麦克风设置到最大，音量仍然较小!

//参考资料 Teensy 打造USB纯数字麦克风
//https://zhuanlan.zhihu.com/p/53880083


/*
  用teensy做usb声卡。
  相对于普通的usb声卡。
  1.普通的usb声卡不带数字麦克风.
  2.普通的usb声卡语音输出是低电流，电流不足够直接驱动喇叭.
  
  按如下引脚将数字麦克风接到teensy上就可以支持录音。
  Teensy 3.6 硬件 MSM261S4030H0 或 INMP441 可用
  GND LR
  D23 WS
  D9  CK
  D13 DA
  GND GND
  3.3V 3V


  按如下引脚将声音处理模块接到teensy上就可以直接播放数字声音，直接接喇叭，不需要放大器。
  Teensy 3.6+ 硬件 MAX98357A 可用
  D23 LRC
  D9  RCLK
  D22 DATA_OUT :SPEAKER
  GND GND
  3.3V 3V
*/


void setup() {

  //增加音量 0-32767
  amp1.gain(200);
  
  AudioMemory(80);

}

void loop() {

}
