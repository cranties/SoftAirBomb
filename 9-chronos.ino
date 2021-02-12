void Chronos() {
  StartGame(false);
  unsigned int mintoplay = GAMEMINUTES;
  CountDown("Chrono Respawn", "Prepare to Play!", 10, false, true);
  unsigned long timetoplay = mintoplay * 60 * 1000;
  unsigned long timeforlife = timetoplay / SQLIFES;
  unsigned long starttime = millis();
  unsigned long playtime = millis();
  unsigned int respawn = 1;
  unsigned int winner = 0;
  unsigned int percent = 0;
  unsigned int talive = SQLIFES;
  unsigned int tblive = SQLIFES;
  bool btapressed = false;
  bool btcpressed = false;
  String stringtime = RemainTime(mintoplay, 0);
  ezProgressBar ctf ("Chrono Respawn", "", "Team A##Team B");
  PLAYING = true;
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_BLACK);
  M5.Lcd.setCursor(30, 70);
  M5.Lcd.print("Time Remain:");
  M5.Lcd.setCursor(30, 180);
  M5.Lcd.print("Team A: " + String(talive) + " - Team B: " + String(tblive));
  while (PLAYING == true) {
    M5.update();
    playtime = millis();
    stringtime = RemainTime(mintoplay, (playtime - starttime));
    M5.Lcd.fillRect(200, 50, 120, 60, 61309);
    M5.Lcd.setCursor(210, 70);
    M5.Lcd.print(stringtime);
    percent = (playtime * 100) / (playtime + (timeforlife * respawn));
    if (percent > 100) {
      percent = 100;
      respawn = respawn + 1;
      sb.beep(9, ToneArming, 1000);
    }
    ctf.value(percent);
    btapressed = false;
    btcpressed = false;
    while (M5.BtnA.isPressed()) {
      M5.update();
      btapressed = true;
      delay(100);
    }
    if (btapressed) {
      if (talive > 0) {
        talive = talive - 1;
        sb.beep(9, ToneBip, 90);
      } else {
        talive = 0;
        sb.beep(9, ToneError, 1500);
      }
      M5.Lcd.fillRect(30, 150, 280, 60, 61309);
      M5.Lcd.setCursor(30, 180);
      M5.Lcd.print("Team A: " + String(talive) + " - Team B: " + String(tblive));
    }
    while (M5.BtnC.isPressed()) {
      M5.update();
      btcpressed = true;
      delay(100);
    }
    if (btcpressed) {
      if (tblive > 0) {
        tblive = tblive - 1;
        sb.beep(9, ToneBip, 90);
      } else {
        tblive = 0;
        sb.beep(9, ToneError, 1500);
      }
      M5.Lcd.fillRect(30, 150, 280, 60, 61309);
      M5.Lcd.setCursor(30, 180);
      M5.Lcd.print("Team A: " + String(talive) + " - Team B: " + String(tblive));
    }
    if (playtime >= (starttime + timetoplay)) {
      PLAYING = false;
    }
    delay(500);
  }
  ALARM_ON();
  while (M5.BtnB.isPressed()) {
    M5.update();
    delay(500);
  }
  String win = "USED LIFES:|Team A: " + String(int(SQLIFES - talive)) + "|Team B: " + String(int(SQLIFES - tblive));
  ALARM_OFF();
  ez.msgBox("Chrono Respawn", win, "OK");
}
