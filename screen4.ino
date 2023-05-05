

void screen4() // start screen4
{
  bool flag=false;
  
  tft.fillScreen(TFT_YELLOW);

  //======================================
  tft.fillRect(20, 215, 80, 50, TFT_WHITE);     //Back to Screen 1
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
 
  tft.drawString("Back",40 ,220 );
  
  //======================================
  
  uint16_t x = 0, y = 0; // To store the touch coordinates
  do{
  bool pressed = tft.getTouch(&x, &y);

  // Draw a white spot at the detected coordinates
  if (pressed) {
    Serial.print("x,y = ");
    Serial.print(x);
    Serial.print(",");
    Serial.println(y);
    //checkBtn(x,y);
  } // end if
 
  tft.fillRect(80, 95, 150, 50, TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.drawString("Stop Alarm",100 ,110 );
  
  if (x>120&& x<200 && y>95 && y<145 && flag==false){
     digitalWrite(Led_Yellow, LOW); //turn off
     digitalWrite(Led_Red, LOW); //turn off
     digitalWrite(BUZZER_PIN, LOW);  // turn off
     Serial.println("Alarm stopped");
     delay(200);
     flag = true;
  }
 } // end do loop
 
   while (! (x>20 && x<100 && y>215 && y<265));
   if (x>20 && x<100 && y>215 && y<265) // goes to screen 1 from screen 4
   flag=false; // restarts the ability to alart suspicious movement
      screen1();

      delay(1000);
} // end screen 4
