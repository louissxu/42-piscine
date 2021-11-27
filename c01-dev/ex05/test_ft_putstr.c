#include "ft_putstr.c"
#include <stdio.h>

int main(void)
{
	char test_string[] = "Hello World!\n";
	printf("Running ft_put_str with \"Hello World!\\n\"");
	ft_putstr(test_string);
}
