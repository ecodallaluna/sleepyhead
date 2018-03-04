void waterPump(int humidity){

//case 1
  if(humidity > 30 && humidity <= 40){

    for (int i = 0; i <3; i++){
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(150);              // wait for a second
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    delay(2000);              // wait for a second
    }
  }

  //case 2
  else if(humidity > 40 && humidity <= 50){

    for (int i = 0; i <6; i++){
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(150);              // wait for a second
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);              // wait for a second
    }
  }

  //case 3
  else if(humidity > 50){

    for (int i = 0; i <8; i++){
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(150);              // wait for a second
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    delay(200);              // wait for a second
    }
  }
  
}

