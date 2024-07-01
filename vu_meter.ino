int fast0 = 0;
int slow0 = 0;
int fast1 = 0;
int slow1 = 0;
int fast2 = 0;
int slow2 = 0;
int fast3 = 0;
int slow3 = 0;
int sens12 = 100;
int sens34 = 100;
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels(100, 3, NEO_GRB + NEO_KHZ800);

void setup(){
    Serial.begin(115200);
    pixels.begin();
    pixels.clear();
}

void loop(){
    int accumulator0 = 0;
    int accumulator1 = 0;
    int accumulator2 = 0;
    int accumulator3 = 0;
    for(int i = 0; i < 25; i++){
        accumulator0 += analogRead(A0);
        accumulator1 += analogRead(A1);
        accumulator2 += analogRead(A2);
        accumulator3 += analogRead(A3);
        delayMicroseconds(50);
    }
    for(int i = 0; i < 25; i++){
        accumulator0 += analogRead(A0);
        accumulator1 += analogRead(A1);
        accumulator2 += analogRead(A2);
        accumulator3 += analogRead(A3);
        delayMicroseconds(70);
    }

    accumulator0 = map(sqrt(20*accumulator0),0,50,0,sens12);
    accumulator1 = map(log(accumulator1),0,50,0,sens12);
    accumulator2 = map(log(accumulator2),0,50,0,sens12);
    accumulator3 = map(log(accumulator3),0,50,0,sens12);

    fast0 = fast0 - 5;
    fast0 = max(fast0, accumulator0);
    slow0 = slow0 - 1;
    slow0 = max(slow0, accumulator0);

    
    fast1 = fast1 - 5;
    fast1 = max(fast1, accumulator1);
    slow1 = slow1 - 1;
    slow1 = max(slow1, accumulator1);

    
    fast2 = fast2 - 5;
    fast2 = max(fast2, accumulator2);
    slow2 = slow2 - 1;
    slow2 = max(slow2, accumulator2);

    
    fast3 = fast3 - 5;
    fast3 = max(fast3, accumulator3);
    slow3 = slow3 - 1;
    slow3 = max(slow3, accumulator3);

    for(int j = 0; j <25;j++){
        if(fast0/10 >= j){
            if(j > 22){
                pixels.setPixelColor(j, pixels.Color(255, 0, 0));
            }else if(j > 12){
                pixels.setPixelColor(j, pixels.Color(100, 50, 0));
            }else{
                pixels.setPixelColor(j, pixels.Color(0, 60, 0));
            }
        }else{
            pixels.setPixelColor(j,0);
        }
    }
    pixels.setPixelColor(int(slow0/10),pixels.Color(150,00,150));

    pixels.show();   // Send the updated pixel colors to the hardware.

}
