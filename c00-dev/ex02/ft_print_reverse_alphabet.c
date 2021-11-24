#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
	char a;
	char z;

	a = 'a';
	z = 'z';

	while (z >= a)
	{
		write(1, &z, 1);
		z--;
	}
}

