//the refresher.
//checks the switch whether to do Safari refresh (CMD+R) or refresh for any other browser (F5)

bool MAC = false;

//pin configuration on the cheap-o-china boards is weird.. 14 and 16 are right next to each other .. meh...

const int input_pin = 16;
const int output_pin = 14;

void setup()
{

  pinMode(input_pin, INPUT_PULLUP);
  pinMode(output_pin, OUTPUT);

  digitalWrite(output_pin, LOW);

  Keyboard.begin();

  delay(2500);

}

void loop()
{
  //if the button is pressed
  if(digitalRead(input_pin)==LOW) MAC = true;
  else MAC=false;

  if(MAC)
  {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
  }
  else Keyboard.press(KEY_F5);

  delay(100); //a little delay to make sure the keypresses are recognized by the computer... better safe than sorry...

  Keyboard.releaseAll();

  delay(5000); /*  <---- This is measured in milliseconds, so 5000 is 5 seconds :) */

}