#include "ft_strcmp.c"
#include <string.h>
#include <stdio.h>

int main(void)
{
	printf("-------------------");
	printf("Using inbult strcmp\n");
	printf("Comparing \"Hello\" and \"Hello\": %d\n", strcmp("Hello", "Hello"));	
	printf("Comparing \"Hello\" and \"World\": %d\n", strcmp("Hello", "World"));
	printf("Comparing \"123\" and \"1234\": %d\n", strcmp("123", "1234"));
	printf("Comparing \"321\" and \"123\": %d\n", strcmp("321", "123"));
	printf("Comparing \"!@#\" and \"123\": %d\n", strcmp("!@#", "123"));
	printf("Comparing \"abcdef\" and \"abcdefghijklb\": %d\n", strcmp("abcdef", "abcdefghijklb"));
	char *s1 = "hello";
	char *s2 = "world";
	printf("Comparing \"%s\" and \"%s\": %d\n", s1, s2, strcmp(s1, s2));
	

	printf("-------------------");
	printf("Using ft_strcmp\n");
	printf("Comparing \"Hello\" and \"Hello\": %d\n", ft_strcmp("Hello", "Hello"));	
	printf("Comparing \"Hello\" and \"World\": %d\n", ft_strcmp("Hello", "World"));
	printf("Comparing \"123\" and \"1234\": %d\n", ft_strcmp("123", "1234"));
	printf("Comparing \"321\" and \"123\": %d\n", ft_strcmp("321", "123"));
	printf("Comparing \"!@#\" and \"123\": %d\n", ft_strcmp("!@#", "123"));
	printf("Comparing \"%s\" and \"%s\": %d\n", s1, s2, ft_strcmp(s1, s2));
}
