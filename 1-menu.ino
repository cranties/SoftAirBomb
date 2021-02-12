void FmenuTop() {
  if (ALARMACTIVE) {
    sb.beep(5, ToneBip, 90);
  }
  ezMenu menuTop("SoftAirBomb");
  menuTop.txtSmall();
  menuTop.addItem("Search and Destroy", SearchDestroy);
  menuTop.addItem("Sabotage", Sabotage);
  menuTop.addItem("Domination", Domination);
  menuTop.addItem("Capture The Flag", CaptureTheFlag);
  menuTop.addItem("Chrono Respawn", Chronos);
  menuTop.addItem("How To Play Help", FmenuHelp);
  menuTop.addItem("Software Configuration", FmenuSoftware);
  menuTop.addItem("Hardware Configuration", FmenuConfig);
  menuTop.run();
}

void FmenuHelp() {
  if (ALARMACTIVE) {
    sb.beep(5, ToneBip, 90);
  }
  ezMenu menuHelp("SoftAirBomb");
  menuHelp.txtSmall();
  menuHelp.addItem("Search and Destroy", HelpSearchDestroy);
  menuHelp.addItem("Sabotage", HelpSabotage);
  menuHelp.addItem("Domination", HelpDomination);
  menuHelp.addItem("Capture The Flag", HelpCaptureTheFlag);
  menuHelp.addItem("Chrono Respawn", HelpChronos);
  menuHelp.addItem("SoftAirBomb Info", HelpSAP);
  menuHelp.addItem("Back");
  menuHelp.run();
}

void FmenuSoftware() {
  if (ALARMACTIVE) {
    sb.beep(5, ToneBip, 90);
  }
  ezMenu menuSoftware("Software Configuration");
  menuSoftware.txtSmall();
  menuSoftware.addItem("Game Config", FmenuGame);
  menuSoftware.addItem("Save Configuration", SaveConfigEEprom);
  menuSoftware.addItem("Load Configuration", LoadConfigEEprom);
  menuSoftware.addItem("Reset Configuration", ResetConfigEEprom);
  menuSoftware.addItem("Back");
  menuSoftware.run();
}

void FmenuGame() {
  if (ALARMACTIVE) {
    sb.beep(5, ToneBip, 90);
  }
  ezMenu menuGame("SoftAirBomb");
  menuGame.txtSmall();
  menuGame.addItem("Gameplay Configuration", FmenuGamePlay);
  menuGame.addItem("Optional Configuration", FmenuOptional);
  menuGame.addItem("I/O Configuration", FmenuIO);
  menuGame.addItem("Sound Frequency", FmenuFrequency);
  menuGame.addItem("Test Configured Devices", FmenuTest);
  menuGame.addItem("Back");
  menuGame.run();
}

void FmenuTest() {
  if (ALARMACTIVE) {
    sb.beep(5, ToneBip, 90);
  }
  M5.Lcd.fillScreen(WHITE);
  delay(50);
  M5.Lcd.fillScreen(RED);
  delay(50);
  M5.Lcd.fillScreen(GREEN);
  delay(50);
  M5.Lcd.fillScreen(BLUE);
  delay(50);
  M5.Lcd.fillScreen(BLACK);
  delay(50);
  PressButton("SoftAirBomb", "TEST LCD");
  sb.beep(5, ToneBip, 90);
  delay(10);
  sb.beep(5, ToneAlarm1, 90);
  delay(10);
  sb.beep(5, ToneAlarm2, 90);
  delay(10);
  sb.beep(5, ToneArming, 90);
  delay(10);
  sb.beep(5, ToneError, 90);
  delay(10);
  PressButton("SoftAirBomb", "TEST BEEPER");
  digitalWrite(IO_ALARM, HIGH);
  PressButton("SoftAirBomb", "TEST IO ALARM");
  digitalWrite(IO_ALARM, LOW);
}

void FmenuOptional() {
  ALARMACTIVE = AskYesNo("SoftAirBomb", "Activate Internal Beeper?");
  SMARTCARDACTIVE = AskYesNo("SoftAirBomb", "Use RfID Reader for Capture, Arm, Defuse, etc?");
  PASSWORDACTIVE = AskYesNo("SoftAirBomb", "Use a Numeric Password for Capture, Arm, Defuse, etc?");
  IOALARMACTIVE = AskYesNo("SoftAirBomb", "Activate External IO as Beeper?");
}

void FmenuIO() {
  String inputdata;
  inputdata = AskNumber("SoftAirBomb", "Set IO Pin for Alarm", String(IO_ALARM));
  IO_ALARM = inputdata.toInt();
  inputdata = AskNumber("SoftAirBomb", "Set IO Pin for Other", String(IO_OTHER));
  IO_OTHER = inputdata.toInt();
}

void FmenuFrequency() {
  String inputdata;
  inputdata = AskNumber("SoftAirBomb", "Frequency Tone of Alarm 1", String(ToneAlarm1));
  ToneAlarm1 = inputdata.toInt();
  inputdata = AskNumber("SoftAirBomb", "Frequency Tone of Alarm 2", String(ToneAlarm2));
  ToneAlarm2 = inputdata.toInt();
  inputdata = AskNumber("SoftAirBomb", "Frequency Tone of Arming", String(ToneArming));
  ToneArming = inputdata.toInt();
  inputdata = AskNumber("SoftAirBomb", "Frequency Tone of Error", String(ToneError));
  ToneError = inputdata.toInt();
  inputdata = AskNumber("SoftAirBomb", "Frequency Tone of Bip", String(ToneBip));
  ToneBip = inputdata.toInt();
}

void FmenuGamePlay() {
  String inputdata;
  inputdata = AskNumber("SoftAirBomb", "Game Play Time (min)", String(GAMEMINUTES));
  GAMEMINUTES = inputdata.toInt();
  inputdata = AskNumber("SoftAirBomb", "Arm and Defuse Bomb (sec)", String(ACTIVATESECONDS));
  ACTIVATESECONDS = inputdata.toInt();
  inputdata = AskNumber("SoftAirBomb", "Capture Point and Flag (sec)", String(CAPTURESECONDS));
  CAPTURESECONDS = inputdata.toInt();
  inputdata = AskNumber("SoftAirBomb", "Number of Respawn Life (num)", String(SQLIFES));
  SQLIFES = inputdata.toInt();
}

void FmenuConfig() {
  if (ALARMACTIVE) {
    sb.beep(5, ToneBip, 90);
  }
  ezMenu menuConfig("Hardware Configuration");
  menuConfig.txtSmall();
  menuConfig.addItem("Hardware Info", sysInfoPage1);
  menuConfig.addItem("SD & Ram Info", sysInfoPage2);
  menuConfig.addItem("Battery Settings", ez.battery.menu);
  menuConfig.addItem("BackLight Settings", ez.backlight.menu);
  menuConfig.addItem("Back");
  menuConfig.run();
}

void sysInfoPage1() {
  if (ALARMACTIVE) {
    sb.beep(5, ToneBip, 90);
  }
  const byte tab = 120;
  ez.screen.clear();
  ez.header.show("Hardware Info");
  ez.buttons.show("#Back#");
  ez.canvas.font(&FreeSans9pt7b);
  ez.canvas.lmargin(10);
  ez.canvas.println("");
  ez.canvas.print("CPU freq:");  ez.canvas.x(tab); ez.canvas.println(String(ESP.getCpuFreqMHz()) + " MHz");
  ez.canvas.print("CPU cores:");  ez.canvas.x(tab); ez.canvas.println("2");    //   :)
  ez.canvas.print("Chip rev.:");  ez.canvas.x(tab); ez.canvas.println(String(ESP.getChipRevision()));
  ez.canvas.print("Flash speed:");  ez.canvas.x(tab); ez.canvas.println(String(ESP.getFlashChipSpeed() / 1000000) + " MHz");
  ez.canvas.print("Flash size:");  ez.canvas.x(tab); ez.canvas.println(String(ESP.getFlashChipSize() / 1000000) + " MB");
  ez.canvas.print("ESP SDK:");  ez.canvas.x(tab); ez.canvas.println(String(ESP.getSdkVersion()));
  ez.canvas.print("M5ez:");  ez.canvas.x(tab); ez.canvas.println(String(ez.version()));
  ez.buttons.wait("Back");
}

void sysInfoPage2() {
  if (ALARMACTIVE) {
    sb.beep(5, ToneBip, 90);
  }
  const String SD_Type[5] = {"NONE", "MMC", "SD", "SDHC", "UNKNOWN"};
  const byte tab = 140;
  ez.screen.clear();
  ez.header.show("SD & Ram Info)");
  ez.buttons.show("#Back#");
  ez.canvas.font(&FreeSans9pt7b);
  ez.canvas.lmargin(10);
  ez.canvas.println("");
  ez.canvas.print("Free RAM:");  ez.canvas.x(tab);  ez.canvas.println(String((long)ESP.getFreeHeap()) + " bytes");
  ez.canvas.print("Min. free seen:");  ez.canvas.x(tab); ez.canvas.println(String((long)esp_get_minimum_free_heap_size()) + " bytes");
  const int sd_type = SD.cardType();
  SPIFFS.begin();
  ez.canvas.print("SPIFFS size:"); ez.canvas.x(tab); ez.canvas.println(String((long)SPIFFS.totalBytes()) + " bytes");
  ez.canvas.print("SPIFFS used:"); ez.canvas.x(tab); ez.canvas.println(String((long)SPIFFS.usedBytes()) + " bytes");
  ez.canvas.print("SD type:"); ez.canvas.x(tab); ez.canvas.println(SD_Type[sd_type]);
  if (sd_type != 0) {
    ez.canvas.print("SD size:"); ez.canvas.x(tab); ez.canvas.println(String((long)SD.cardSize()  / 1000000) + " MB");
    ez.canvas.print("SD used:"); ez.canvas.x(tab); ez.canvas.println(String((long)SD.usedBytes()  / 1000000) + " MB");
  }
  ez.buttons.wait("Back");
}
