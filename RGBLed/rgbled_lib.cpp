#include "rgbled_lib.h"
#include "arduino.h"

RGBLed::RGBLed(int RedPin, int GreenPin, int BluePin) :
	redPin(RedPin),
	greenPin(GreenPin),
	bluePin(BluePin)
	{
		// The three pins of rgb led, used for OUTPUT
		pinMode(redPin, OUTPUT);
		pinMode(greenPin, OUTPUT);
		pinMode(bluePin, OUTPUT);
		
		set(0, 0, 0);
	}
	
void RGBLed::set(int redValue, int greenValue, int blueValue) {
	setRed(redValue);
	setGreen(greenValue);
	setBlue(blueValue);
}

void RGBLed::setRed(int redValue) {
	analogWrite(redPin, redValue);
}

void RGBLed::setGreen(int greenValue) {
	analogWrite(greenPin, greenValue);
}

void RGBLed::setBlue(int blueValue) {
	analogWrite(bluePin, blueValue);
}
