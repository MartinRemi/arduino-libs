#ifndef _rgbled_lib_h
#define _rgbled_lib_h

class RGBLed {
	public :
		// Public member(s)
		
		// Public method(s)
		RGBLed(int redPin, int greenPin, int bluePin);
		void set(int redValue, int greenValue, int blueValue);
		void setRed(int redValue);
		void setGreen(int greenValue);
		void setBlue(int blueValue);
	private :
		// Private member(s)
		int redPin;
		int greenPin;
		int bluePin;
		
		// Private method(s)
};

#endif