//Writen by Dylan Dickson Nov. 27, 2020

int trigPin = 2; //Trigger pin on HC-SR04
int echoPin = 3; //Echo pin on HC-SR04
long duration;   //Variable for duration
int distance;    //Variable for distance
const int buzzer = A5;

void setup() {
  //Start serial communication
  Serial.begin(9600);
  
  //Set output pins
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
//Start main loop
  digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
//Calculate Centimeters away
 duration = pulseIn(echoPin, HIGH);
 distance = duration * .034 / 2;

//Print cm away
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);
  music(); // Goto music loop
}

void music() {
//Music loop

  //Middle C equivalent
  while(distance >= 2 || distance <= 4) { //Between 2 and 4cm
    sensing(); //Sensor loop
    tone(buzzer, 261.63);
 
    if (distance < 2 || distance > 4) {
      noTone(buzzer);
      break;
    } else if(distance > 30) {
      noTone(buzzer);
      break;
    }
  }
  
//D
  while(distance >= 5 || distance <= 7) {//Between 5 and 7cm
    sensing(); //Sensor loop
    tone(buzzer, 293.66);
 
    if (distance < 5 || distance > 7) {
      noTone(buzzer);
      break;
    } else if(distance > 30) {
      noTone(buzzer);
      break;
    }
  }
  
  //E
  while(distance >= 8 || distance <= 10) {//Between 8 and 10cm
    sensing(); //Sensor loop
    tone(buzzer, 329.63);
 
    if (distance < 8 || distance > 10) {
      noTone(buzzer);
      break;
    } else if(distance > 30) {
      noTone(buzzer);
      break;
    }
  }
  
  //F
  while(distance >= 11 || distance <= 13) {//Between 11 and 13cm
    sensing(); //Sensor loop
    tone(buzzer, 349.23);
 
    if (distance < 11 || distance > 13) {
      noTone(buzzer);
      break;
    } else if(distance > 30) {
      noTone(buzzer);
      break;
    }
  }
  
  //G
  while(distance >= 14 || distance <= 16) {//Between 14 and 16cm
    sensing(); //Sensor loop
    tone(buzzer, 392.00);
 
    if (distance < 14 || distance > 16) {
      noTone(buzzer);
      break;
    } else if(distance > 30) {
      noTone(buzzer);
      break;
    }
  }
  
  //A
  while(distance >= 17 || distance <= 19) {//Between 17 and 19cm
    sensing(); //Sensor loop
    tone(buzzer, 440.00);
 
    if (distance < 17 || distance > 19) {
      noTone(buzzer);
      break;
    } else if(distance > 30) {
      noTone(buzzer);
      break;
    }
  }
}


void sensing() {
  //Setup sensing so it can go in while loop
  
  digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

//Calculation
 duration = pulseIn(echoPin, HIGH);
 distance = duration * .034 / 2;



}
