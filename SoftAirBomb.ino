#include <Wire.h>
#include <EEPROMex.h>
#include <Keypad.h>
//#include "I2CIO.h"
//#include "LCD.h"
#include <LiquidCrystal_I2C.h>
#include <avr/wdt.h>

// CONFIG TYPE
#define CONFIG_VERSION "GB4"

// EEPROM
#define memoryBase 32
int configAdress=0;
struct ConfigStruct {
    char version[4];
    int GH, GM, GB, GA, GS, GC, GP, SQ;          
    int T1, T2, TA, TE, TB;
};
ConfigStruct ConfigData;
ConfigStruct TestData;

// LCD
LiquidCrystal_I2C lcd(0x27, 20, 4); // CONNESSO A4=SDA A5=SCL

// KEYPAD
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = { { '1', '2', '3', 'a' } , { '4', '5', '6', 'b' } , { '7', '8', '9', 'c' } , { '*', '0', '#', 'd' } };
byte rowPins[ROWS] = {  2, 3, 4, 5 };         // CONNESSO D2-D5
byte colPins[COLS] = {  A3, A2, A1, A0 };     // CONNESSO A3-A0
Keypad KeyPad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// SMARTCARD
const int SMARTCARD = 7;        // CONNESSO D7

// LEDS
const int BTNLED   = 12;        // CONNESSO D12
const int REDLED   = 11;        // CONNESSO D11
const int GREENLED = 10;        // CONNESSO D10
const int BOOMLED  =  6;        // CONNESSO D6

// ALARM RELAYS
const int ALARM = 9;            // CONNESSO D9

// SECOND RELAYS
const int RELAY = 8;            // CONNESSO D8

// TONE
int TonePin = 13;               // CONNESSO D13
int ToneAlarm1 = 700;
int ToneAlarm2 = 2600;
int ToneArming = 1330;
int ToneError = 100;
int ToneBip = 2400;

// TIME GAME e OPTIONS
short int GAMEHOURS = 0;
short int GAMEMINUTES = 45;
short int BOMBMINUTES = 5;
short int ACTIVATESECONDS = 15;
short int CAPTURESECONDS = 20;
short int CATCHPOINTMINUTES = 3;
short int SQLIFES = 15;
byte time[4];
bool ALARMACTIVE = true;
bool SMARTCARDACTIVE = false;
bool PASSWORDACTIVE = false;
char enteredText[4];
char password[4];
char temptext[4];
bool PLAYING = false;
long iTime;
short int minutos;

// VARIABLES
bool DEFUSE = false;
bool ARMING = false;
short int GAMETYPE = 0;

void setup() {
  lcd.begin(20,4);
  lcd.backlight();
  KeyPad.setHoldTime(50);
  KeyPad.setDebounceTime(50);
  KeyPad.addEventListener(KeyPadEvent);
  pinMode(GREENLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(BTNLED, OUTPUT);
  pinMode(ALARM, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(SMARTCARD, INPUT);
  digitalWrite(ALARM, LOW);
  digitalWrite(RELAY, LOW);
  tone(TonePin, ToneBip, 90);
  LCD_Welcome();
  LCD_CreateBar();
  EEPROM.setMemPool(memoryBase, EEPROMSizeUno);
  configAdress  = EEPROM.getAddress(sizeof(ConfigStruct)); 
  if(CheckConfig()){LoadConfig();}
  LCD_Cls();
}

void loop(){
  MenuMain();
}
