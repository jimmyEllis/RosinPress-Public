void SetupLCD(void) {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(200); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  display.display();
  delay(200);
}
void writeDoubleToDisplay(double txt, int size, int col, int row, bool inv, int places) {

  display.setTextSize(size);      // Normal 1:1 pixel scale
  if (inv) {
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  }
  else {
    display.setTextColor(SSD1306_WHITE); // Draw white text
  }
  display.setCursor(col,row);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  display.println(String(txt,places));



}

void writeTextToDisplay(String txt, int size, int col, int row, bool inv) {

  display.setTextSize(size);      // Normal 1:1 pixel scale
  if (inv) {
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  }
  else {
    display.setTextColor(SSD1306_WHITE); // Draw white text
  }
  display.setCursor(col, row);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  display.println(txt);



}
