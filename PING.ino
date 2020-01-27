//PING sensor functions
long ping() {
pinMode(pingPin, OUTPUT);    //Pingpin is an output
digitalWrite(pingPin, LOW);  //Send a low pulse
delayMicroseconds(2);        //wait for 2microseconds
digitalWrite(pingPin, HIGH); //send a high pulse
delayMicroseconds(5); 
digitalWrite(pingPin, LOW); 
pinMode(pingPin,INPUT);      //switch Pingpin to input
duration = pulseIn(pingPin, HIGH); //listen for the echo
//inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);
}
//conversions
long microsecondsToInches(long microseconds) {
return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds) {
return microseconds / 29 / 2;
}

