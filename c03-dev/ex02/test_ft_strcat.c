#include "ft_strcat.c"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[] = "Hello";
	char b[] = "World";
	
	ft_strcat(b, a);
	printf("Result is: %s\n", b);
}
