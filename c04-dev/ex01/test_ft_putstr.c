#include "ft_putstr.c"
#include <stdio.h>

int main(void)
{
	char* s1 = "Hello";
	printf("Test string: %s\n", s1);
	ft_putstr(s1);
	printf("\n\n");

	char* s2 = "Hello World";
	printf("Test string: %s\n", s2);
	ft_putstr(s2);
	printf("\n\n");

	char* s3 = "Hello World testing something longer";
	printf("Test string: %s\n", s3);
	ft_putstr(s3);
	printf("\n\n");

	char* s4 = "Other characters 123!@#abc";
	printf("Test string: %s\n", s4);
	ft_putstr(s4);
	printf("\n\n");

	char* s5 = "Fizz Buzz";
	printf("Test string: %s\n", s5);
	ft_putstr(s5);
	printf("\n");

}
