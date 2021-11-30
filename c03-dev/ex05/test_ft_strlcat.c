#include <stdio.h>
#include "ft_strlcat.c"

int main(void)
{
	char a[] = "Birds";
	char b[] = "World Hams";
	unsigned int result = ft_strlcat(b, a, 4);
	printf("String: %s    Return: %u\n", b, result);

}

