//Functions that use the servo to look in different directions and compare/save readings.

void LookAhead() //Unused at d mo...
{
  servo1.write(90);// angle to look forward
  delay(175); // wait 0.175 seconds
  ping();
  centerDist = cm; //get the center distance
}
bool checkRoute()
{
  servo1.write(135);      // angle (right)
  delay(160);             // wait 0.16 seconds
  ping();
  rightDist = cm;         //get the right distance
  servo1.write(45);       // look to the other side
  delay(320);             // wait 0.62 seconds
  ping();
  leftDist = cm;          // get the left distance
  servo1.write(90);       // 90° angle
  delay(160);             // wait 0.275 seconds
  centerDist = cm;        // get the c distance
  if (leftDist < minSafeDist || rightDist < minSafeDist || centerDist < minSafeDist)
    return false;//obstacle
  else
    return true;//obstacle free
  //Ccm = (leftDist + rightDist + centerDist)/3;

  //Prints following serial monitor
  Serial.print("RightDist: ");
  Serial.println(rightDist);
  Serial.print("LeftDist: ");
  Serial.println(leftDist);
  Serial.print("CenterDist: ");
  Serial.println(centerDist);
}

void FarLeftRight()
{   //check 90 degrees left and right
  servo1.write(180);    // 180° angle (right)
  delay(320);           // wait 0.32 seconds
  ping();
  FarRightDist = cm;    //get the right distance
  servo1.write(0);      // look to the other side
  delay(640);           // wait 0.62 seconds
  ping();
  FarLeftDist = cm;     // get the left distance
  servo1.write(90);     // 90° angle
  delay(320);           // wait 0.275 seconds

  // Prints following serial monitor
  Serial.print("FarRightDist: ");
  Serial.println(FarRightDist);
  Serial.print("FarLeftDist: ");
  Serial.println(FarLeftDist);
}
