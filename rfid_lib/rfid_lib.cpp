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

  if(rfid.available() > 0) {
    if((val = rfid.read()) == 10) {
      bytesread = 0; 
      while(bytesread<10) { 
        if( rfid.available() > 0) { 
          val = rfid.read(); 
          if((val == 10)||(val == 13)) { 
            break;
          } 
          code[bytesread] = val;      
          bytesread++;
        } 
      } 
      if(bytesread == 10) {      

        for(int x=0;x<10;x++)    
        {
          TagCode += code[x];
        }
        ReadTagString = TagCode; 
        while(rfid.available() > 0)
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
