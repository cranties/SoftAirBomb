void KeyPadEvent(KeypadEvent key) {
  switch (KeyPad.getState()) {
    case PRESSED:
      break;
    case RELEASED:
      switch (key) {
        case 'd': DEFUSE = false;
          break;
        case 'c': ARMING = false;
          break;
      }
      break;
    case HOLD:
      switch (key) {
        case 'd': DEFUSE = true;
          break;
        case 'c': ARMING = true;
          break;
      }
      break;
  }
}

void PressKeyToStop() {
  lcd.setCursor(0, 1);
  lcd.print("Premi un tasto");
  KeyPad.waitForKey();
}

void PressAKey() {
  KeyPad.waitForKey();
}

bool KeyConfirm() {
  lcd.setCursor(13, 1);
  lcd.print("OK?");
  while (1) {
    char key = KeyPad.waitForKey();
    tone(TonePin, ToneBip, 30);
    if (key == 'c') {
      return false;
    }
    if (key == 'd') {
      return true;
    }
  }
}

bool KeyYesNo() {
  lcd.setCursor(0, 1);
  lcd.print(F("C : No  -  D : SI"));
  while (1) {
    char key = KeyPad.waitForKey();
    tone(TonePin, ToneBip, 30);
    if (key == 'd') {
      return true;
    }
    if (key == 'c') {
      return false;
    }
  }
}

byte KeyGetNumber() {
  char key = KeyPad.getKey();
  if (key == '1') {
    return 1;
  }
  if (key == '2') {
    return 2;
  }
  if (key == '3') {
    return 3;
  }
  if (key == '4') {
    return 4;
  }
  if (key == '5') {
    return 5;
  }
  if (key == '6') {
    return 6;
  }
  if (key == '7') {
    return 7;
  }
  if (key == '8') {
    return 8;
  }
  if (key == '9') {
    return 9;
  }
  if (key == '0') {
    return 0;
  }
  return 11;
}
