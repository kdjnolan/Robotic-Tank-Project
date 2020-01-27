/********************************
Name: Karl Nolan
Description: This Project is a toy tank that is being controlled 
by an Arduino and AdafruitV2 Motorshield.
It has 3 modes of operation:
  1. Programmer Mode (do nothing, MAYBE FLASH/TURN ON A LED TO INDICATE WHAT MODE IT IS IN)
  2. Android Bluetooth Controlled
  3. Obstacle Avoidance Robot
********************************/
/*    Pins used: 
(A0-ping) (A1-LDR) (A2-POT) (A3- ) (A4- ) (A5- )
(D0&D1-blueT)  (D2&D3-lftRInd)  D4-  D5-  D6- (D7&D8-F&Tlights)  D9- D10-servo D11-piezo D12- D13md
*///////////////////////////////
//#include "Ultrasonic.h"
#include <Servo.h>                                 //Enables Servo library
#include <Wire.h>                                  //MotorShieldV2 libs
#include <Adafruit_MotorShield.h>                  //MotorShieldV2 libraries
#include "utility/Adafruit_MS_PWMServoDriver.h"    //MotorShieldV2 libs
Adafruit_MotorShield AFMS = Adafruit_MotorShield();//Create motor shield object with default I2C address
Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);   //Rmotor on port M4
Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);    //Lmotor on port M2

//variables for pings and distances
const int pingPin = A0;                   //Ping sensor is connected to port A0
int minSafeDist = 25, Clear = 40 ;        //Minimum distance for ping sensor to know when to turn
int centerDist, leftDist, rightDist, FarLeftDist, FarRightDist; // Define variables center, left, right and back distance
long duration, inches, cm, Ccm;           //Define variables for Ping sensor

//vars for light sensor
const int sensorPin = A1;    //LDR shit...
int sensorValue = 0;         //initialise to zero

//Potentiometer
const int pot = A2;  //POT attached to Pin(analog)2

//Constants and variable used in Bluetooth controlled tank
//bluetooth shite
char dataIn = 'S';   //declares dataIn as char, initialises to S (stop)
char determinant;    //determines what key was recieved(function's variable)
char det;            //determinant used in switch
int vel ;            //will determine speed

//LEDs and horn
int headLights = 7; //headlights attached to Pin 8
int tailLights = 8; //tailights attached to Pin 7
int leftInd =    2; //left turn indicator  
int rightInd =   3; //right indicator
int horn =       11;//piezo element attached to pin2
int modeIndicatorLED = 13;

int mode;            //variable to store the set mode
Servo servo1;        //servo library


void setup() 
{
  Serial.begin(9600);          //initialize serial communication:
  AFMS.begin();                //create with the default frequency 1.6KHz
  leftMotor->setSpeed(0);      //set the initial speed of motors(OFF in this case)
  rightMotor->setSpeed(0);
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  pinMode(headLights, OUTPUT);  //All LEDs and speaker are outputs
  pinMode(tailLights, OUTPUT); 
  pinMode(leftInd, OUTPUT);
  pinMode(rightInd, OUTPUT);
  pinMode(horn, OUTPUT);
  pinMode(modeIndicatorLED, OUTPUT);
  digitalWrite(headLights, LOW);//Write zero to all LEDs and speaker 
  digitalWrite(tailLights, LOW); 
  digitalWrite(leftInd, LOW);
  digitalWrite(rightInd, LOW);
  digitalWrite(modeIndicatorLED, LOW);
  servo1.attach(10);// Attach a servo to pin #10
  servo1.write(90);// servo straight ahead position
  Serial.println("Bluetooth and Sonar Tank Test");

  ChooseMode();

  tone(horn, 3000, 300);
  delay(100);
  noTone(horn);
  delay(200);
  tone(horn, 3000, 400);
  delay(100);
  noTone(horn);
  delay(200);
  tone(horn, 3000, 600);
  delay(500);
  noTone(horn);

}

void loop()
{ 
  
  if( mode == 0 ){                            //Obstacle avoider mode
    Serial.println("Obstacle Avoider Mode");
    avoidanceTank();
    digitalWrite(modeIndicatorLED, LOW);
  }
  if( mode == 1 ){                            //Bluetooth mode
    
    Serial.println("Bluetooth Mode");
    bluetooth();
    digitalWrite(modeIndicatorLED, HIGH);

    ///delay(20000);
  }
  if( mode == 2 ){                            //Programming mode
    Serial.println("Programming Mode");
    delay(500);                               //delay
    digitalWrite(leftInd, HIGH);
    digitalWrite(rightInd, HIGH);
    digitalWrite(headLights, HIGH);
    digitalWrite(tailLights, HIGH);
    digitalWrite(modeIndicatorLED, HIGH);
    delay(750);
    digitalWrite(leftInd, LOW);
    digitalWrite(rightInd, LOW);
    digitalWrite(headLights, LOW);
    digitalWrite(tailLights, LOW);
    digitalWrite(modeIndicatorLED, LOW);
  }  
  ChooseMode();
}

