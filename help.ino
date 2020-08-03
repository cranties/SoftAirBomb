void Help(){
  tone(13, 2400, 30);
  LCD_Cls();
  switch (GAMETYPE) {
        case 0:
          lcd.setCursor(0, 0);
          lcd.print(F("Sq. A: Armare Bomba "));
          lcd.setCursor(0, 1);
          lcd.print(F("Sq. B: Sterminare A "));
          lcd.setCursor(0, 2);
          lcd.print(F("       o Disarmare  "));
          break;
        case 1:
          lcd.setCursor(0, 0);
          lcd.print(F("Sq. A: Armare Bomba "));
          lcd.setCursor(0, 1);
          lcd.print(F("Sq. B: Disarmare    "));
          lcd.setCursor(0, 2);
          lcd.print(F("Vince B per Tempo   "));
          break;
        case 2:
          lcd.setCursor(0, 0);
          lcd.print(F("Vince la Sq. che    "));
          lcd.setCursor(0, 1);
          lcd.print(F("mantiene il possesso"));
          lcd.setCursor(0, 2);
          lcd.print(F("per più tempo       "));
          break;
        case 3:
          lcd.setCursor(0, 0);
          lcd.print(F("Sq. A: Proteggere   "));
          lcd.setCursor(0, 1);
          lcd.print(F("Sq. B: Conquistare  "));
          lcd.setCursor(0, 2);
          lcd.print(F("Vince A per Tempo   "));
          break;
        case 4:
          lcd.setCursor(0, 0);
          lcd.print(F("Gestisce il Tempo   "));
          lcd.setCursor(0, 1);
          lcd.print(F("dei Rentri per Morte"));
          lcd.setCursor(0, 2);
          lcd.print(F("delle due squadre   "));
          break;
        case 5:
          lcd.setCursor(0, 0);
          lcd.print(F("Configurazioni      "));
          lcd.setCursor(0, 1);
          lcd.print(F("Globali e Test di   "));
          lcd.setCursor(0, 2);
          lcd.print(F("Funzionamento       "));
          break;
      }
  lcd.setCursor(0, 3);
  lcd.print(F("   Premi un tasto   "));
  PressAKey();
}
