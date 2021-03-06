 #ifndef __SYSTEM_H
#define __SYSTEM_H
#include "stdint.h"
struct regs
{
    unsigned int gs, fs, es, ds;      
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  
    unsigned int int_no, err_code;    
    unsigned int eip, cs, eflags, useresp, ss;   
};

/* MAIN.C */
extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
extern int strlen(const char *str);
extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);
extern void play_music();

/* CONSOLE.C */
extern void init_video();
extern void cls();
extern void putch(unsigned char c);
extern void puts(unsigned char *str);

/* GDT.C */
extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
extern void gdt_install();

/* IDT.C */
extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
extern void idt_install();

/* ISRS.C */
extern void isrs_install();

/* IRQ.C */
extern void irq_install();
extern void irq_install_handler(int irq, void (*handler)(struct regs *r));
extern void irq_uninstall_handler(int irq);

/* TIMER.C */
extern void timer_install();
extern void timer_wait(int ticks);

/* KEYBOARD.C */
extern void keyboard_install();

/*BEEP.C*/
extern void beep(uint32_t nFrequence,int time);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);

#endif
	
