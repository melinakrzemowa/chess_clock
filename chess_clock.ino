#include <LCD_I2C.h>
#define l_button 5
#define r_button 4

LCD_I2C lcd(0x27);

int side = 0;

void setup()
{
    lcd.begin();
    lcd.backlight();
     pinMode(l_button, INPUT_PULLUP);
      pinMode(r_button, INPUT_PULLUP);
}

void loop()
{
    if (digitalRead(l_button) == LOW) {
      side = 0;
    }
    else if (digitalRead(r_button) == LOW) {
      side = 1;
    }

    if (side == 0) {
      lcd.setCursor(0, 0);
      lcd.print("left");
    } else if (side ==1) {
      lcd.print("right");
    }
    delay(100);
    lcd.clear();
}
