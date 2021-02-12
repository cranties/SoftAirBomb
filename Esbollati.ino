#include <M5Stack.h>
#include <M5ez.h>
#include <ezTime.h>
#include <SPIFFS.h>
#include <EEPROM.h>
#include <SimpleBeep.h>
#include <Preferences.h>

// CONFIG VERSION
String VER = "2.37";

// CONFIG TYPE
unsigned int CONFIG_VERSION = 125;

// EEPROM
Preferences Config;

// TONE
unsigned int ToneAlarm1 = 700;
unsigned int ToneAlarm2 = 2600;
unsigned int ToneArming = 1330;
unsigned int ToneError = 100;
unsigned int ToneBip = 2400;

// TIME GAME e OPTIONS
unsigned int GAMEMINUTES = 15;
unsigned int ACTIVATESECONDS = 10;
unsigned int CAPTURESECONDS = 10;
unsigned int CATCHPOINTMINUTES = 3;
unsigned int SQLIFES = 10;
bool ALARMACTIVE = true;
bool SMARTCARDACTIVE = false;
bool PASSWORDACTIVE = false;
bool IOALARMACTIVE = false;
unsigned short IO_ALARM = 21;
unsigned short IO_OTHER = 22;
bool PLAYING = false;
long iTime;
unsigned int minutos;
String PASSWORD = "";

// VARIABLES
char keymap[1][3][4] = {{{'7', '8', '9', '0'}, {'4', '5', '6', '<'}, {'1', '2', '3', 'E'}}};
bool showkey = true;
bool firsttime = true;
int shift = 0;
int csel = 3;
int rsel = 2;
int ocsel = -1;
int orsel = -1;
String keystring;
String okeystring;

void setup() {
  M5.begin();
  M5.Power.begin();
  M5.Lcd.fillScreen(WHITE);
  delay(100);
  M5.Lcd.fillScreen(RED);
  delay(100);
  M5.Lcd.fillScreen(GREEN);
  delay(100);
  M5.Lcd.fillScreen(BLUE);
  delay(100);
  M5.Lcd.fillScreen(BLACK);
  delay(100);
  ez.begin();
  sb.init();
  pinMode(IO_ALARM, OUTPUT);
  pinMode(IO_OTHER, OUTPUT);
  digitalWrite(IO_ALARM, LOW);
  digitalWrite(IO_OTHER, LOW);
  ez.theme->select("Default");
  if (ALARMACTIVE) {
    sb.beep(9, ToneBip, 90);
  }
  ez.msgBox("SoftAirBomb", "Firmware Version: " + VER, "Continue", true);
  if (ALARMACTIVE) {
    sb.beep(9, ToneBip, 90);
  }
  delay(90);
  if (CheckConfig()) {
    LoadConfig();
  }
}

void loop() {
  FmenuTop();
}

void Ftest() {

}
