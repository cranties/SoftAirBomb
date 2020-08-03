void Domination(){
  StartGameCount();
  LCD_Cls();
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  lcd.setCursor(0, 2);
  lcd.print("--------------------");
  lcd.setCursor(0, 3);
  lcd.print("     DOMINAZIONE    ");
  minutos = GAMEMINUTES - 1;
  iTime=0;
  PLAYING = false;
  PlayForDom();
}

void PlayForDom(){
  unsigned long timeCalcVar;
  unsigned long aTime;
  if(PLAYING = true){
    iTime = millis();
  }
  lcd.setCursor(0, 0);
  lcd.print(" code under develop ");
  delay(3000);
  PlayAgain();
}
