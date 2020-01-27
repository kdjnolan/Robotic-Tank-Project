//If this mode is chosen the tank will act as a obstacle avoidance robot
void avoidanceTank()
{
  LDR();
  Ccm = checkRoute();
  Serial.print("\ncm:\t"); //Prints dist from the object detected
  Serial.print(cm);
  Serial.println();

  if( Ccm == true )//0    //forward IF object is over 20cm 
  {
    Forward();             //wheels forward
    delay(110);           
    //checkRoute();
  }
  else                     //ELSE IF under 20cm Stop And Look
  {
    Stop();
    FarLeftRight();  
    if (FarLeftDist>FarRightDist && FarLeftDist>minSafeDist)
    {
      Left();
    }
    else if (FarLeftDist<FarRightDist && FarRightDist>minSafeDist)
    {
      Right();
    }
    else
    {
      Reverse();
      Do180();
    }
  }
}


