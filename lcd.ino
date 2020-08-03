void LCD_Welcome(){
  lcd.setCursor(0, 0);
  lcd.print(F("    SOFTAIR BOMB    "));
  lcd.setCursor(0, 1);
  lcd.print(F("  FIRMWARE REV 4.1  "));
  lcd.setCursor(0, 2);
  lcd.print(F("                    "));
  lcd.setCursor(0, 3);
  lcd.print(F("  ESBOLLATI  PRATO  "));
  delay(5000);
}

void LCD_CreateBar(){
  byte bar1[8] = {    B10000,    B10000,    B10000,    B10000,    B10000,    B10000,    B10000,    B10000,  };
  byte bar2[8] = {    B11000,    B11000,    B11000,    B11000,    B11000,    B11000,    B11000,    B11000,  };
  byte bar3[8] = {    B11100,    B11100,    B11100,    B11100,    B11100,    B11100,    B11100,    B11100,  };
  byte bar4[8] = {    B11110,    B11110,    B11110,    B11110,    B11110,    B11110,    B11110,    B11110,  };
  byte bar5[8] = {    B11111,    B11111,    B11111,    B11111,    B11111,    B11111,    B11111,    B11111,  };
  byte up[8]   = {    B00000,    B00100,    B01110,    B11111,    B11111,    B00000,    B00000,  };
  byte down[8] = {    B00000,    B00000,    B11111,    B11111,    B01110,    B00100,    B00000,  };
  lcd.createChar(0, bar1);
  lcd.createChar(1, bar2);
  lcd.createChar(2, bar3);
  lcd.createChar(3, bar4);
  lcd.createChar(4, bar5);
  lcd.createChar(5, up);
  lcd.createChar(6, down);
}

void LCD_Cls() {
  lcd.setCursor(0, 0);
  lcd.print(F("                    "));
  lcd.setCursor(0, 1);
  lcd.print(F("                    "));
  lcd.setCursor(0, 0);
}

void LCD_Clear(){
  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("                    "));
  lcd.setCursor(0, 1);
  lcd.print(F("                    "));
  lcd.setCursor(0, 0);
}

void LCD_Percentage(byte porcent) {
  int aDibujar = (8 * porcent) / 8;
  lcd.setCursor(0, 1);
  if (aDibujar < 5)
  {
    switch (aDibujar) {
      case 0:
        break;
      case 1:
        lcd.write((uint8_t)0);
        break;
      case 2:
        lcd.write(1);
        break;
      case 3:
        lcd.write(2);
        break;
      case 4:
        lcd.write(3);
        break;
    }
  }
  while (aDibujar >= 5) {
    if (aDibujar >= 5)
    {
      lcd.write(4);
      aDibujar -= 5;
    }
    if (aDibujar < 5)
    {
      switch (aDibujar) {
        case 0:
          break;
        case 1:
          lcd.write((uint8_t)0);
          break;
        case 2:
          lcd.write(1);
          break;
        case 3:
          lcd.write(2);
          break;
        case 4:
          lcd.write(3);
          break;
      }
    }
  }
}

void checkArrows(byte i, byte maxx ) {
  if (i == 0) {
    lcd.setCursor(19, 1);
    lcd.write(6);
  }
  if (i == maxx) {
    lcd.setCursor(19, 0);
    lcd.write(5);
  }
  if (i > 0 && i < maxx) {
    lcd.setCursor(19, 1);
    lcd.write(6);
    lcd.setCursor(19, 0);
    lcd.write(5);
  }
}
