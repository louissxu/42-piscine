#include <unistd.h>

void ft_print_numbers(void)
{
	int num;
	int end;

	num = '0';
	end = '9';
	while (num <= end)
	{
		write(1, &num, 1);
		num++;
	}
}
