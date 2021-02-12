bool CheckConfig() {
  unsigned int testver;
  Config.begin("SAB", true);
  testver = Config.getUInt("ver", 0);
  Config.end();
  if (testver == CONFIG_VERSION) {
    return true;
  } else {
    ez.msgBox("SoftAirBomb", "Error Load from EEPROM|Code " + String(testver) + " not " + String(CONFIG_VERSION), "Abort");
    SaveConfig();
    return false;
  }
}

void LoadConfig() {
  Config.begin("SAB", true);
  GAMEMINUTES = Config.getUInt("gm", GAMEMINUTES);
  ACTIVATESECONDS = Config.getUInt("ga", ACTIVATESECONDS);
  CAPTURESECONDS = Config.getUInt("gc", CAPTURESECONDS);
  CATCHPOINTMINUTES = Config.getUInt("gp", CATCHPOINTMINUTES);
  SQLIFES = Config.getUInt("sq", SQLIFES);
  ToneAlarm1 = Config.getUInt("t1", ToneAlarm1);
  ToneAlarm2 = Config.getUInt("t2", ToneAlarm2);
  ToneArming = Config.getUInt("ta", ToneArming);
  ToneError = Config.getUInt("te", ToneError);
  ToneBip = Config.getUInt("tb", ToneBip);
  ALARMACTIVE = Config.getBool("aa", ALARMACTIVE);
  SMARTCARDACTIVE = Config.getBool("sc", SMARTCARDACTIVE);
  PASSWORDACTIVE = Config.getBool("pa", PASSWORDACTIVE);
  IO_ALARM = Config.getUShort("ia", IO_ALARM);
  IO_OTHER = Config.getUShort("io", IO_OTHER);
  Config.end();
}

void SaveConfig() {
  Config.begin("SAB", false);
  Config.putUInt("ver", CONFIG_VERSION);
  Config.putUInt("gm", GAMEMINUTES);
  Config.putUInt("ga", ACTIVATESECONDS);
  Config.putUInt("gc", CAPTURESECONDS);
  Config.putUInt("gp", CATCHPOINTMINUTES);
  Config.putUInt("sq", SQLIFES);
  Config.putUInt("t1", ToneAlarm1);
  Config.putUInt("t2", ToneAlarm2);
  Config.putUInt("ta", ToneArming);
  Config.putUInt("te", ToneError);
  Config.putUInt("tb", ToneBip);
  Config.putBool("aa", ALARMACTIVE);
  Config.putBool("sc", SMARTCARDACTIVE);
  Config.putBool("pa", PASSWORDACTIVE);
  Config.putUShort("ia", IO_ALARM);
  Config.putUShort("io", IO_OTHER);
  Config.end();
}
