bool CheckConfig() {
  EEPROM.readBlock(configAdress, TestData);
  return (TestData.version == CONFIG_VERSION);
}

void LoadConfig() {
  EEPROM.readBlock(configAdress, ConfigData);
  GAMEHOURS = ConfigData.GH;
  GAMEMINUTES = ConfigData.GM;
  BOMBMINUTES = ConfigData.GB;
  ACTIVATESECONDS = ConfigData.GA;
  CAPTURESECONDS = ConfigData.GC;
  CATCHPOINTMINUTES = ConfigData.GP;
  SQLIFES = ConfigData.SQ;
  ToneAlarm1 = ConfigData.T1;
  ToneAlarm2 = ConfigData.T2;
  ToneArming = ConfigData.TA;
  ToneError = ConfigData.TE;
  ToneBip = ConfigData.TB;
}

void SaveConfig() {
  EEPROM.writeBlock(configAdress, ConfigData);
}

void SetConfig() {
  ConfigData = (ConfigStruct) {
    CONFIG_VERSION,
    GAMEHOURS, GAMEMINUTES, ACTIVATESECONDS, CAPTURESECONDS, CATCHPOINTMINUTES, SQLIFES,
    ToneAlarm1, ToneAlarm2, ToneArming, ToneError, ToneBip
  };
}

