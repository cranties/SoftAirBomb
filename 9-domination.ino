void Domination() {
  StartGame(false);
  unsigned int mintoplay = GAMEMINUTES;
  CountDown("Domination", "Prepare to Play!", 10, false, true);
  unsigned long timetoplay = mintoplay * 60 * 1000;
  unsigned long starttime = millis();
  unsigned long astart = 0;
  unsigned long bstart = 0;
  unsigned long atotal = 0;
  unsigned long btotal = 0;
  unsigned long playtime = millis();
  unsigned long xTime = millis();
  unsigned long timeCalcVar;
  unsigned int winner = 0;
  unsigned int percent = 0;
  String timetowin = "";
  String stringtime = RemainTime(mintoplay, 0);
  ezProgressBar ctf ("Domination", "", "Team A##Team B");
  PLAYING = true;
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_BLACK);
  M5.Lcd.setCursor(30, 70);
  M5.Lcd.print("Time Remain:");
  M5.Lcd.setCursor(50, 180);
  M5.Lcd.print("Domination: No Team");
  while (PLAYING == true) {
    M5.update();
    playtime = millis();
    stringtime = RemainTime(mintoplay, (playtime - starttime));
    M5.Lcd.fillRect(200, 50, 120, 60, 61309);
    M5.Lcd.setCursor(210, 70);
    M5.Lcd.print(stringtime);
    percent = 0;
    ctf.value(percent);
    xTime = millis();
    while (M5.BtnA.isPressed()) {
      M5.update();
      timeCalcVar = (millis() - xTime) % 1000;
      if ( timeCalcVar >= 0 && timeCalcVar <= 50)
      {
        if (ALARMACTIVE) {
          sb.beep(9, ToneAlarm1, 200);
          ALARM_ON();
        }
      }
      if (timeCalcVar >= 470 && timeCalcVar <= 520)
      {
        if (ALARMACTIVE) {
          sb.beep(9, ToneAlarm2, 200);
          ALARM_OFF();
        }
      }
      unsigned long seconds = millis() - xTime;
      percent = (seconds) / (ACTIVATESECONDS * 10);
      ctf.value(percent);
      if (percent >= 100) {
        M5.Lcd.fillRect(180, 150, 120, 60, 61309);
        M5.Lcd.setCursor(50, 180);
        M5.Lcd.print("Domination: TEAM A");
        astart = millis();
        if (bstart > 0) {
          btotal = btotal + (playtime - bstart);
          bstart = 0;
        }
        break;
      }
    }
    while (M5.BtnC.isPressed()) {
      M5.update();
      timeCalcVar = (millis() - xTime) % 1000;
      if ( timeCalcVar >= 0 && timeCalcVar <= 50)
      {
        if (ALARMACTIVE) {
          sb.beep(9, ToneAlarm1, 200);
          ALARM_ON();
        }
      }
      if (timeCalcVar >= 470 && timeCalcVar <= 520)
      {
        if (ALARMACTIVE) {
          sb.beep(9, ToneAlarm2, 200);
          ALARM_OFF();
        }
      }
      unsigned long seconds = millis() - xTime;
      percent = (seconds) / (ACTIVATESECONDS * 10);
      ctf.value(percent);
      if (percent >= 100) {
        M5.Lcd.fillRect(180, 150, 120, 60, 61309);
        M5.Lcd.setCursor(50, 180);
        M5.Lcd.print("Domination: TEAM B");
        bstart = millis();
        if (astart > 0) {
          atotal = atotal + (playtime - astart);
          astart = 0;
        }
        break;
      }
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
  if (atotal > btotal) {
    winner = 1;
  } else {
    winner = 2;
  }
  timetowin = "Team A: " + String(int(atotal/1000)) + "|" + "Team B: " + String(int(btotal/1000));
  if (winner == 1) {
    timetowin = "THE WINNER IS|TEAM A|"+timetowin;
  }
  if (winner == 2) {
    timetowin = "THE WINNER IS|TEAM B|"+timetowin;
  }
  ALARM_OFF();
  ez.msgBox("Domination", timetowin, "OK");
}
