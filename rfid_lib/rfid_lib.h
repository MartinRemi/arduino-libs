#ifndef _rfid_lib_h
#define _rfid_lib_h

#include <SoftwareSerial.h>

class RFID {
	public :
		// Public member(s)
		
		// Public method(s)
		RFID(uint8_t enable, uint8_t sout);
		String getTag();
                void clean();
                
	private :
		// Private member(s)
		uint8_t enablePin;
		SoftwareSerial rfid;
		
		// Private method(s)
		void readSerial(String &ReadTagString);
};

#endif
