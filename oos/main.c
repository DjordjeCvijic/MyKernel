#include"system.h"

/* You will need to code these up yourself!  */
unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count)
{
    /* Add code here to copy 'count' bytes of data from 'src' to
    *  'dest', finally return 'dest' */
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for(; count != 0; count--) *dp++ = *sp++;
    return dest;
}

unsigned char *memset(unsigned char *dest, unsigned char val, int count)
{
    /* Add code here to set 'count' bytes in 'dest' to 'val'.
    *  Again, return 'dest' */
    char *temp = (char *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, int count)
{
    /* Same as above, but this time, we're working with a 16-bit
    *  'val' and dest pointer. Your code can be an exact copy of
    *  the above, provided that your local variables if any, are
    *  unsigned short */
    unsigned short *temp = (unsigned short *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;

}

int strlen(const char *str)
{
    int len=0;
	for(len;*str!='\0';len++,str++);
	return len;
}

/* We will use this later on for reading from the I/O ports to get data
*  from devices such as the keyboard. We are using what is called
*  'inline assembly' in these routines to actually do the work */
unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

/* We will use this to write to I/O ports to send bytes to devices. This
*  will be used in the next tutorial for changing the textmode cursor
*  position. Again, we use some inline assembly for the stuff that simply
*  cannot be done in C */
void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

/* This is a very simple main() function. All it does is sit in an
*  infinite loop. This will be like our 'idle' loop */
int strcmp(char a[], char b[])
{
   int c = 0;
 
   while (a[c] == b[c]) {
      if (a[c] == '\0' || b[c] == '\0')
         break;
      c++;
   }
 
   if (a[c] == '\0' && b[c] == '\0')
      return 0;
   else
      return -1;
}
typedef struct notes
{
    char *names[13];
    int frequence[13];

};
typedef struct melody
{
    char*m_notes[30];
    int time[30];
    int lenght;
};
int return_freq(char *a,struct notes n)
{
    int i=0;
    while(strcmp(a,n.names[i]) && i<15) i++;
    if(i<15) return n.frequence[i];
    return 0;

}
void main()
{   
    struct notes n={{{"c"},{"c-up,d-down"},{"d"},{"d-up,e-down"},{"e"},{"f"},{"f-up,g-down"},{"g"},{"g-up,a-down"},{"a"},{"a-up,b-down"},{"b"},{"c1"}},
                    {261,277,293,311,329,349,369,391,415,440,466,493,523}};

    struct melody m={{{"e"},{"a"},{"c"},{"e"},{"g"},{"a"},{"d"},{"g"},{"c"},{"d"},{"e"},{"f"},{"c"},{"g"},{"e"},{"a"},{"c1"},{"e"},{"d"},{"a"}},
                    {1,1,2,1,1,2,1,1,1,0.5,4,2,2,2,0.5,1,1,1,0.25,0.25 }};
    m.lenght=20;
	gdt_install();
	idt_install();
	isrs_install();
	irq_install();
    keyboard_install();
    init_video();
	timer_install();
	__asm__ __volatile__ ("sti"); /* dozvoljava da se interapt moze desiti */
   int i;
    for(i=0;i<m.lenght;i++)
    {
        timer_wait(0.2);//pauza izmedju svake note
        beep(return_freq(m.m_notes[i],n));

    }
    
	
	/*('a');
	timer_wait(18*4);
      	puts(" kraaalj\n");
	putch('t');*/
    for (;;);
}
