#include "system.h"

volatile int timer_ticks = 0;


void timer_handler(struct regs *r)
{
    timer_ticks++;
}

void timer_install()

{
    irq_install_handler(0,(unsigned) timer_handler);
}


void timer_wait1(int ticks)
{
   unsigned long eticks;

    eticks = timer_ticks + ticks*18;
    (timer_ticks != eticks);
	__asm__ __volatile__("hlt");
}
void timer_wait(int ticks)
{
 
    volatile int i;
    for(i=0;i<ticks*500000000;i=i+1);
}
