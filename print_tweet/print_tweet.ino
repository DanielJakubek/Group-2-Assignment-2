/*
    Non web print tweet, remade version of get_tweet made to work on TinkerCad
    has a hard coded tweet
    Made by Sameer Al Harbi
    with code from Tinkercad
    v1.0.0
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String tweet = "";
String oldTweet = "";

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Loading Tweet...");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  if(getTweet()==false)
  {
    lcd.print(millis() / 1000);
  }
}
 
boolean getTweet()
{
  //Huzzah specific code to get tweet here
  tweet = "test tweet";
  if(oldTweet!=tweet)
  {
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print(tweet);
  }
  oldTweet = tweet;
  return true;
}
