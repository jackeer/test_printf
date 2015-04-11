
#include "REG51.H"

#include "stdio.h"
#include "stdarg.h"

#include "STRING.H"


void Uart_init(void)
{
	SCON |= 0x50;				// Set to enable serial reception. 8-bit UART Variable
	TMOD |= 0x20;				// Timer 1 Mode 2: 8-bit auto-reload Timer/Counter (TL1).(1)Reloaded from TH1 at overflow.
	TH1 = 0xFA;					// 9600 bauds at 11.0592 MHz
	TL1 = TH1; 
	PCON |= 0x80;				// SMOD0 Set to select double baud rate in mode 1, 2 or 3.
	TCON |= 0x40;				// Set to turn on Timer/Counter 1.   
	TI=1;						// Set by hardware at the end of the 8th bit time in mode 0 or at the beginning of the 
								// stop bit in the other modes.
}

void put_char (const char *tmp) large
{

	int i = 0;

	while((tmp[i] != NULL) && (tmp[i] != EOF)&& (tmp[i] != '\n'))
		{
		SBUF = tmp[i];

		TI=0;

		while(!TI);
		
		i ++;
		}
}

void put_char_args(char *arg1, ...) large
{
	va_list ap;
	char *str, rent='\n';
	// char temp[3]=0;

	va_start(ap, arg1);
	str = arg1;

	// sprintf(temp, "%s", sizeof(arg1));
	// put_char(temp), put_char(&rent);

	// printf("%s\n", arg1);

	do{
		put_char(str), put_char(&rent);
		// printf("%s\n", str);

		str = va_arg(ap, char *);
		// str=str-1;

	} while((*str != NULL) && (*str != EOF));
	
	va_end(ap);

	put_char(&rent);
}

void main(void) large
{
	code char *tmp_str ="Hello World!";

	Uart_init();
	ES=1;			// Serial Port interrupt enable bit.

	// put_char(tmp_str);
	put_char_args("This test Variadic templates", tmp_str, "test", "4", "5", "6", "7", "8", "9");

	while(1);
}



