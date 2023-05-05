
void screen3()
{
  tft.fillScreen(TFT_BLACK);
  tft.fillRect(20, 215, 80, 50, TFT_WHITE);     //Back to Screen 1
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
 
  tft.drawString("Back",40 ,220 );

  //========================
  
   uint16_t x = 0, y = 0; // To store the touch coordinates
  do{
  // Pressed will be set true is there is a valid touch on the screen
  bool pressed = tft.getTouch(&x, &y);

  // Draw a white spot at the detected coordinates
  if (pressed) {
    Serial.print("x,y = ");
    Serial.print(x);
    Serial.print(",");
    Serial.println(y);
    //checkBtn(x,y);

    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(2);
  }
  
  float temperature = dht.readTemperature();                                
  float humidity = dht.readHumidity();
  tft.setCursor(0, 0);
  tft.print("Temperature: ");
  tft.print(temperature);
  tft.print(" C");
  tft.setCursor(0, 30);
  tft.print("Humidity: ");
  tft.print(humidity);
  tft.print("%");
  delay(200);
  tft.fillRect(0, 0, 850, 100, TFT_BLACK);
  
  }

// ..........................................................................................................................................
  while (!((x>20 && x<100 && y>215 && y<265)));
  //220, 215, 80, 50
    if (x>20 && x<100 && y>215 && y<265)
      screen1();
//if (x>220 && x<300 && y>215 && y<265)
//screen2();
    delay(2000);
  }

