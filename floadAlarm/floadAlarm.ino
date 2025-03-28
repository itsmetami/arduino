/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board
#include <SoftwareSerial.h>
long duration;
int distance;


const int red = 9;
const int trigPin = 10;
const int echoPin = 11;

const int buzzer = 7;
const int yellow = 6;
const int green = 5;




void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);



  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);


}


// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(trigPin, LOW);
  delay(1000); 
 
  digitalWrite(trigPin, HIGH);
  delay(1000); 
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration *0.034 / 2;

  Serial.print("Distance: \n");
  Serial.print(distance);

if (distance <= 18) {
    digitalWrite(red, HIGH); // Turn LED ON
    digitalWrite(yellow, LOW);
   digitalWrite(green, LOW);
    // Ascending tone (siren going up)
    for (int freq = 500; freq <= 1500; freq += 10) {
        if (distance > 15) { // Stop if condition is false
            noTone(buzzer);
            digitalWrite(red, LOW); // Turn LED OFF
            break;
        }
        tone(buzzer, freq);
        delay(100);
    }

    // Descending tone (siren going down)
    for (int freq = 1500; freq >= 500; freq -= 10) {
        if (distance > 15) { // Stop if condition is false
            noTone(buzzer);
            digitalWrite(red, LOW); // Turn LED OFF
            break;
        }
        tone(buzzer, freq);
        delay(100);
    }
}
  else if (distance <=25){
  digitalWrite(buzzer, LOW); // Turn buzzer ON
   digitalWrite(yellow, HIGH);
   delay(3000);
   digitalWrite(yellow, LOW);
   delay(3000);
   digitalWrite(yellow, HIGH);
   delay(3000);
   digitalWrite(yellow, LOW);
   digitalWrite(red, LOW); // Ensure LED is OFF 
   digitalWrite(green, LOW);
  }

  else{
     noTone(buzzer);
     digitalWrite(green, HIGH);
     delay(1000);
     digitalWrite(green, LOW);
     digitalWrite(buzzer, LOW);
      digitalWrite(red, LOW); // Ensure LED is OFF 
      digitalWrite(yellow, LOW);
  }

  

  


}
