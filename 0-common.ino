String RemainTime(unsigned long minutos, unsigned long millisplay) {
  unsigned long sectoplay = ((minutos * 60) - (millisplay / 1000));
  char str[6];
  int m = int(sectoplay / 60);
  int s = int(sectoplay % 60);
  sprintf(str, "%02d:%02d", m, s);
  return str;
}

bool ButtonAPressed(ezProgressBar &bar, unsigned int timetotake) {
  unsigned long startpressed = millis();
  unsigned long playpressed = 0;
  unsigned int percent = 0;
  bool ret = false;
  while (M5.BtnA.isPressed()) {
    M5.update();
    playpressed = (millis() - startpressed) % 1000;
    if ( playpressed >= 0 && playpressed <= 50) {
      if (ALARMACTIVE) {
        sb.beep(9, ToneAlarm1, 200);
        ALARM_ON();
      }
    }
    if (playpressed >= 470 && playpressed <= 520) {
      if (ALARMACTIVE) {
        sb.beep(9, ToneAlarm2, 200);
        ALARM_OFF();
      }
    }
    unsigned long seconds = millis() - startpressed;
    percent = (seconds) / (timetotake * 10);
    bar.value(percent);
    if (percent >= 100) {
      ret = true;
      break;
    }
  }
  return ret;
}

bool ButtonBPressed(ezProgressBar &bar, unsigned int timetotake) {
  unsigned long startpressed = millis();
  unsigned long playpressed = 0;
  unsigned int percent = 0;
  bool ret = false;
  while (M5.BtnB.isPressed()) {
    M5.update();
    playpressed = (millis() - startpressed) % 1000;
    if ( playpressed >= 0 && playpressed <= 50) {
      if (ALARMACTIVE) {
        sb.beep(9, ToneAlarm1, 200);
        ALARM_ON();
      }
    }
    if (playpressed >= 470 && playpressed <= 520) {
      if (ALARMACTIVE) {
        sb.beep(9, ToneAlarm2, 200);
        ALARM_OFF();
      }
    }
    unsigned long seconds = millis() - startpressed;
    percent = (seconds) / (timetotake * 10);
    bar.value(percent);
    if (percent >= 100) {
      ret = true;
      break;
    }
  }
  return ret;
}

bool ButtonCPressed(ezProgressBar &bar, unsigned int timetotake) {
  unsigned long startpressed = millis();
  unsigned long playpressed = 0;
  unsigned int percent = 0;
  bool ret = false;
  while (M5.BtnC.isPressed()) {
    M5.update();
    playpressed = (millis() - startpressed) % 1000;
    if ( playpressed >= 0 && playpressed <= 50) {
      if (ALARMACTIVE) {
        sb.beep(9, ToneAlarm1, 200);
        ALARM_ON();
      }
    }
    if (playpressed >= 470 && playpressed <= 520) {
      if (ALARMACTIVE) {
        sb.beep(9, ToneAlarm2, 200);
        ALARM_OFF();
      }
    }
    unsigned long seconds = millis() - startpressed;
    percent = (seconds) / (timetotake * 10);
    bar.value(percent);
    if (percent >= 100) {
      ret = true;
      break;
    }
  }
  return ret;
}
