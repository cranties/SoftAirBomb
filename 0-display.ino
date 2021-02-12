void CountDown(String theader, String tmessage, unsigned long secondi, bool btnBtoabort = false, bool bepper = false) {
  String tbutton = "";
  if (btnBtoabort == true) {
    tbutton = "Abort";
  }
  ezProgressBar pb (theader, tmessage, tbutton);
  pb.value(0);
  float stepper = (secondi * 1000 / 100) - 5;
  for (float i = 0; i < 101; i++) {
    pb.value(i);
    if (bepper == true) {
      if (ALARMACTIVE) {
        sb.beep(9, ToneBip, 5);
      }
    }
    delay(stepper);
  }
  if (bepper == true) {
    if (ALARMACTIVE) {
      sb.beep(9, ToneArming, 1000);
    }
  }
}
