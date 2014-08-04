#include "buzzer_lib.h"
#include "arduino.h"

Buzzer::Buzzer(int pin) :
	pinNode(pin)
{
	
}
	
void Buzzer::melodyTone(int notes[], int durations[], int arraySize) {
    for(int i = 0; i < arraySize; i++) {
	noteTone(notes[i], durations[i]);
    }
}

void Buzzer::noteTone(int note, int duration) {
    duration = 1000/duration;
    tone(pinNode, note, duration);
    
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(pinNode);
}
