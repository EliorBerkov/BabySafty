
void screen2() //Screen 2!
{
  tft.fillScreen(TFT_BLACK);
  tft.fillRect(20, 25, 80, 50, TFT_RED);      // RED
   tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
 
  tft.drawString("Red",40 ,45 );
  //==============================

  tft.fillRect(120, 25, 80, 50, TFT_YELLOW);   // yellow
   tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
 
  tft.drawString("Yellow",125 ,45 );
  //==============================

  tft.fillRect(220, 25, 80, 50, TFT_GREEN);    // green
   tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
 
  tft.drawString("Green",230 ,45 );
  
  //==============================
                                                                     // on button
  tft.fillRect(20, 105, 80, 35, TFT_RED);      // RED
   tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
                                               
  tft.drawString("ON",50 ,115 );
  //==============================

  tft.fillRect(120, 105, 80, 35, TFT_YELLOW);   // yellow
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
 
  tft.drawString("ON",150 ,115);
  //==============================

  tft.fillRect(220, 105, 80, 35, TFT_GREEN);    // green
   tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
 
  tft.drawString("ON",250 ,115);
  //==============================
  

  //RED STROKE
  tft.fillRect(10, 85, 100, 5, TFT_RED);
  tft.fillRect(10, 200, 100, 5, TFT_RED);
  tft.fillRect(10, 85, 5, 115, TFT_RED);
  tft.fillRect(105, 85, 5, 115, TFT_RED);

  //YELLOW STROKE
  tft.fillRect(110, 85, 100, 5, TFT_YELLOW);
  tft.fillRect(110, 200, 100, 5, TFT_YELLOW);
  tft.fillRect(110, 85, 5, 115, TFT_YELLOW);
  tft.fillRect(205, 85, 5, 115, TFT_YELLOW);

  //GREEN STROKE
  tft.fillRect(210, 85, 100, 5, TFT_GREEN);
  tft.fillRect(210, 200, 100, 5, TFT_GREEN);
  tft.fillRect(210, 85, 5, 115, TFT_GREEN);
  tft.fillRect(305, 85, 5, 115, TFT_GREEN);
  //==============================
                                                                     // off button
  tft.fillRect(20, 150, 80, 35, TFT_RED);      // RED
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
                                               
  tft.drawString("OFF",45 ,160 );
  //==============================

  tft.fillRect(120, 150, 80, 35, TFT_YELLOW);   // yellow
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
 
  tft.drawString("OFF",145 ,160);
  //==============================

  tft.fillRect(220, 150, 80, 35, TFT_GREEN);    // green
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
 
  tft.drawString("OFF",245 ,160);

  //==============================
  
  tft.fillRect(20, 215, 80, 50, TFT_WHITE);     //Back to Screen 1
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
 
  tft.drawString("Back",40 ,220 );

  //========================
    
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
  }  
     if (x>20 && x<100 && y>105 &&y<140)
     digitalWrite(Led_Red, HIGH) ;              
//=========================================================== red off
     if (x>20 && x<100 && y>150 &&y<185)
     digitalWrite(Led_Red, LOW);
//=========================================================== yellow on 
     if (x>120 && x<200 && y>105 &&y<140)
     digitalWrite(Led_Yellow, HIGH);
//=========================================================== yellow off
     if (x>120 && x<200 && y>150 &&y<185)
     digitalWrite(Led_Yellow, LOW);
//=========================================================== green on  
     if (x>220 && x<300 && y>105 &&y<140)
     digitalWrite(Led_Green, HIGH);
//=========================================================== green off
     if (x>220 && x<300 && y>150 &&y<185)
     digitalWrite(Led_Green, LOW);
//=========================================================== traffic_light
    
 } // End of "Do" loop
 
  while (!((x>220 && x<300 && y>215 && y<265) || (x>20 && x<100 && y>215 && y<265)));
   if (x>20 && x<100 && y>215 && y<265){ // goes to screen 1 from screen 2
      screen1();
   }
   
    delay(1000);
} //End of screen 2a

