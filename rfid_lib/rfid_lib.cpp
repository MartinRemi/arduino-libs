#include "Arduino.h"
#include "rfid_lib.h"

RFID::RFID(uint8_t enable, uint8_t sout) : 
	rfid(sout, 20),
	enablePin(enable) 
	{
		rfid.begin(2400);
		pinMode(enable, OUTPUT);
		digitalWrite(enable, LOW);
	}

void RFID::readSerial(String &ReadTagString)
{
  int bytesread = 0;
  int  val = 0; 
  char code[10];
  String TagCode="";

  if(rfid.available() > 0) {          // If data available from reader 
    if((val = rfid.read()) == 10) {   // Check for header 
      bytesread = 0; 
      while(bytesread<10) {                 // Read 10 digit code 
        if( rfid.available() > 0) { 
          val = rfid.read(); 
          if((val == 10)||(val == 13)) {   // If header or stop bytes before the 10 digit reading 
            break;                         // Stop reading 
          } 
          code[bytesread] = val;           // Add the digit           
          bytesread++;                     // Ready to read next digit  
        } 
      } 
      if(bytesread == 10) {                // If 10 digit read is complete 

        for(int x=0;x<10;x++)              //Copy the Chars to a String
        {
          TagCode += code[x];
        }
        ReadTagString = TagCode;          //Update the caller
        while(rfid.available() > 0) //Burn off any characters still in the buffer
        {
          rfid.read();
        }
      } 
      bytesread = 0;
      TagCode="";
    } 
  } 
}

String RFID::getTag() {
    String tag="";
    if(rfid.available()) {
	     readSerial(tag);
    }
    return tag;
}

void RFID::clean() {
  while(rfid.available() > 0) //Burn off any characters still in the buffer
  {
    rfid.read();
  }
}
