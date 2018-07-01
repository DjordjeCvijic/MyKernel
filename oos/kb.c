
unsigned char kbdus[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};

void keyboard_handler(struct regs *r)
{
    unsigned char scancode;
    scancode = inportb(0x60);

    if (scancode & 0x80)
    {
        
    }
    else
    {
        if(kbdus[scancode]=='2')
        play_music();

        if(kbdus[scancode]=='1')
        {  
          cls();
           puts("If you want to leave, press 0.\n");
          puts("Now you can play:\n");
         
        }
        if(kbdus[scancode]=='a')
        {
           puts("c ");
          beep(261,0.2);
        }
        if(kbdus[scancode]=='w')
        {
         puts("c-up,d-down ");
         beep(277,0.2);
        }
         if(kbdus[scancode]=='s')
        {
          puts("d ");
          beep(293,0.2);
        }
         if(kbdus[scancode]=='e')
        {
          puts("d-up,e-down ");
          beep(311,0.2);

        }
        if(kbdus[scancode]=='d')
        {
          puts("e ");
          beep(329,0.2);
        }
        if(kbdus[scancode]=='f')
        {
          puts("f ");
          beep(349,0.2);
         
        }
        if(kbdus[scancode]=='t')
        {
          puts("f-up,g-down ");
          beep(369,0.2);
         
        }if(kbdus[scancode]=='g')
        {
          puts("g ");
          beep(391,0.2);
         
        }
        if(kbdus[scancode]=='y')
        {
          puts("g-up,a-down ");
          beep(415,0.2);
         
        }
        if(kbdus[scancode]=='h')
        {
          puts("a ");
          beep(440,0.2);
         
        }
        if(kbdus[scancode]=='u')
        {
         puts("a-up,b-down ");
          beep(466,0.2);
         
        }
        if(kbdus[scancode]=='j')
        {
          puts("b ");
          beep(493,0.2);
         
        }
        if(kbdus[scancode]=='k')
        {
          puts("c ");
          beep(523,0.2);
         
        }
        if(kbdus[scancode]=='0')
        {
          meni();
         
        }
        


        
    }
}

void keyboard_install()
{
    irq_install_handler(1, keyboard_handler);
}	
