#include <Servo.h>

Servo servo1;  // Create servo object for first servo
Servo servo2;  // Create servo object for second servo
int x = 0;
int y = 0;
void setup() {
    Serial.begin(9600);  // Start serial communication at 9600 baud
    servo1.attach(9);  // Attach first servo to pin D9
    servo2.attach(10); // Attach second servo to pin D10
}

void loop() {
   if (Serial.available()) {  // Check if data is available to read
        String receivedData = Serial.readStringUntil('\n');  // Read the incoming string
        Serial.print("Received: ");  
        Serial.println(receivedData);  // Print received data

        if (receivedData == "d"){
          x-= 18;
        }
        else if (receivedData == "a"){
           x+= 18;
        }
        else if (receivedData == "s"){
          y-= 18;
        }
        else if (receivedData == "w"){
          y+=18;
        }

        if (x >180){
          x = 180;
        }
        else if (x < 0){
          x =0;
        }
        else if (y > 180){
          y = 180;
        }
        else if (y < 0){
          y = 0;
        }

            // Move both servos to 0 degrees
    servo1.write(x);
    servo2.write(y);
    delay(60);
    }
  


}
