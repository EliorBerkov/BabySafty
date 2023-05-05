 
void screen1() // start screen1
{
  tft.fillScreen(TFT_PURPLE);
  
  tft.fillRect(40, 95, 70, 50, TFT_ORANGE);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("Led",60 ,110 );
  
  tft.fillRect(200, 95, 70, 50, TFT_ORANGE);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("T&H",210 ,110 );

  tft.fillRect(120, 95, 70, 50, TFT_ORANGE);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("M-S",137 ,110 );

}

