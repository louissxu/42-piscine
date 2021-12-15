#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(void)
{
	int i = 0;
	char c;

	while (i < 26)
	{
		c = 'a' + i;
		if (i % 2 == 1)
		{
			c = c - 'a' + 'A';
		}
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
