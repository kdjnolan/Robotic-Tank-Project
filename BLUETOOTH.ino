//If bluetooth mode is chosen, this will loop.
//Allows user to control tank with an android phone through bluetooth. The name of the bluetooth app is "Bluetooth RC Controller"

void bluetooth()
{
  det = check();                //get the serial code
  switch (det)                  //switch depending on the serial code recieved
  {
    case 'F':                   //'F' moves forward
      rightMotor->setSpeed(vel);//sets the speed
      leftMotor->setSpeed(vel);
      leftMotor->run(FORWARD);  //Lmotor goes forward
      rightMotor->run(FORWARD); //Rmotor goes forward
      Serial.println("Forward");
      det = check();
      break;
    
    case 'B':                          //move back
      rightMotor->setSpeed(vel);
      leftMotor->setSpeed(vel);
      rightMotor->run(BACKWARD);
      leftMotor->run(BACKWARD);
      Serial.println("Backward");
      det = check();
      break;
    
    case 'L':                          //move left
      rightMotor->setSpeed(vel);
      leftMotor->setSpeed(vel/4);
      rightMotor->run(FORWARD);
      leftMotor->run(BACKWARD);

      digitalWrite(leftInd, HIGH);
      Serial.println("turning  Left");
      det = check();
      break;
    
    case 'R':                          //move right
      rightMotor->setSpeed(vel/4);
      leftMotor->setSpeed(vel);
      rightMotor->run(BACKWARD);      
      leftMotor->run(FORWARD);

      digitalWrite(rightInd, HIGH);
      Serial.println("turning right");
      det = check();
      break;
    
    case 'I':                          //turn right while moving forward
      rightMotor->setSpeed(vel/2);
      leftMotor->setSpeed(vel);
      rightMotor->run(FORWARD);      
      leftMotor->run(FORWARD);
      det = check();
      break;
    
    case 'J':                          //turn right back
      rightMotor->setSpeed(vel/2);
      leftMotor->setSpeed(vel);  
      rightMotor->run(BACKWARD);     
      leftMotor->run(BACKWARD);
      det = check();
      break;
    
    case 'G':                          //turn left forward
      rightMotor->setSpeed(vel);
      leftMotor->setSpeed(vel/2);
      rightMotor->run(FORWARD);      
      leftMotor->run(FORWARD);
      det = check();
      break;
    
    case 'H':                          //turn left moving back
      rightMotor->setSpeed(vel);
      leftMotor->setSpeed(vel/2);  
      rightMotor->run(BACKWARD);     
      leftMotor->run(BACKWARD);
      det = check();
      break;
    
    case 'S':                          //stop
      rightMotor->setSpeed(vel);
      leftMotor->setSpeed(vel);
      leftMotor->run(RELEASE);         //Turns off motor
      rightMotor->run(RELEASE); 
      det = check();
      break;
      
    //Horn & Lights
    case 'V':                          //Horn On
      Serial.println("Horn On");
      tone(horn, 200, 100);
      det = check();
      break;
    
    case 'v':                          //Horn Off
      Serial.println("Horn Off");
      noTone(horn);
      det = check();
      break;
    
    case 'W':                          //Front Lights On
      Serial.println("Head Lights On");
      digitalWrite(headLights, HIGH);
      det = check();
      break;
    
    case 'w':                          //Front Lights Off
      Serial.println("Head Lights Off");    
      digitalWrite(headLights, LOW);
      det = check();
      break;

    case 'U':                          //tail Lights On
      Serial.println("tail Lights On");
      digitalWrite(tailLights, HIGH);
      delay(100);
      det = check();
      break;
    
    case 'u':                          //tail Lights Off
      Serial.println("tail Lights Off");    
      digitalWrite(tailLights, LOW);
      delay(100);
      det = check();
      break;

   case 'X':                           //hazards On
      Serial.println("Hazards On");
      digitalWrite(leftInd, HIGH);
      digitalWrite(rightInd, HIGH);
      delay(400);
      digitalWrite(rightInd, LOW);
      digitalWrite(leftInd, LOW);
      delay(400);
      det = check();
      break;
    
   case 'x':                            //hazards Off
      Serial.println("hazards Off");    
      digitalWrite(rightInd, LOW);
      digitalWrite(leftInd, LOW);
      det = check();
      break;
  }
}

//function that returns the bluetooth code received from serial port
int check()
{
  if (Serial.available() > 0)   //if there is valid data in the serial port
  { 
    dataIn = Serial.read();     //store the data into a variable called dataIN
    if (dataIn == 'F'){//Forward
      determinant = 'F';
    }
    else if (dataIn == 'B'){//Backward
      determinant = 'B';
    }
    else if (dataIn == 'L'){//Left
      determinant = 'L';
    }
    else if (dataIn == 'R'){//Right
      determinant = 'R';
    }
    else if (dataIn == 'I'){//Froward Right
      determinant = 'I';
    }
    else if (dataIn == 'J'){//Backward Right
      determinant = 'J';
    }
    else if (dataIn == 'G'){//Forward Left
      determinant = 'G';
    }    
    else if (dataIn == 'H'){//Backward Left
      determinant = 'H';
    }
    else if (dataIn == 'S'){//Stop
      determinant = 'S';
    }
    else if (dataIn == '0'){//Speed 0
      vel = 0;
    }
    else if (dataIn == '1'){//Speed 25
      vel = 25;
    }
    else if (dataIn == '2'){//Speed 50
      vel = 50;
    }
    else if (dataIn == '3'){//Speed 75
      vel = 75;
    }
    else if (dataIn == '4'){//Speed 100
      vel = 100;
    }
    else if (dataIn == '5'){//Speed 125
      vel = 125;
    }
    else if (dataIn == '6'){//Speed 150
      vel = 150;
    }
    else if (dataIn == '7'){//Speed 175
      vel = 175;
    }
    else if (dataIn == '8'){//Speed 200
      vel = 200;
    }
    else if (dataIn == '9'){//Speed 225
      vel = 225;
    }
    else if (dataIn == 'q'){//Speed 255
      vel = 255;
    }
    else if (dataIn == 'U'){//Back Lights On
      determinant = 'U';
    }
    else if (dataIn == 'u'){//Back Lights Off
      determinant = 'u';
    }
    else if (dataIn == 'W'){//Front Lights On
      determinant = 'W';
    }
    else if (dataIn == 'w'){//Front Lights Off
      determinant = 'w';
    }
    else if (dataIn == 'V'){//Horn On
      determinant = 'V';
    }
    else if (dataIn == 'v'){//Horn Off
      determinant = 'v';
    }
    else if (dataIn == 'X'){//Hazards On
      determinant = 'X';
    }
    else if (dataIn == 'x'){//Hazards Off
      determinant = 'x';
    }
  }
  return determinant;
}

