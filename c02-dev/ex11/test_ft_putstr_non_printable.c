#include <stdio.h>
#include "ft_putstr_non_printable.c"

int main(void)
{
	printf("Printing: \"Hello ~ World\"\n");
	printf("Result  : ");
	fflush(stdout);
	ft_putstr_non_printable("Hello ~ World");
	printf("\n");

	printf("Printing: \"Line \\n break\"\n");
	printf("Re  \\0a : ");
	fflush(stdout);
	ft_putstr_non_printable("Line \n break");
	printf("\n");

	printf("Printing: \"Horizontal \\t tab\"\n");
	printf("Re  \\09 : ");
	fflush(stdout);
	ft_putstr_non_printable("Horizontal \t tab");
	printf("\n");

	printf("Printing: \"Null \\0 char\"\n");
	printf("Re  \\00 : ");
	fflush(stdout);
	ft_putstr_non_printable("Null \0 char");
	printf("\n");
	
	char all_chars[128];
	char a = '~';
	while (a)
	{
		all_chars[(int)a] = a;
		a--;
	}
	all_chars[0] = '~' + 1;
	all_chars[127] = '~' + 1;
	all_chars[127] = '\0';
	ft_putstr_non_printable(all_chars);

}
