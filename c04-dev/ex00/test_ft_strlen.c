#include <stdio.h>
#include "ft_strlen.c"
#include <string.h>

int main(void)
{
	char* s1 = "Hello World";
	printf("Test string is: %s\n", s1);
	printf("ft_strlen(s1): %d\n", ft_strlen(s1));
	printf("strlen(s1):    %lu\n", strlen(s1));
	printf("\n");

	char* s2 = "";
	printf("Test string is: %s\n", s2);
	printf("ft_strlen(s1): %d\n", ft_strlen(s2));
	printf("strlen(s1):    %lu\n", strlen(s2));
	printf("\n");

	char* s3 = "Hello World Testing something longer than the previous one";
	printf("Test string is: %s\n", s3);
	printf("ft_strlen(s1): %d\n", ft_strlen(s3));
	printf("strlen(s1):    %lu\n", strlen(s3));
	printf("\n");

	char* s4 = "Testing non letters 123abc!@#";
	printf("Test string is: %s\n", s4);
	printf("ft_strlen(s1): %d\n", ft_strlen(s4));
	printf("strlen(s1):    %lu\n", strlen(s4));
	printf("\n");

	char* s5 = "Fizz Buzz";
	printf("Test string is: %s\n", s5);
	printf("ft_strlen(s1): %d\n", ft_strlen(s5));
	printf("strlen(s1):    %lu\n", strlen(s5));
	printf("\n");
}

