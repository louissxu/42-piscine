#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	a;
	char	z;

	a = 'a';
	z = 'z';
	while (a < z + 1)
	{
		write(1, &a, 1);
		a++;
	}
}
