#include <stdio.h>
#include <stdarg.h>


void put_char_args(char *arg1, ...)
{
	va_list ap;
	char *str;

	va_start(ap, arg1);
	str = arg1;
	// printf("%d\n", sizeof(arg1));

	while((str[0] != '\0') && (str[0] != EOF))
		{
		printf("%s\n", str);
		str = va_arg(ap, char *);
		} 

	va_end(ap);

}

int main()
{
	char *tmp_str ="Hello World!" ;

	put_char_args("This test Variadic templates", tmp_str, "test", "4", "5", "6", "7", "8", "9");

	return(0);
}


