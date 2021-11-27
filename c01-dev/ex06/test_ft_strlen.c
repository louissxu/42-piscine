#include <stdio.h>
#include "ft_strlen.c"

int main(void)
{
	int result = 0;
	result = ft_strlen("Hello World");
	printf("Testing ft_strlen with \"Hello World\". Result is %d. Should be 11\n", result);
	result = ft_strlen("Test");
	printf("Testing ft_strlen with \"Test\". Result is %d. Should be 4\n", result);
}		
