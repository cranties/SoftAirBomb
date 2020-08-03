void TestAlarm() {
  LCD_Cls();
  lcd.print(F("TEST SIRENA"));
  digitalWrite(ALARM, HIGH);
  PressKeyToStop();
  digitalWrite(ALARM, LOW);
  delay(500);
}

void TestBuzzer() {
  LCD_Cls(); lcd.print(F("TEST Tone ALARM1"));
  tone(TonePin, ToneAlarm1, 500);
  PressKeyToStop();
  LCD_Cls(); lcd.print(F("TEST Tone ALARM2"));
  tone(TonePin, ToneAlarm2, 500);
  PressKeyToStop();
  LCD_Cls(); lcd.print(F("TEST Tone ARM   "));
  tone(TonePin, ToneArming, 500);
  PressKeyToStop();
  LCD_Cls(); lcd.print(F("TEST Tone ERROR "));
  tone(TonePin, ToneError, 500);
  PressKeyToStop();
  LCD_Cls(); lcd.print(F("TEST Tone BIP   "));
  tone(TonePin, ToneBip, 500);
  PressKeyToStop();
  delay(200);
}

void TestLed(){
  LCD_Cls(); lcd.print(F("TEST LED VERDE"));
  digitalWrite(GREENLED, HIGH);  digitalWrite(GREENLED, LOW);
  delay(200);
  LCD_Cls(); lcd.print(F("TEST LED ROSSO"));
  digitalWrite(REDLED, HIGH);  digitalWrite(REDLED, LOW);
  delay(200);
  LCD_Cls(); lcd.print(F("TEST LED BOMBA"));
  digitalWrite(BOOMLED, HIGH);  digitalWrite(BOOMLED, LOW);
  delay(200);
}


int DigitRestInt(int Numbers, int Poss, int Len) {
  String Nums = String(Numbers);
  while (Nums.length() < Len){
    Nums = "0" + Nums;
  }
  String Chrz = Nums.substring(Poss, Poss + 1);
  int Ret = Chrz.toInt();
  return (Ret);
}

bool ArmKeyHold(char* txt) {
  digitalWrite(GREENLED, LOW);
  LCD_Cls();
  lcd.setCursor(2, 0);
  lcd.print(txt);
  lcd.setCursor(0, 1);
  unsigned int percent = 0;
  unsigned long xTime = millis();
  unsigned long timeCalcVar;
  while (ARMING == true) {
    KeyPad.getKey();
    timeCalcVar = (millis() - xTime) % 1000;
    if ( timeCalcVar >= 0 && timeCalcVar <= 50)
    {
      digitalWrite(REDLED, HIGH);
      tone(TonePin, ToneAlarm1, 200);
      ALARM_OFF();
    } else {
      ALARM_ON();
    }
    if (timeCalcVar >= 470 && timeCalcVar <= 520)
    {
      tone(TonePin, ToneAlarm2, 200);
      digitalWrite(REDLED, LOW);
    }
    unsigned long seconds = millis() - xTime;
    percent = (seconds) / (ACTIVATESECONDS * 10);
    LCD_Percentage(percent);
    if (percent >= 100)
    {
      digitalWrite(REDLED, HIGH);
      digitalWrite(GREENLED, HIGH);
      digitalWrite(BTNLED, HIGH);
      return true;
      break;
    }
  }
  LCD_Cls();
      digitalWrite(REDLED, LOW);
      digitalWrite(GREENLED, LOW);
      digitalWrite(BTNLED, LOW);
  return false;
}

bool DefuseKeyHold(char* txt) {
  digitalWrite(GREENLED, LOW);
  LCD_Cls();
  lcd.setCursor(2, 0);
  lcd.print(txt);
  lcd.setCursor(0, 1);
  unsigned int percent = 0;
  unsigned long xTime = millis();
  unsigned long timeCalcVar;
  while (DEFUSE == true) {
    KeyPad.getKey();
    timeCalcVar = (millis() - xTime) % 1000;
    if ( timeCalcVar >= 0 && timeCalcVar <= 40)
    {
      digitalWrite(REDLED, HIGH);
      tone(TonePin, ToneAlarm1, 200);
      ALARM_ON();
    }
    if (timeCalcVar >= 480 && timeCalcVar <= 520)
    {
      tone(TonePin, ToneAlarm2, 200);
      digitalWrite(REDLED, LOW);
      ALARM_OFF();
    }
    unsigned long seconds = millis() - xTime;
    percent = (seconds) / (ACTIVATESECONDS * 10);
    LCD_Percentage(percent);
    if (percent >= 100)
    {
      digitalWrite(REDLED, LOW);
      digitalWrite(GREENLED, LOW);
      digitalWrite(BTNLED, LOW);
      return true;
      break;
    }
  }
  LCD_Cls();
      digitalWrite(REDLED, HIGH);
      digitalWrite(GREENLED, HIGH);
      digitalWrite(BTNLED, HIGH);
  return false;
}

bool ArmPassword(char* txt) {
  LCD_Clear();
  digitalWrite(GREENLED, LOW);
  digitalWrite(REDLED, HIGH);
  lcd.setCursor(3, 0);
  lcd.print(txt);
  delay(1000);
  LCD_Cls();
  lcd.setCursor(0, 0);
  AskPassword("Inserisci Password:");
  for (int i = 0; i < 4; i++) {
    enteredText[i] = temptext[i];
  }
  if (CheckPassword()) {
      digitalWrite(REDLED, HIGH);
      digitalWrite(GREENLED, HIGH);
      digitalWrite(BTNLED, LOW);
    return true;
  } else {
    LCD_Cls();
    lcd.setCursor(0, 0);
    lcd.print("ERRORE PASSWORD !!!!");
    tone(TonePin, ToneError, 30);
    delay(500);
      digitalWrite(REDLED, LOW);
      digitalWrite(GREENLED, LOW);
      digitalWrite(BTNLED, LOW);
    LCD_Cls();
    return false;
  }
}

bool ArmSmartCard(char* txt) {
  digitalWrite(GREENLED, LOW);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print(txt);
  lcd.setCursor(0, 1);
  unsigned int percent = 0;
  unsigned long xTime = millis();
  unsigned long timeCalcVar;
  while (digitalRead(SMARTCARD) == HIGH) {
    timeCalcVar = (millis() - xTime) % 1000;
    if ( timeCalcVar >= 0 && timeCalcVar <= 40)
    {
      digitalWrite(REDLED, HIGH);
      tone(TonePin, ToneAlarm1, 200);
      ALARM_ON();
    }
    if (timeCalcVar >= 480 && timeCalcVar <= 520)
    {
      tone(TonePin, ToneAlarm2, 200);
      digitalWrite(REDLED, LOW);
      ALARM_OFF();
    }
    unsigned long seconds = millis() - xTime;
    percent = (seconds) / (ACTIVATESECONDS * 10);
    LCD_Percentage(percent);
    if (percent >= 100)
    {
      digitalWrite(REDLED, HIGH);
      digitalWrite(GREENLED, HIGH);
      digitalWrite(BTNLED, LOW);
      return true;
      break;
    }
  }
  LCD_Cls();
      digitalWrite(REDLED, LOW);
      digitalWrite(GREENLED, LOW);
      digitalWrite(BTNLED, LOW);
  return false;
}

void SetPassword() {
ReType:
  LCD_Cls();
  AskPassword("Inserisci Password:");
  for (int i = 0; i < 4; i++) {
    password[i] = temptext[i];
  }
  AskPassword("Ripeti Password:");
  for (int i = 0; i < 4; i++) {
    enteredText[i] = temptext[i];
  }
  if (CheckPassword()) {
    LCD_Cls();
    lcd.setCursor(0, 0);
    lcd.print(F("Password Salvata!"));
    delay(2000);
  } else {
    LCD_Cls();
    lcd.setCursor(0, 0);
    lcd.print(F("ERRORE NON UGUALE"));
    tone(TonePin, ToneError, 30);
    delay(2000);
    goto ReType;
  }
}

boolean CheckPassword() {
  for (int i = 0; i < 4; i++) {
    if (enteredText[i] != password[i])return false;
  }
  return true;
}

void AskPassword(char* quest) {
  LCD_Clear();
  lcd.setCursor(0, 0);
  lcd.print(quest);
  lcd.setCursor(8, 1);
  lcd.print("----");
  lcd.cursor();
  lcd.blink();
  lcd.setCursor(8, 1);
  for (int i = 0; i < 4; i++) {
    byte number = 11;
    while (number == 11) {
      number = KeyGetNumber();
    }
    lcd.setCursor((i+8), 1);
    lcd.print("*");
    temptext[i] =  number;
    tone(TonePin, ToneBip, 30);
  }
  lcd.noCursor();
  lcd.noBlink();
}

int MenuAskTime2(int quest, char* type, char* std, int t1, int t2) {
ReAsk:
  LCD_Cls();
  lcd.setCursor(0, 0);
  if (quest == 1) {lcd.print(F("Tempo Detonazione:"));}
  if (quest == 2) {lcd.print(F("Tempo per ARM/DIS:"));}
  if (quest == 3) {lcd.print(F("Tempo Cattura Punto:"));}
  if (quest == 4) {lcd.print(F("Tempo Rientro:"));}
  if (quest == 5) {lcd.print(F("Numero Vite Squadra"));}
  lcd.setCursor(3, 1);
  lcd.print(type);
  lcd.setCursor(0, 1);
  lcd.print(std);
  lcd.setCursor(0, 1);
  lcd.print(t1);
  lcd.print(t2);
  lcd.cursor();
  lcd.blink();
  lcd.setCursor(0, 1);
  for (int i = 0; i < 2; i++) {
    byte number = 99;
    while (number == 99) {
      number = KeyGetNumber();
      if (number == 11) {
        time[0] = t1;
        time[1] = t2;
        goto EndProg;
        break;
      }
      if (number == 10) {
        goto ReAsk;
        break;
      }
    }
    tone(13, 2400, 30);
    time[i] = number;
    lcd.print(number);
    delay(250);
  }
EndProg:
  lcd.noCursor();
  lcd.noBlink();
  if (KeyConfirm() == false) {
    goto ReAsk;
  }
  return ((time[0] * 10) + (time[1]));
}

int MenuAskTime4(int quest, char* type, char* std, int t1, int t2, int t3, int t4) {
ReAsk:
  LCD_Cls();
  lcd.setCursor(0, 0);
  if (quest == 1) {lcd.print(F("Tempo Max. di Gioco:"));}
  lcd.setCursor(6, 1);
  lcd.print(type);
  lcd.setCursor(0, 1);
  lcd.print(std);
  lcd.setCursor(0, 1);
  lcd.print(t1);
  lcd.print(t2);
  lcd.print(":");
  lcd.print(t3);
  lcd.print(t4);
  lcd.cursor();
  lcd.blink();
  lcd.setCursor(0, 1);
  for (int i = 0; i < 4; i++) {
    if (i == 2) {
      lcd.print(":");
    }
    byte number = 99;
    while (number == 99) {
      number = KeyGetNumber();
      if (number == 11) {
        time[0] = t1;
        time[1] = t2;
        time[2] = t3;
        time[3] = t4;
        goto EndProg;
        break;
      }
      if (number == 10) {
        goto ReAsk;
        break;
      }
    }
    tone(13, 2400, 30);
    time[i] = number;
    lcd.print(number);
    delay(250);
  }
EndProg:
  lcd.noCursor();
  lcd.noBlink();
  if (KeyConfirm() == false) {
    goto ReAsk;
  }
  return ((time[0] * 600) + (time[1] * 60) + (time[2] * 10) + (time[3]));
}

int MenuAskNumber4(int quest, char* type, char* std, int t1, int t2, int t3, int t4) {
ReAsk:
  LCD_Cls();
  lcd.setCursor(0, 0);
  if (quest == 1) {lcd.print(F("Tone ALARM 1:"));}
  if (quest == 2) {lcd.print(F("Tone ALARM 2:"));}
  if (quest == 3) {lcd.print(F("Tone ARMING:"));}
  if (quest == 4) {lcd.print(F("Tone ERROR:"));}
  if (quest == 5) {lcd.print(F("Tone BIP:"));}
  lcd.setCursor(6, 1);
  lcd.print(type);
  lcd.setCursor(0, 1);
  lcd.print(std);
  lcd.setCursor(0, 1);
  lcd.print(t1);
  lcd.print(t2);
  lcd.print(t3);
  lcd.print(t4);
  lcd.cursor();
  lcd.blink();
  lcd.setCursor(0, 1);
  for (int i = 0; i < 4; i++) {
    byte number = 99;
    while (number == 99) {
      number = KeyGetNumber();
      if (number == 11) {
        time[0] = t1;
        time[1] = t2;
        time[2] = t3;
        time[3] = t4;
        goto EndProg;
        break;
      }
      if (number == 10) {
        goto ReAsk;
        break;
      }
    }
    tone(13, 2400, 30);
    time[i] = number;
    lcd.print(number);
    delay(250);
  }
EndProg:
  lcd.noCursor();
  lcd.noBlink();
  if (KeyConfirm() == false) {
    goto ReAsk;
  }
  return ((time[0] * 1000) + (time[1] * 100) + (time[2] * 10) + (time[3]));
}

int MenuAskNumber2(int quest, char* type, char* std, int t1, int t2) {
ReAsk:
  LCD_Cls();
  lcd.setCursor(0, 0);
  if (quest == 1) {lcd.print(F("Max Tempo Gioco:"));}
  if (quest == 2) {lcd.print(F("Tempo Detonazione:"));}
  if (quest == 3) {lcd.print(F("Tempo ARM/DIS:"));}
  if (quest == 4) {lcd.print(F("Tempo Cattura:"));}
  if (quest == 5) {lcd.print(F("Tempo Conquista:"));}
  if (quest == 6) {lcd.print(F("Numero di Vite:"));}
  lcd.setCursor(6, 1);
  lcd.print(type);
  lcd.setCursor(0, 1);
  lcd.print(std);
  lcd.setCursor(0, 1);
  lcd.print(t1);
  lcd.print(t2);
  lcd.cursor();
  lcd.blink();
  lcd.setCursor(0, 1);
  for (int i = 0; i < 2; i++) {
    byte number = 99;
    while (number == 99) {
      number = KeyGetNumber();
      if (number == 11) {
        time[0] = t1;
        time[1] = t2;
        goto EndProg;
        break;
      }
      if (number == 10) {
        goto ReAsk;
        break;
      }
    }
    tone(13, 2400, 30);
    time[i] = number;
    lcd.print(number);
    delay(250);
  }
EndProg:
  lcd.noCursor();
  lcd.noBlink();
  if (KeyConfirm() == false) {
    goto ReAsk;
  }
  return ((time[0] * 10) + (time[1]));
}

void PlayAgain() {
  LCD_Cls();
  PLAYING = false;
  lcd.print(F(" Giocare Ancora? "));
  lcd.setCursor(0, 1);
  lcd.print(F("C : No  -  D : SI"));
  while (1)
  {
    char key = KeyPad.waitForKey();
    if (key == 'd' ) {
      tone(TonePin, ToneBip, 30);
      switch (GAMETYPE) {
        case 0:
          SearchDestroy();
          break;
        case 1:
          Sabotage();
          break;
        case 2:
          Domination();
          break;
        case 3:
          Capture();
          break;
      }
    }
    if (key == 'c' ) {
      tone(TonePin, ToneBip, 30);
      Software_Reboot();
      break;
    }
  }
}

void StartGameCount() {
  LCD_Cls();
  lcd.setCursor(0, 0);
  lcd.print(F("PRONTO PER INIZIARE!"));
  lcd.setCursor(0, 1);
  lcd.print(F("                    "));
  lcd.setCursor(0, 2);
  lcd.print(F("                    "));
  lcd.setCursor(0, 3);
  lcd.print(F(" Premi un Pulsante! "));
  PressAKey();
  LCD_Cls();
  lcd.setCursor(0, 1);
  lcd.print(F(" ATTENDI 10 SECONDI "));
  for (int i = 9; i > 0 ; i--) {
    lcd.setCursor(9, 2);
    tone(TonePin, ToneBip, 30);
    lcd.print(i);
    delay(1000);
  }
  PLAYING = true;
  LCD_Cls();
}

void PrintTime(unsigned long minutos, unsigned long aTiempo) {
  unsigned long sectoprint;
  sectoprint = (minutos*60 - aTiempo/600);
  char str[12];
  long h = sectoprint / 3600;
  sectoprint = sectoprint % 3600;
  int m = sectoprint / 60;
  int s = sectoprint % 60;
  sprintf(str, "%04ld:%02d:%02d", h, m, s);
  lcd.print(str);
}

void EndNoWin() {
  LCD_Cls();
  lcd.print(F("  -- GAME  OVER --"));
  lcd.setCursor(0, 1);
  lcd.print(F("  TEMPO ESAURITO  "));
  for (int i = 1; i < 11; i++) {
    tone(TonePin, ToneBip, 30);
    delay(100);
  }
  noTone(TonePin);
  ALARM_ON();
  PressAKey();
  ALARM_OFF();
  PlayAgain();
}

void EndAttackerWin() {
  LCD_Cls();
  lcd.print(F("  -- GAME  OVER --"));
  lcd.setCursor(0, 1);
  lcd.print(F("VINCONO ATTACCANTI"));
  for (int i = 1; i < 11; i++) {
    tone(TonePin, ToneBip, 30);
    delay(100);
  }
  noTone(TonePin);
  ALARM_ON();
  PressAKey();
  ALARM_OFF();
  PlayAgain();
}

void EndDefenderWin() {
  LCD_Cls();
  lcd.print(F("  -- GAME  OVER --"));
  lcd.setCursor(0, 1);
  lcd.print(F("VINCONO DIFENSORI "));
  for (int i = 1; i < 11; i++) {
    tone(TonePin, ToneError, 30);
    delay(100);
  }
  noTone(TonePin);
  ALARM_ON();
  PressAKey();
  ALARM_OFF();
  PlayAgain();
}

void ALARM_ON() {
  if (ALARMACTIVE) {
    digitalWrite(ALARM, HIGH);
  }
}

void ALARM_OFF() {
  if (ALARMACTIVE) {
    digitalWrite(ALARM, LOW);
  }
}

void Software_Reboot(){
  wdt_enable(WDTO_15MS);
  while(1)
  {
  }
}
