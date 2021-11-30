#include <stdio.h>
#include "ft_print_memory.c"

int main(void)
{
	char* a = "/bcdefg";
	unsigned int size = 34;
	ft_print_memory(a, size);
	return (1);
}

