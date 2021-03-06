#include"system.h"

unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count)
{
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for(; count != 0; count--) *dp++ = *sp++;
    return dest;
}

unsigned char *memset(unsigned char *dest, unsigned char val, int count)
{
    char *temp = (char *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, int count)
{
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


unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}


void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}


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
     return n.frequence[i];
    

}
void install()
{
    gdt_install();
	idt_install();
	isrs_install();
	irq_install();
    keyboard_install();
    init_video();
	timer_install();
    __asm__ __volatile__ ("sti"); /* dozvoljava da se interapt moze desiti */
}
void meni()
{
    cls();
    puts("Wellcome\n\n");
    puts("If you want to play, press 1.\n");
    puts("If you want to hear the music, press 2.\n");
}

void play_music()
{
    struct notes n={{{"c"},{"c-up,d-down"},{"d"},{"d-up,e-down"},{"e"},{"f"},{"f-up,g-down"},{"g"},{"g-up,a-down"},{"a"},{"a-up,b-down"},{"b"},{"c1"}},
                    {261,277,293,311,329,349,369,391,415,440,466,493,523}};
    struct melody m={{{"e"},{"a"},{"d-up,e-down"},{"e"},{"g"},{"a"},{"d"},{"g"},{"g-up,a-down"},{"d"},{"e"},{"f"},{"c"},{"f-up,g-down"},},
                    {3,2,1,1,2,1,2,2,1,1,2,1,1,2, }};
    m.lenght=14;
	
	cls();
   int i;
    for(i=0;i<m.lenght;i++)
    {
        puts("  ");
        puts(m.m_notes[i]);
        beep(return_freq(m.m_notes[i],n),m.time[i]);
        
    }
        puts("\nSong is over.\n");
        timer_wait(4);
     cls();
    meni();
}

void main()
{   
    install();
  
   meni();
    for (;;);
}
