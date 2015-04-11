#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>


int main()
{
	char i,j;

	for (i = 'H'; i >= 'A'; i--) 
		{
		for (j = i; j >= 'A'; j--) 
			printf("%c", j);
		printf("\n");
		}

	return(0);
}
