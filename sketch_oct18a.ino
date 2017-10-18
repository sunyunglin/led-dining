const int ledCount = 10; // the number of LEDs in the bar graph


int ledPins[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 12};


#define fsr_pin A0




void setup(){


Serial.begin(115200);


for (int thisLed = 0; thisLed < ledCount; thisLed++) {


pinMode(ledPins[thisLed], OUTPUT);


}


}




void loop()


{


int fsr_value = analogRead(fsr_pin); // 讀取FSR


int led_value = map(fsr_value, 0, 1023, 0, 10); // 從0~1023映射到0~10
for (int thisLed = 0; thisLed < ledCount;
thisLed++) {


if (thisLed < led_value) {



digitalWrite(ledPins[thisLed], HIGH);


}


else {



digitalWrite(ledPins[thisLed], LOW);
}
}
}
