void LDR(){
  sensorValue = analogRead(sensorPin);//take reading from the sensor and store the value
  Serial.print("LDR's Value is: \t"); //print
  Serial.print(sensorValue);          //prints values from sensor
  if(sensorValue < 300)               //set darkness threshold
  {
    digitalWrite(headLights,HIGH);   //turn lights ON if its dark
    digitalWrite(tailLights,HIGH);   //turn lights ON if its dark
  }
  else 
  {
    digitalWrite(headLights,LOW);    //turn lights OFF if bright
    digitalWrite(tailLights,LOW);    //turn lights OFF if bright
  }
}
