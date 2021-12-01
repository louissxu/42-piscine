#include <stdio.h>
#include "ft_atoi.c"

int main(void)
{
	char* s1 = "";
	printf("Testing: %s\n", s1);
	printf("Result: %d\n\n", ft_atoi(s1));

	char* s2 = "abc";
	printf("Testing: %s\n", s2);
	printf("Result: %d\n\n", ft_atoi(s2));

	char* s3 = "123";
	printf("Testing: %s\n", s3);
	printf("Result: %d\n\n", ft_atoi(s3));

	char* s4 = "    12345";
	printf("Testing: %s\n", s4);
	printf("Result: %d\n\n", ft_atoi(s4));

	char* s5 = "-1";
	printf("Testing: %s\n", s5);
	printf("Result: %d\n\n", ft_atoi(s5));

	char* s6 = "-+--12345";
	printf("Testing: %s\n", s6);
	printf("Result: %d\n\n", ft_atoi(s6));

	char* s7 = "    -+-+-12345abc";
	printf("Testing: %s\n", s7);
	printf("Result: %d\n\n", ft_atoi(s7));
}
