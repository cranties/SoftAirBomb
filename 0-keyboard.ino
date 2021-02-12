String AskNumber(String titolo = "SoftAirBomb", String domanda = "INPUT", String defaultt = "15") {
  showkey = true;
  firsttime = true;
  shift = 0;
  csel = 3;
  rsel = 2;
  ocsel = -1;
  orsel = -1;
  keystring = "";
  okeystring = "";
  M5.Lcd.fillScreen(61309);
  ez.header.show(titolo);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_BLACK, 61309);
  M5.Lcd.drawString(domanda, 0, 50, 4);
  keystring = defaultt;
  keyboard();
  while (1) {
    if (showkey) {
      if (M5.BtnC.wasReleased()) {
        csel = csel + 1;
        if (csel > 3) {
          csel = 0;
          rsel = rsel + 1;
          if (rsel > 2) {
            rsel = 0;
          }
        }
      }
      if (M5.BtnA.wasReleased()) {
        csel = csel - 1;
        if (csel < 0) {
          csel = 3;
          rsel = rsel - 1;
          if (rsel < 0) {
            rsel = 2;
          }
        }
      }
      if (M5.BtnB.wasReleased()) {
        if (firsttime != true) {
          int len = keystring.length();
          if ((rsel == 2) && (csel == 3)) {
            csel = 2;
            rsel = 3;
            if (ALARMACTIVE) {
              sb.beep(5, ToneBip, 90);
            }
            return (keystring);
          } else {
            if ((rsel == 1) && (csel == 3)) {
              if (ALARMACTIVE) {
                sb.beep(5, ToneBip, 50);
              }
              keystring = keystring.substring(0, len - 1);
            } else {
              if (len > 2) {
                if (ALARMACTIVE) {
                  sb.beep(5, ToneError, 100);
                }
              } else {
                if (ALARMACTIVE) {
                  sb.beep(5, ToneBip, 50);
                }
                keystring += keymap[shift][rsel][csel];
              }
            }
          }
        } else {
          firsttime = false;
        }
      }
      keyboard();
      okeystring = keystring;
    }
    delay(1);
    M5.update();
  }
}

bool AskYesNo(String titolo = "SoftAirBomb", String domanda = "INPUT"){
  String risposta;
  risposta = ez.msgBox(titolo, domanda, "YES##NO", true);
  if (risposta == "YES") {
    return true;
  }else{
    return false;
  }
}

void PressButton(String titolo = "SoftAirBomb", String domanda = "INPUT"){
  ez.msgBox(titolo, domanda, "DONE", true);
}

void keyboard() {
  if ((showkey) && ((csel != ocsel) || (rsel != orsel) || (keystring != okeystring))) {
    M5.Lcd.fillRect(0, 120, 320, 60, 61309);
    M5.Lcd.setTextColor(TFT_BLUE, 61309);
    M5.Lcd.drawRect(115, 95, 80, 35, BLUE);
    M5.Lcd.drawString("          ", 120, 100, 4);
    M5.Lcd.drawString(String(keystring + "_"), 120, 100, 4);
    int x, y;
    M5.Lcd.fillRect(0, 144, 320, 240, 61309);
    for (int r = 0; r < 3; r++) {
      for (int c = 0; c < 4; c++) {
        x = (c * 80);
        y = (144 + (r * 32));
        if ((csel == c) && (rsel == r)) {
          M5.Lcd.setTextColor(61309, TFT_BLUE);
          M5.Lcd.fillRect(x, y, 80, 32, BLUE);
        } else {
          M5.Lcd.setTextColor(TFT_BLACK, 61309);
          M5.Lcd.drawRect(x, y, 80, 32, BLUE);
        }
        M5.Lcd.drawString(String(keymap[shift][r][c]), x + 10 + 2 + 24, y + 7 + 6, 2);
      }
    }
    ocsel = csel;
    orsel = rsel;
  }
}
