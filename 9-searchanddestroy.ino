void SearchDestroy() {
  StartGame(true);
  unsigned int mintoplay = GAMEMINUTES;
  CountDown("Search and Destroy", "Prepare to Play!", 10, false, true);
  unsigned long timetoplay = mintoplay * 60 * 1000;
  unsigned long starttime = millis();
  unsigned long playtime = millis();
  unsigned long xTime = millis();
  unsigned long timeCalcVar;
  unsigned int winner = 0;
  unsigned int percent = 0;
  String stringtime = RemainTime(mintoplay, 0);
  ezProgressBar ctf ("Search and Destroy", "", "ARM");
  PLAYING = true;
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_BLACK);
  M5.Lcd.setCursor(30,70);
  M5.Lcd.print("Time Remain:");
  while (PLAYING == true) {
    M5.update();
    playtime = millis();
    stringtime = RemainTime(mintoplay, (playtime - starttime));
    M5.Lcd.fillRect(200, 50, 120, 60, 61309);
    M5.Lcd.setCursor(210,70);
    M5.Lcd.print(stringtime);
    percent = 0;
    ctf.value(percent);
    winner = CheckBBtn(ctf, false, 0);
    if (playtime >= (starttime + timetoplay)) {
      PLAYING = false;
      winner = 1;
    }
    delay(500);
  }
  ezProgressBar sad ("Search and Destroy", "", "DEFUSE");
  PLAYING = true;
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_BLACK);
  M5.Lcd.setCursor(30,70);
  M5.Lcd.print("Time Remain:");
  while (PLAYING == true) {
    M5.update();
    playtime = millis();
    stringtime = RemainTime(mintoplay, (playtime - starttime));
    M5.Lcd.fillRect(200, 50, 120, 60, 61309);
    M5.Lcd.setCursor(210,70);
    M5.Lcd.print(stringtime);
    percent = 0;
    sad.value(percent);
    winner = CheckBBtn(sad, false, 1);
    if (playtime >= (starttime + timetoplay)) {
      PLAYING = false;
      winner = 0;
    }
    delay(500);
  }
  ALARM_ON();
  while (M5.BtnB.isPressed()) {
    M5.update();
    delay(500);
  }
  String win = "THE WINNER IS|TERRORIST|BOMB DETONATED";
  if (winner == 1) {
    win = "THE WINNER IS|DEFENDER|BOMB DEFUSED";
  }
  ALARM_OFF();
  ez.msgBox("Search and Destroy", win, "OK");
}
