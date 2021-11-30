#include "ft_strncat.c"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[] = "Hello";
	char b[] = "World";
	
	ft_strncat(b, a, 2);
	printf("Result is: %s\n", b);
}
