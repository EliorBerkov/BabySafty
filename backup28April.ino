#include <SPI.h>
#include <TFT_eSPI.h>      // Hardware-specific library
#include <DHT.h>

#define DHT_PIN 27
#define PIR_MS 26
#define BUZZER_PIN 25

int state = LOW;             // by default, no motion detected
int val = 0;     // variable to store the sensor status (value)

#define DHT_TYPE DHT11
DHT dht (DHT_PIN, DHT_TYPE);
#define LABEL1_FONT &FreeSansOblique12pt7b // Key label font 1
#define LABEL2_FONT &FreeSansBold12pt7b    // Key label font 2
TFT_eSPI tft = TFT_eSPI(); // Invoke custom library

#define Led_Red 13
#define Led_Yellow 12
#define Led_Green 14

//------------------------------------------------------------------------------------------

void screen1();
void screen2();
void screen3();
void screen4();

void setup() {
  // Use serial port
  Serial.begin(115200);
  // Initialise the TFT screen
  tft.init();
  pinMode(PIR_MS, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);       // set ESP32 pin to output mode
  // Set the rotation to the orientation you wish to use in your project before calibration
  // (the touch coordinates returned then correspond to that rotation only)
  tft.setRotation(1);
 uint16_t calData[5] = { 320, 3409, 376, 3454, 3 };//{ 560, 3357, 314, 3438, 7 };//
  tft.setTouch(calData);
    // Clear the screen
  tft.fillScreen(TFT_WHITE);
  //tft.drawCentreString("Touch screen to test!",tft.width()/2, tft.height()/2, 2);
   screen1();

  dht.begin();

    pinMode(Led_Red, OUTPUT );
    pinMode(Led_Yellow, OUTPUT );
    pinMode(Led_Green, OUTPUT );

}



//------------------------------------------------------------------------------------------

void loop(void)
{
  uint16_t x = 0, y = 0; // To store the touch coordinates

  // Pressed will be set true is there is a valid touch on the screen
  bool pressed = tft.getTouch(&x, &y);

  // Draw a white spot at the detected coordinates
  if (pressed) {
    Serial.print("x,y = ");
    Serial.print(x);
    Serial.print(",");
    Serial.println(y);
    checkBtn(x,y);
  }

  float temperature = dht.readTemperature();                                
  float humidity = dht.readHumidity();
  
  //begin PIR MS
  val = digitalRead(PIR_MS);   // read sensor value
  if (val == HIGH){ // open if loop
    digitalWrite(Led_Red, HIGH); // turn on
    digitalWrite(BUZZER_PIN, HIGH); // turn on
    Serial.println("Suspicious Movement Detected!");
    delay(100);
  }
} // end void loop

 

