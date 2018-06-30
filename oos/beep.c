#include "system.h" 
#include "stdint.h" 
//Play sound using built in speaker
//proba da li radiiii
 static void play_sound(uint32_t nFrequence) {
 	uint32_t Div;
 	uint8_t tmp;
 
        //Set the PIT to the desired frequency
 	Div = 1193180 / nFrequence;
 	outportb(0x43, 0xb6);
 	outportb(0x42, (uint8_t) (Div) );
 	outportb(0x42, (uint8_t) (Div >> 8));
 
        //And play the sound using the PC speaker
 	tmp = inportb(0x61);
  	if (tmp != (tmp | 3)) {
 		outportb(0x61, tmp | 3);
 	}
 }
 
 //make it shutup
 static void nosound() {
 	uint8_t tmp = inportb(0x61) & 0xFC;
 
 	outportb(0x61, tmp);
 }
 
 //Make a beep
 void beep(uint32_t nFrequence ) {
 	 play_sound(nFrequence);
 	 timer_wait(1);//duzina trajanja note
 	 nosound();
          //set_PIT_2(old_frequency);
 }


