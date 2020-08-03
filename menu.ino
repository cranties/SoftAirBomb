void MenuMain() {
  digitalWrite(GREENLED, LOW);
  digitalWrite(REDLED, LOW);
  digitalWrite(ALARM, LOW);
  LCD_Cls();
  int i = 0;
  int j = 100;
  int MaxMenu = 5;      // NUMBER OF VOICES ON MAIN MENU (-1)
  char var;
  delay(100);
  lcd.setCursor(0, 2);
  lcd.print(F("- MENU  PRINCIPALE -"));
  lcd.setCursor(0, 3);
  lcd.print(F("D=SELEZIONA - C=INFO"));
  while (1) {
    GAMETYPE = i;
    var = KeyPad.getKey();
    if (j != i) {
      tone(TonePin, ToneBip, 30);
      LCD_Cls();
      if(i==0) lcd.print(F("Piazza e Disarma   "));
      if(i==1) lcd.print(F("Sabotaggio         "));
      if(i==2) lcd.print(F("Dominazione        "));
      if(i==3) lcd.print(F("Cattura Bandiera   "));
      if(i==4) lcd.print(F("Cronometro Rientri "));
      if(i==5) lcd.print(F("Configurazione     "));
      checkArrows(i, MaxMenu);
      delay(250);
      j = i;
    }
    delay(50);
    if (var == 'a' && i > 0) {
      i--;
    }
    if (var == 'b' && i < MaxMenu) {
      i++;
    }
    if (var == 'c') {
      Help();
    }
    if (var == 'd') {
      tone(TonePin, ToneBip, 30);
      LCD_Cls();
      switch (i) {
        case 0:
          GAMETYPE = 1;
          GameConfig();
          SearchDestroy();
          break;
        case 1:
          GAMETYPE = 2;
          GameConfig();
          Sabotage();
          break;
        case 2:
          GAMETYPE = 3;
          GameConfig();
          Domination();
          break;
        case 3:
          GAMETYPE = 4;
          GameConfig();
          Capture();
          break;
        case 4:
          GAMETYPE = 5;
          GameConfig();
          Chrono();
          break;
        case 5:
          MenuConfig();
          break;
      }
    }
  }
}

void MenuConfig() {
  LCD_Cls();
  int i = 0;
  int j = 100;
  int MaxMenu = 6;      // NUMBER OF VOICES ON MAIN MENU -1
  char var;
  bool answer;
  delay(100);
  lcd.setCursor(0, 2);
  lcd.print(F("-  CONFIGURAZIONE  -"));
  lcd.setCursor(0, 3);
  lcd.print(F("D=SELEZIONA - C=MENU"));
  while (1) {
    var = KeyPad.getKey();
    if (j != i) {
      tone(TonePin, ToneBip, 30);
      LCD_Cls();
      if(i==0) lcd.print(F("Configura Gioco    "));
      if(i==1) lcd.print(F("Configura Audio    "));
      if(i==2) lcd.print(F("Test Allarme       "));
      if(i==3) lcd.print(F("Test Audio         "));
      if(i==4) lcd.print(F("Test Led           "));
      if(i==5) lcd.print(F("Salva Impostazioni "));
      if(i==6) lcd.print(F("Carica Impostazioni"));
      checkArrows(i, MaxMenu);
      delay(250);
      j = i;
    }
    if (var == 'a' && i > 0) {
      i--;
    }
    if (var == 'b' && i < MaxMenu) {
      i++;
    }
    if (var == 'c') {
      tone(TonePin, ToneBip, 30);
      LCD_Cls;
      MenuMain();
    }
    if (var == 'd') {
      tone(TonePin, ToneBip, 30);
      LCD_Cls();
      switch (i) {
        case 0:
          ConfigGame();
          j = 100;
          break;
        case 1:
          ConfigAudio();
          j = 100;
          break;
        case 2:
          TestAlarm();
          j = 100;
          break;
        case 3:
          TestBuzzer();
          j = 100;
          break;
        case 4:
          TestLed();
          j = 100;
          break;
        case 5:
          LCD_Cls();
          lcd.print(F("Salvo Impostazioni?"));
          answer = KeyYesNo();
          if (answer == true){
            SetConfig();
            SaveConfig();
          }
          j = 100;
          break;
        case 6:
          LCD_Cls();
          lcd.print(F("Carico Impostazioni?"));
          answer = KeyYesNo();
          if (answer == true){
            if(CheckConfig()){LoadConfig();}
          }
          j = 100;
          break;
      }
    }
  }
}

void ConfigGame(){
  lcd.setCursor(0, 2);
  lcd.print(F("-   CONFIG. GIOCO  -"));
  lcd.setCursor(0, 3);
  lcd.print(F("D=SELEZIONA - C=DEL "));
  lcd.setCursor(0, 0);
  GAMEHOURS = MenuAskNumber2(1,"HH","--",DigitRestInt(GAMEHOURS,0,2),DigitRestInt(GAMEHOURS,1,2));
  GAMEMINUTES = MenuAskNumber2(1,"minuti","--",DigitRestInt(GAMEMINUTES,0,2),DigitRestInt(GAMEMINUTES,1,2));
  BOMBMINUTES = MenuAskNumber2(2,"minuti","--",DigitRestInt(BOMBMINUTES,0,2),DigitRestInt(BOMBMINUTES,1,2));
  ACTIVATESECONDS = MenuAskNumber2(3,"secondi","--",DigitRestInt(ACTIVATESECONDS,0,2),DigitRestInt(ACTIVATESECONDS,1,2));
  CAPTURESECONDS = MenuAskNumber2(4,"secondi","--",DigitRestInt(CAPTURESECONDS,0,2),DigitRestInt(CAPTURESECONDS,1,2));
  CATCHPOINTMINUTES = MenuAskNumber2(5,"minuti","--",DigitRestInt(CATCHPOINTMINUTES,0,2),DigitRestInt(CATCHPOINTMINUTES,1,2));
  SQLIFES = MenuAskNumber2(6,"vite","--",DigitRestInt(SQLIFES,0,2),DigitRestInt(SQLIFES,1,2));
  MenuConfig();
}

void ConfigAudio(){
  lcd.setCursor(0, 2);
  lcd.print(F("-   CONFIG. AUDIO  -"));
  lcd.setCursor(0, 3);
  lcd.print(F("D=SELEZIONA - C=DEL "));
  lcd.setCursor(0, 0);
  ToneAlarm1 = MenuAskNumber4(1,"Hz","0000",DigitRestInt(ToneAlarm1,0,4),DigitRestInt(ToneAlarm1,1,4),DigitRestInt(ToneAlarm1,2,4),DigitRestInt(ToneAlarm1,3,4));tone(TonePin, ToneAlarm1, 500);
  ToneAlarm2 = MenuAskNumber4(2,"Hz","0000",DigitRestInt(ToneAlarm2,0,4),DigitRestInt(ToneAlarm2,1,4),DigitRestInt(ToneAlarm2,2,4),DigitRestInt(ToneAlarm2,3,4));tone(TonePin, ToneAlarm2, 500);
  ToneArming = MenuAskNumber4(3,"Hz","0000",DigitRestInt(ToneArming,0,4),DigitRestInt(ToneArming,1,4),DigitRestInt(ToneArming,2,4),DigitRestInt(ToneArming,3,4));tone(TonePin, ToneArming, 500);
  ToneError  = MenuAskNumber4(4,"Hz","0000",DigitRestInt(ToneError,0,4),DigitRestInt(ToneError,1,4),DigitRestInt(ToneError,2,4),DigitRestInt(ToneError,3,4));tone(TonePin, ToneError, 500);
  ToneBip    = MenuAskNumber4(5,"Hz","0000",DigitRestInt(ToneBip,0,4),DigitRestInt(ToneBip,1,4),DigitRestInt(ToneBip,2,4),DigitRestInt(ToneBip,3,4));tone(TonePin, ToneBip, 500);
  MenuConfig();
}

void GameConfig() {
  lcd.setCursor(0, 2);
  lcd.print(F("-   CONFIG. GIOCO  -"));
  lcd.setCursor(0, 3);
  lcd.print(F("D=SELEZIONA - C=DEL "));
  lcd.setCursor(0, 0);
  if ( GAMETYPE == 1 || GAMETYPE == 2 || GAMETYPE == 3 || GAMETYPE == 4 || GAMETYPE == 5) {
    GAMEMINUTES = MenuAskTime4(1,'hh:mm','--:--',DigitRestInt(GAMEHOURS,0,2),DigitRestInt(GAMEHOURS,1,2),DigitRestInt(GAMEMINUTES,0,2),DigitRestInt(GAMEMINUTES,1,2));
  }
  if ( GAMETYPE == 1 || GAMETYPE == 2) {
    BOMBMINUTES = MenuAskTime2(1,'minuti','--',DigitRestInt(BOMBMINUTES,0,2),DigitRestInt(BOMBMINUTES,1,2));
  }

  if ( GAMETYPE == 1 || GAMETYPE == 2) {
    ACTIVATESECONDS = MenuAskTime2(2,"secondi","--",DigitRestInt(ACTIVATESECONDS,0,2),DigitRestInt(ACTIVATESECONDS,1,2));
  }
  if ( GAMETYPE == 3 || GAMETYPE == 4 ) {
    ACTIVATESECONDS = MenuAskTime2(3,"secondi","--",DigitRestInt(ACTIVATESECONDS,0,2),DigitRestInt(ACTIVATESECONDS,1,2));
  }
  if ( GAMETYPE == 5) {
    BOMBMINUTES = MenuAskTime2(4,"minuti","--",DigitRestInt(BOMBMINUTES,0,2),DigitRestInt(BOMBMINUTES,1,2));
    SQLIFES =     MenuAskTime2(5,"vite","--",DigitRestInt(SQLIFES,0,2),DigitRestInt(SQLIFES,1,2));
  }
  if ( GAMETYPE == 1 || GAMETYPE == 2 || GAMETYPE == 3 || GAMETYPE == 4 || GAMETYPE == 5) {
    LCD_Cls();
    lcd.print(F("Abilta Sirena?"));
    ALARMACTIVE = KeyYesNo();
  }
  if ( GAMETYPE == 1 || GAMETYPE == 2 || GAMETYPE == 3 || GAMETYPE == 4) {
    LCD_Cls();
    lcd.print(F("Abilita Taglio Cavi?"));
    SMARTCARDACTIVE = KeyYesNo();
  }
  if (( GAMETYPE == 1 || GAMETYPE == 2) && SMARTCARDACTIVE == false) {
    LCD_Cls();
    lcd.print(F("Abilita Codice?"));
    PASSWORDACTIVE = KeyYesNo();
    if(PASSWORDACTIVE == true){
      SetPassword();
    }
  }
}
