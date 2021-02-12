void HelpSearchDestroy() {
  ez.textBox("Search and Destroy", "Team A must find the Bomb defended by Team B, take it to the designated target location, arm it and protect it until detonation.\nTeam B wins if they defeat Team A or if they defuse the Bomb.", true);
}

void HelpSabotage() {
  ez.textBox("Sabotage", "Team A must arm the Bomb before the time limit runs out and protect it.\nTeam B must find the bomb and defuse it before the time limit runs out.", true);
}

void HelpDomination() {
  ez.textBox("Domination", "Both teams must take control of the device and protect it.\nThe team wins, who managed to keep the device under his control for the longest time after the time ran out.", true);
}

void HelpCaptureTheFlag() {
  ez.textBox("Capture The Flag", "Team A must protect the device.\nTeam B must capture the device or kill all members of Team A within the maximum time.", true);
}

void HelpChronos() {
  ez.textBox("Chrono Respawn", "This function allows you to count the number of team re-entries.|Each team has a number of lives for possible re-entries, and the device counts lives and respawn time.", true);
}

void HelpSAP() {
  ez.msgBox("SoftAirBomb", "Firmware Version: " + VER + "|Developed by|Andrea Monni|cranties76@gmail.com", "Continue");
  ez.screen.clear();
  M5.Lcd.qrcode("mailto:cranties76@gmail.com");
  ez.buttons.wait("OK");
}
