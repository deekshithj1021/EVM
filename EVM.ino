#include <LiquidCrystal.h>

// LCD module connections (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
const int buzzerPin = 13; 

boolean x1 = false;
boolean x2 = false;
boolean x3 = false;
boolean x4 = false;

void setup() {
  // Set the button pins as INPUT
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

  // Set the buzzer pin as OUTPUT
  pinMode(buzzerPin, OUTPUT);

  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.print("PLEASE VOTE");
  Serial.begin(9600);
}

void loop() {
  // Check for votes
  if (digitalRead(buttonPin1) == HIGH) {
    while (digitalRead(buttonPin1) == HIGH) {
    }
    x1 = true;
    activateBuzzer(); // Turn on the buzzer for 1 second
  }

  if (digitalRead(buttonPin2) == HIGH) {
    while (digitalRead(buttonPin2) == HIGH) {
    }
    x2 = true;
    activateBuzzer(); // Turn on the buzzer for 1 second
  }

  if (digitalRead(buttonPin3) == HIGH) {
    while (digitalRead(buttonPin3) == HIGH) {
    }
    x3 = true;
    activateBuzzer(); // Turn on the buzzer for 1 second
  }

  if (digitalRead(buttonPin4) == HIGH) {
    while (digitalRead(buttonPin4) == HIGH) {
    }
    x4 = true;
    activateBuzzer(); // Turn on the buzzer for 1 second
  }

  // Display votes and corresponding symbols
  if (x1 == true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("VOTED FOR PARTY1");
    x1 = false;
    Serial.println("*");
    delay(3000); // Wait for 3 seconds
  }

  if (x2 == true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("VOTED FOR PARTY2");
    x2 = false;
    Serial.println("#");
    delay(3000); // Wait for 3 seconds
  }

  if (x3 == true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("VOTED FOR PARTY3");
    x3 = false;
    Serial.println("$");
    delay(3000); // Wait for 3 seconds
  }

  if (x4 == true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("VOTED FOR NOTA");
    x4 = false;
    Serial.println("&");
    delay(3000); // Wait for 3 seconds
  }

  // Show "PLEASE VOTE" message if no vote is being displayed
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PLEASE VOTE");

  // Wait for a short delay to avoid flickering
  delay(200);
}

void activateBuzzer() {
  digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
  delay(1000); // Wait for 1 second
  digitalWrite(buzzerPin, LOW); // Turn off the buzzer
}
