#include "ft_strncmp.c"
#include <string.h>
#include <stdio.h>

int main(void)
{
	printf("-------------------");
	printf("Using inbult strncmp\n");
	printf("Comparing \"Hello\" and \"Hello\": %d\n", strncmp("Hello", "Hello", 3));	
	printf("Comparing \"Hello\" and \"World\": %d\n", strncmp("Hello", "World", 3));
	printf("Comparing \"123\" and \"1234\": %d\n", strncmp("123", "1234", 4));
	printf("Comparing \"321\" and \"123\": %d\n", strncmp("321", "123", 3));
	printf("Comparing \"!@#\" and \"123\": %d\n", strncmp("!@#", "123", 3));

	printf("-------------------");
	printf("Using ft_strncmp\n");
	printf("Comparing \"Hello\" and \"Hello\": %d\n", ft_strncmp("Hello", "Hello", 3));	
	printf("Comparing \"Hello\" and \"World\": %d\n", ft_strncmp("Hello", "World", 3));
	printf("Comparing \"123\" and \"1234\": %d\n", ft_strncmp("123", "1234", 4));
	printf("Comparing \"321\" and \"123\": %d\n", ft_strncmp("321", "123", 3));
	printf("Comparing \"!@#\" and \"123\": %d\n", ft_strncmp("!@#", "123", 3));
}
