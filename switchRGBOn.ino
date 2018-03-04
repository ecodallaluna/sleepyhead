
void switchRGBOn(int humidity){
  
  //case 1
  if(humidity <= 30){
    RGB[0]=222; 
    RGB[1]=22; 
    RGB[2]=11;
    analogWrite(redLed,RGB[0]);
    analogWrite(greenLed,RGB[1]);
    analogWrite(blueLed,RGB[2]);
  }

  //case 2
  else if(humidity > 30 && humidity <= 35){
    RGB[0]=227; 
    RGB[1]=104; 
    RGB[2]=43;
    analogWrite(redLed,RGB[0]);
    analogWrite(greenLed,RGB[1]);
    analogWrite(blueLed,RGB[2]);
  }

  //case 3
  else if(humidity > 35 && humidity <= 40){
    RGB[0]=247; 
    RGB[1]=182; 
    RGB[2]=62;
    analogWrite(redLed,RGB[0]);
    analogWrite(greenLed,RGB[1]);
    analogWrite(blueLed,RGB[2]);
  }

  //case 4
  else if(humidity > 40 && humidity <= 45){
    RGB[0]=247; 
    RGB[1]=247; 
    RGB[2]=62;
    analogWrite(redLed,RGB[0]);
    analogWrite(greenLed,RGB[1]);
    analogWrite(blueLed,RGB[2]);
  }

  //case 5
  else if(humidity > 45 && humidity <= 50){
    RGB[0]=245; 
    RGB[1]=245; 
    RGB[2]=186;
    analogWrite(redLed,RGB[0]);
    analogWrite(greenLed,RGB[1]);
    analogWrite(blueLed,RGB[2]);
  }


  //case 5
  else if(humidity > 50 && humidity <= 55){
    RGB[0]=186; 
    RGB[1]=245; 
    RGB[2]=245;
    analogWrite(redLed,RGB[0]);
    analogWrite(greenLed,RGB[1]);
    analogWrite(blueLed,RGB[2]);
  }


  //case 6
  else if(humidity > 55 && humidity <= 60){
    RGB[0]=91; 
    RGB[1]=188; 
    RGB[2]=240;
    analogWrite(redLed,RGB[0]);
    analogWrite(greenLed,RGB[1]);
    analogWrite(blueLed,RGB[2]);
  }

  //case 7
  else if(humidity > 60 && humidity <= 65){
    RGB[0]=31; 
    RGB[1]=104; 
    RGB[2]=222;
    analogWrite(redLed,RGB[0]);
    analogWrite(greenLed,RGB[1]);
    analogWrite(blueLed,RGB[2]);
  }

  //case 8
  else if(humidity > 65 && humidity <= 70){
    RGB[0]=15; 
    RGB[1]=27; 
    RGB[2]=191;
    analogWrite(redLed,RGB[0]);
    analogWrite(greenLed,RGB[1]);
    analogWrite(blueLed,RGB[2]);
  }

  //case 9
  else if(humidity > 70){
    RGB[0]=27; 
    RGB[1]=3; 
    RGB[2]=87;
    analogWrite(redLed,RGB[0]);
    analogWrite(greenLed,RGB[1]);
    analogWrite(blueLed,RGB[2]);
  }
}

