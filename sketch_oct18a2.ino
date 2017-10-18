#include <Adafruit_SSD1306.h>


int ledPins[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 12};
const int ledCount = 10; // the number of LEDs in the bar graph


#define fsr_pin A0
#include<Wire.h>


#include<SPI.h>


#include<Adafruit_GFX.h>


#include<Adafruit_SSD1306.h>
#define OLED_MOSI 11
#define OLED_CLK 12
#define OLED_DC  9
#define OLED_CS  8
#define OLED_RESET  10
Adafruit_SSD1306 display(OLED_MOSI,OLED_CLK,OLED_DC,OLED_RESET,OLED_CS);
static const unsigned char PROGMEM Logo[]={
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00010000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00011110, B10111101, B11110111, B11011001, B01111000, B00000000, B00000011, 
  B00000000, B00000000, B00011110, B10101100, B11110111, B11011101, B01011000, B00000000, B00000011, 
  B00000000, B00000000, B00010011, B10100111, B10010100, B11010101, B01001000, B00000000, B00000011, 
  B00000000, B00000000, B00011111, B10111101, B11110111, B11010011, B01111000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00111111, B11111111, B11100111, B11111111, B11111100, B00000000, B00000011, 
  B00000000, B00000000, B01111111, B11111111, B11101111, B11111111, B11111110, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00101100, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000011, B01111111, B11111111, B00101101, B11111111, B11111101, B10000000, B00000011, 
  B00000000, B00000001, B10111000, B00000001, B10101101, B10000000, B00011001, B10000000, B00000011, 
  B00000000, B00000000, B11011000, B00000001, B10101101, B00000000, B00011011, B00000000, B00000011, 
  B00000000, B00000000, B01101100, B00000001, B10101101, B00000000, B00110110, B00000000, B00000011, 
  B00000000, B00000000, B01110110, B00000001, B10101101, B00000000, B01101100, B00000000, B00000011, 
  B00000000, B00000000, B00111011, B00000001, B10101101, B00000000, B11011000, B00000000, B00000011, 
  B00000000, B00000000, B00011101, B10000001, B10101101, B00000001, B10111000, B00000000, B00000011, 
  B00000000, B00000000, B00111100, B11000001, B10101101, B00000011, B01111000, B00000000, B00000011, 
  B00000000, B00000000, B11011100, B00000001, B10101101, B00000000, B00011010, B00000000, B00000011, 
  B00000000, B00000000, B01101100, B00000001, B10101101, B00000000, B00110110, B00000000, B00000011, 
  B00000000, B00000000, B01110110, B00000001, B10101101, B00000000, B01101100, B00000000, B00000011, 
  B00000000, B00000000, B00111011, B00000001, B10101101, B00000000, B11011000, B00000000, B00000011, 
  B00000000, B00000000, B00011001, B10000001, B10101101, B00000001, B10110000, B00000000, B00000011, 
  B00000000, B00000000, B00001100, B11000001, B10101101, B00000011, B01100000, B00000000, B00000011, 
  B00000000, B00000000, B00000110, B11100000, B10101101, B00000010, B01000000, B00000000, B00000011, 
  B00000000, B00000000, B00000011, B01110000, B00101100, B00000110, B11000000, B00000000, B00000011, 
  B00000000, B00000000, B00000001, B10110000, B00101100, B00001101, B10000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B11011000, B00101000, B00011011, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B11101100, B00000000, B00110110, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B01100110, B00000000, B01101100, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00110011, B00000000, B11011000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00011001, B10000001, B10010000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00001101, B10000001, B10110000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000110, B11000011, B01100000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000011, B01100110, B11000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000011, B10101101, B10000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000001, B11011011, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B11000110, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B01100110, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00101100, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00011000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000011, 
  
};
void setup(){


Serial.begin(9600);
display.begin(SSD1306_SWITCHCAPVCC);
display.clearDisplay();
display.drawBitmap(30,-15,Logo,70,70,WHITE);
display.display();
for (int thisLed = 0; thisLed < ledCount; thisLed++) {


pinMode(ledPins[thisLed], OUTPUT);


}


}




void loop()


{}

//
//int fsr_value = analogRead(fsr_pin); // 讀取FSR
//
//
//int led_value = map(fsr_value, 0, 1023, 0, 10); // 從0~1023映射到0~10
//for (int thisLed = 0; thisLed < ledCount;
//thisLed++) {
//
//
//if (thisLed < led_value) {
//
//
//
//digitalWrite(ledPins[thisLed], HIGH);
//
//
//}
//
//
//else {
//
//
//
//digitalWrite(ledPins[thisLed], LOW);
//}
//}
//}
