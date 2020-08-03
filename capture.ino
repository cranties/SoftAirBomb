void Capture() {
  StartGameCount();
  LCD_Cls();
  digitalWrite(REDLED, LOW);
  digitalWrite(GREENLED, LOW);
  lcd.setCursor(0, 2);
  lcd.print("--------------------");
  lcd.setCursor(0, 3);
  lcd.print("CATTURA LA BANDIERA ");
  minutos = GAMEMINUTES - 1;
  iTime=0;
  PLAYING = false;
  PlayForCapture();
}

void PlayForCapture() {
  unsigned long timeCalcVar;
  unsigned long aTime;
  if (PLAYING = true) {
    iTime = millis();
  }
  while (1) {
    timeCalcVar = (millis() - iTime) % 1000;
    if (timeCalcVar >= 0 && timeCalcVar <= 50)
    {
      digitalWrite(GREENLED, HIGH);
    }
    if (timeCalcVar >= 90 && timeCalcVar <= 130)
    {
      digitalWrite(GREENLED, LOW);
    }
    lcd.setCursor(0, 0);
    lcd.print("   TEMPO DI GIOCO   ");
    aTime = millis() - iTime;
    lcd.setCursor(5, 1);
    PrintTime(minutos, aTime);
    if (minutos - aTime / 60000 == 0 && 59 - ((aTime / 1000) % 60) == 0)
    {
      EndDefenderWin();
    }
    if (KeyPad.getKey() == 'd' && PASSWORDACTIVE == true && SMARTCARDACTIVE == false) {
      bool armings = ArmPassword("- - - CATTURA - - -");
      if (armings == true) {
        EndAttackerWin();
      }else{ALARM_OFF();}
    }
    if (digitalRead(SMARTCARD) == HIGH && SMARTCARDACTIVE == true) {
      bool armings = ArmSmartCard("- - - CATTURA - - -");
      if (armings == true) {
        EndAttackerWin();
      }else{ALARM_OFF();}
    }
    if (ARMING == true && PASSWORDACTIVE == false && SMARTCARDACTIVE == false) {
      bool armings = ArmKeyHold("- - - CATTURA - - -");
      if (armings == true) {
        EndAttackerWin();
      }else{ALARM_OFF();}
    }
  }
}
