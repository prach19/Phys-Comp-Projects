// C++ code
//
uint8_t btn_prev;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  btn_prev = digitalRead(2);
}

// the loop function runs over and over again forever
void loop() {

  cali();
  delay(100);
  float temp = analogRead(A0);
  float roomTemp = ((temp * (5.0/1024.0)) - 0.5) * 100;
  Serial.print("temp: ");
  Serial.println(roomTemp);
  
  if(roomTemp < 10){
    float cold =  map(roomTemp,-10, 10, 255, 0);
    Serial.print(" cold: ");
    Serial.println(cold);
    analogWrite(3, cold);
    
  }
  else if(roomTemp > 12 && roomTemp < 25 ){
    float warm = map(roomTemp, 15, 25, 0, 255);
    //Serial.print("warm: ");
    //Serial.println(warm);
    analogWrite(5, warm);
    //analogWrite(3, 0);
    
  }
 
  
  else if(roomTemp >= 25){
    float warmer = map(roomTemp, 25, 30, 255, 0);
    analogWrite(5, warmer);
    float hot = map(roomTemp, 25, 40, 0, 255);
    analogWrite(6, hot);
    //analogWrite(3, 0);
    //Serial.print("hot: ");
    //Serial.println(hot);
  }

}

void cali(){
  if (digitalRead(2) == LOW && btn_prev == HIGH)
  {
    for (int i = 0; i < 4; i++){
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(3, LOW);
      delay(500);
      digitalWrite(5, LOW);
      delay(500);
      digitalWrite(6, LOW);
      delay(500);
    }
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      
  }
  btn_prev = digitalRead(2);

}

//map temp to light, or use temp to identify a bulb
//use pwm to identify the intensity of that temperature
//when button pressed, "recalibrate" -> take few seconds to check temp, lights blink while this happens

  
