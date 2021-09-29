#include <LCD_I2C.h>
#define l_button 5
#define r_button 4

#define DISABLED 0
#define LEFT -1
#define RIGHT 1

LCD_I2C lcd(0x27);

int side = DISABLED;

unsigned long time_left = 300000;
unsigned long time_right = 300000;

unsigned long last_time = 0;

void setup()
{
    lcd.begin();
    lcd.backlight();
    pinMode(l_button, INPUT_PULLUP);
    pinMode(r_button, INPUT_PULLUP);
    lcd.setCursor(0, 0);
    lcd.print("Melina Krzemowa");
    lcd.setCursor(5, 1);
    lcd.print("CHESS CLOCK");
    delay(2000);
    lcd.clear();
}

void loop()
{
  controls();
  count_time();
  display_clocks();
}

void controls() 
{
  // TODO: Add resetting by pressing both buttons
   
  if (digitalRead(l_button) == LOW && side != LEFT) {
    side = LEFT;
    last_time = millis();
  }
  else if (digitalRead(r_button) == LOW && side != RIGHT) {
    side = RIGHT;
    last_time = millis();
  }
}

void count_time()
{
  if (side == LEFT) {
    time_left -= millis() - last_time;
    last_time = millis();
  }

  if (side == RIGHT) {
    time_right -= millis() - last_time;
    last_time = millis();
  }
}

void display_clocks()
{
//  String str_left = String(time_left, DEC);
  
  lcd.setCursor(0,0);  
  lcd.print(time_left);

  lcd.setCursor(10, 0);
  lcd.print(time_right);
}
