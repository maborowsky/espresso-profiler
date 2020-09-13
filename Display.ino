/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/


 
void displaySetup() {
  // Start I2C Communication SDA = 5 and SCL = 4 on Wemos Lolin32 ESP32 with built-in SSD1306 OLED
  Wire.begin(5, 4);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
}

void displayText(String txt) {
  displayText(txt, 1);
}

void displayText(String txt, int textSize) {
  // Clear the buffer.
  display.clearDisplay();
  
  // Display static text
  display.setTextSize(textSize);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  
  display.println(txt);
  
  display.display();
}

void displayLoadCellSensors() {
  displayText("A3: " + String(analogRead(3)) + "\nA10: " + analogRead(10));
}

void displayTouchSensors() {
  displayText("T0: " + String(touchRead(T0)) + " "  +
              "T1: " + String(touchRead(T1)) + "\n" +
              "T2: " + String(touchRead(T2)) + " "  +
              "T3: " + String(touchRead(T3)) + "\n" +
              "T4: " + String(touchRead(T4)) + " "  +
              "T5: " + String(touchRead(T5)) + "\n" +
              "T6: " + String(touchRead(T6)));
}
