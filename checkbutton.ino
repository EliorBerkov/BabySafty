
void checkBtn(uint16_t x, uint16_t y) {
  Serial.println("enter to check");
  if (x > 40 && x < 110 && y > 95 && y < 145)
   {Serial.println("screen2");
    screen2();}
  if (x > 200 && x < 270 && y > 95 && y < 145)
  {Serial.println("screen3");
    screen3();}
  if (x > 120 && x < 190 && y > 95 && y < 145)
  {Serial.println("screen4");
    screen4();}
}

