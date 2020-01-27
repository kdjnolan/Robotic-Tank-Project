void ChooseMode()
{
  //delay(500);
  int potTemp = analogRead(pot);      
  delay(10);
  Serial.print("Potentiometer Value: ");
  Serial.println(potTemp);
  if( potTemp > 850 )                           //Avoider
  {
    mode = 0;
  }
  if( potTemp < 850 && potTemp > 250 )//bluetooth
  {
    mode = 1;
  }
  if( potTemp < 250 )                   //programmer
  {
    mode = 2;
  }
}

