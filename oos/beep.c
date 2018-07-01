#include "system.h" 
#include "stdint.h" 
 static void play_sound(uint32_t nFrequence) 
  {
 	uint32_t Div;
 	uint8_t tmp;
	Div = 1193180 / nFrequence;
 	outportb(0x43, 0xb6);
 	outportb(0x42, (uint8_t) (Div) );
 	outportb(0x42, (uint8_t) (Div >> 8));
 	tmp = inportb(0x61);
  	if (tmp != (tmp | 3)) 
	{
 		outportb(0x61, tmp | 3);
	}
  }
 
 static void nosound() {
 	uint8_t tmp = inportb(0x61) & 0xFC;
 
 	outportb(0x61, tmp);
 }
 
 void beep(uint32_t nFrequence,int time ) {
 	 play_sound(nFrequence);
 	 timer_wait(time);
 	 nosound();
 }


