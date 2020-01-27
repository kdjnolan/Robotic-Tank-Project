//Functions for movement
void Stop() {               //Stops the motors
  leftMotor->run(RELEASE);  //Turns off Lmotor
  rightMotor->run(RELEASE); //Turns off Rmotor
  Serial.println("Stop");   //Prints a line in the serial monitor
}
void Forward() {            // Makes tank go forward
  leftMotor->setSpeed(150); //set the initial speed of motors
  rightMotor->setSpeed(155);
  leftMotor->run(FORWARD);  // Lmotor goes forward
  rightMotor->run(FORWARD); // Rmotor goes forward
  Serial.println("Forward");// Prints a line in the serial monitor
}
void FullSpeed() {            // Makes tank go forward
  uint8_t i;
  
  leftMotor->setSpeed(150);   //set the initial speed of motors
  rightMotor->setSpeed(155);
  leftMotor->run(FORWARD);    // Lmotor goes forward
  rightMotor->run(FORWARD);   // Rmotor goes forward
  Serial.println("FullSpeed");// Prints a line in the serial monitor
  for( i=0 ; i<255 ; i++ ){
   leftMotor->setSpeed(i);
   rightMotor->setSpeed(i); 
  }
}
void Reverse(){             //puts tank into reverse
  leftMotor->setSpeed(150); //set the initial speed of motors
  rightMotor->setSpeed(155);
  rightMotor->run(BACKWARD);
  leftMotor->run(BACKWARD);
  delay(1400);
  Serial.println("Backward"); 
}
void Right() {              //Makes tank go right
  Serial.println("Turning Right");  //Prints a line in the serial monitor
  digitalWrite(rightInd , HIGH );
  leftMotor->setSpeed(150); //set the initial speed of motors
  rightMotor->setSpeed(155);
  rightMotor->run(BACKWARD);//Rmotor back
  leftMotor->run(FORWARD);  //Lmotor forward
  delay(990);               //Time needed to turn right 
  digitalWrite(rightInd , LOW );
}
void Left() {               //tank turns left
  Serial.println("Turning Left");
  digitalWrite(leftInd , HIGH );
  leftMotor->setSpeed(150); //set the initial speed of motors
  rightMotor->setSpeed(155);
  rightMotor->run(FORWARD);
  leftMotor->run(BACKWARD);
  delay(990);
  digitalWrite(leftInd , LOW );
}
void sRight() {             //Makes tank go right
  leftMotor->setSpeed(150); //set the initial speed of motors
  rightMotor->setSpeed(155);
  rightMotor->run(BACKWARD);//Rmotor back
  leftMotor->run(FORWARD);  //Lmotor forward
  delay(495);               //Time needed to turn right 
  Serial.println("Motors going sRight");    //Prints a line in the serial monitor
}
void sLeft() {              //tank turns left
  leftMotor->setSpeed(150); //set the initial speed of motors
  rightMotor->setSpeed(155);
  rightMotor->run(FORWARD);
  leftMotor->run(BACKWARD);
  delay(495);
  Serial.println("Motors going sLeft");
}
void Do180() {              // Makes the robot do a 180 deg turn
  leftMotor->setSpeed(150); //set the initial speed of motors
  rightMotor->setSpeed(155);//
  rightMotor->run(BACKWARD);// Turns motor 2 in reverse
  leftMotor->run(FORWARD);  // Motor 1 goes forward
  delay(2000);              // Time required to do 180 deg turn
  Serial.println("180");    //Prints a line in the serial monitor
}
