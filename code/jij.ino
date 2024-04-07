#include <Servo.h>

Servo servo1;
Servo servo2;
int LED1 = 3;
int LED2 = 4;
int Mode_Button =7;
const int trigPin = 9;
const int echoPin = 10;
int play=8;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(Mode_Button, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
  pinMode(play,OUTPUT);
  digitalWrite(play,LOW);
  servo1.attach(5); 
  servo2.attach(6);
  servo1.write(0); // set servo1 to 90 degrees
  servo2.write(0);


}

void loop() {
  int Mode_Button1 = digitalRead(Mode_Button);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(500);
  if (Mode_Button1 == 1) {
    digitalWrite(trigPin, LOW);  
	  delayMicroseconds(2);  
	  digitalWrite(trigPin, HIGH);  
	  delayMicroseconds(10);  
	  digitalWrite(trigPin, LOW); 
    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;
    Serial.print("Distance: ");
    Serial.println(distance);
    if (distance<=20){
      servo1.write(130); // set servo1 to 90 degrees
      servo2.write(130);
      digitalWrite(play, HIGH);
      delay(5000);
      digitalWrite(play, LOW);
      servo1.write(0); // set servo1 to 0 degrees
      servo2.write(0);
      delay(500);


    } else{
      digitalWrite(play, LOW);
      servo1.write(0); // set servo1 to 0 degrees
      servo2.write(0);

    }

  } else {
      servo1.write(90); 
      servo2.write(90);
    }


  
}