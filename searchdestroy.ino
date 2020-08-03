void SearchDestroy(){
  StartGameCount();
  LCD_Cls();
  digitalWrite(REDLED, LOW);
  digitalWrite(GREENLED, LOW);
  lcd.setCursor(0, 2);
  lcd.print("--------------------");
  lcd.setCursor(0, 3);
  lcd.print("  PIAZZA E DISARMA  ");
  minutos = GAMEMINUTES - 1;
  iTime=0;
  PLAYING = false;
  PlayForArm();
}

void PlayForArm(){
  unsigned long timeCalcVar;
  unsigned long aTime;
  if(PLAYING = true){
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
      bool armings = ArmPassword("ARMING BOMB");
      if (armings == true) {
        PlayForDefuse();
      }else{ALARM_OFF();}
    }
    if (digitalRead(SMARTCARD) == HIGH && SMARTCARDACTIVE == true) {
      bool armings = ArmSmartCard("ARMING BOMB");
      if (armings == true) {
        PlayForDefuse();
      }else{ALARM_OFF();}
    }
    if (ARMING == true && PASSWORDACTIVE == false && SMARTCARDACTIVE == false) {
      bool armings = ArmKeyHold("ARMING BOMB");
      if (armings == true) {
        PlayForDefuse();
      }else{ALARM_OFF();}
    }
  }
}

void PlayForDefuse(){
  LCD_Cls();
  digitalWrite(REDLED, HIGH);
  digitalWrite(GREENLED, HIGH);
  int minutos = BOMBMINUTES - 1;
  iTime = millis();
  unsigned long timeCalcVar;
  unsigned long aTime;
  int TonoLong = 50;

  while (1) {
    timeCalcVar = (millis() - iTime) % 1000;
    if (timeCalcVar >= 0 && timeCalcVar <= 60)
    {
      digitalWrite(REDLED, HIGH);
      tone(ToneArming, ToneBip, TonoLong);
      ALARM_ON();
    } else {
      ALARM_OFF();
    }
    if (timeCalcVar >= 180 && timeCalcVar <= 220)
    {
      digitalWrite(REDLED, LOW);
      tone(ToneArming, ToneBip, TonoLong);
    }
    aTime = millis() - iTime;
    timeCalcVar = (millis() - iTime) % 1000;
    if (timeCalcVar >= 245 && timeCalcVar <= 255 && minutos - aTime / 60000 < 2 )tone(ToneArming, ToneBip, TonoLong);
    if (timeCalcVar >= 495 && timeCalcVar <= 510 && minutos - aTime / 60000 < 4 )tone(ToneArming, ToneBip, TonoLong);
    if (timeCalcVar >= 745 && timeCalcVar <= 760 && minutos - aTime / 60000 < 2 )tone(ToneArming, ToneBip, TonoLong);
    if ( minutos - aTime / 60000 == 0 && 59 - ((aTime / 1000) % 60) < 10)TonoLong = 300;
    lcd.setCursor(2, 0);
    lcd.print("LA BOMBA ESPLODE IN");
    lcd.setCursor(5, 1);
    PrintTime(minutos, aTime);
    if (minutos - aTime / 60000 == 0 && 59 - ((aTime / 1000) % 60) == 0)
    {
      EndAttackerWin();
    }
    if (KeyPad.getKey() == 'd' && PASSWORDACTIVE == true && SMARTCARDACTIVE == false) {
      bool disarmings = ArmPassword("DISARMING BOMB");
      if (disarmings == true) {
        EndDefenderWin();
      }else{ALARM_OFF();}
    }
    if (digitalRead(SMARTCARD) == HIGH && SMARTCARDACTIVE == true) {
      bool disarmings = ArmSmartCard("DISARMING BOMB");
      if (disarmings == true) {
        EndDefenderWin();
      }else{ALARM_OFF();}
    }
    if (DEFUSE == true && PASSWORDACTIVE == false && SMARTCARDACTIVE == false) {
      bool disarmings = DefuseKeyHold("DISARMING BOMB");
      if (disarmings == true) {
        EndDefenderWin();
      }else{ALARM_OFF();}
    }
  }
}
