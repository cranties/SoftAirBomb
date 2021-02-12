void SaveConfigEEprom() {
  SaveConfig();
  ez.msgBox("SoftAirBomb", "Configuration Saved", "Back");
}

void ResetConfigEEprom() {
  if (AskYesNo("SoftAirBomb", "Want to Reset Configuration Data to Default?")) {
    ToneAlarm1 = 700;
    ToneAlarm2 = 2600;
    ToneArming = 1330;
    ToneError = 100;
    ToneBip = 2400;
    GAMEMINUTES = 15;
    ACTIVATESECONDS = 10;
    CAPTURESECONDS = 10;
    CATCHPOINTMINUTES = 3;
    SQLIFES = 10;
    ALARMACTIVE = false;
    SMARTCARDACTIVE = false;
    PASSWORDACTIVE = false;
    IOALARMACTIVE = false;
    IO_ALARM = 21;
    IO_OTHER = 22;
    SaveConfig();
    ez.msgBox("SoftAirBomb", "Configuration Reset", "Back");
  }
}

void LoadConfigEEprom() {
  if (CheckConfig()) {
    LoadConfig();
    ez.msgBox("SoftAirBomb", "Configuration Loaded", "Back");
  } else {
    ez.msgBox("SoftAirBomb", "No Configuration Found", "Back");
  }
}

void StartGame(bool askpwd) {
  ez.msgBox("SoftAirBomb", "Press START", "START");
  if (askpwd) {
    if (PASSWORDACTIVE) {
      PASSWORD = AskNumber("SoftAirBomb", "Enter Password PIN", PASSWORD);
    }
  }
}

bool CheckPassword() {
  String PWD = "";
  PWD = AskNumber("SoftAirBomb", "Enter Password PIN", PWD);
  if (PWD == PASSWORD) {
    return true;
  } else {
    return false;
  }
}

unsigned int CheckBBtn(ezProgressBar &barz, bool ply, unsigned int win) {
  bool btnpressed = false;
  unsigned int ret = 0;
  if (PASSWORDACTIVE) {
    btnpressed = false;
    while (M5.BtnB.isPressed()) {
      M5.update();
      btnpressed = true;
      delay(500);
    }
    if (btnpressed) {
      if (CheckPassword()) {
        PLAYING = ply;
        ret = win;
      }
    }
  } else {
    if (ButtonBPressed(barz, CAPTURESECONDS)) {
      PLAYING = ply;
      ret = win;
    }
  }
  return ret;
}

void ALARM_ON() {
  if (IOALARMACTIVE) {
    digitalWrite(IO_ALARM, HIGH);
  }
}

void ALARM_OFF() {
  if (IOALARMACTIVE) {
    digitalWrite(IO_ALARM, LOW);
  }
}
