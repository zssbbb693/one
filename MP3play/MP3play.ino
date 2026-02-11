#include <SoftwareSerial.h>

#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySerial(10, 11); // RX, TX
DFRobotDFPlayerMini dfPlayer;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  if (!dfPlayer.begin(mySerial)) {
    Serial.println("DFPlayer Mini 未连接，请检查接线！");
    while (true); // 卡住，等待修复
  }

  dfPlayer.volume(30); // 设置音量 0-30
  dfPlayer.play(1);    // 播放第1首歌
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    switch (cmd) {
      case 'p': dfPlayer.play(); break;      // 播放
      case 's': dfPlayer.pause(); break;     // 暂停
      case 'n': dfPlayer.next(); break;       // 下一首
      case 'b': dfPlayer.previous(); break;  // 上一首
      case '+': dfPlayer.volumeUp(); break;   // 音量+
      case '-': dfPlayer.volumeDown(); break; // 音量-
    }
  }
}