#include <unistd.h>

int ft_atoi(char *str)
{
	int n = 0;
	int char_val;

	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (-1);
		}
		char_val = *str - '0';
		n = n * 10;
		n = n + char_val;
		str++;
	}
	return (n);
}

void ft_putnum(int n)
{
	if (n > 9)
	{
		ft_putnum(n / 10);
	}
	n = n % 10;
	char c = '0' + n;
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	int n1 = ft_atoi(argv[1]);
	int n2 = ft_atoi(argv[2]);

	int candidate_gcd = n1;
	if (n2 < n1)
	{
		candidate_gcd = n2;
	}
	while(candidate_gcd > 0)
	{
		if (n1 % candidate_gcd == 0 && n2 % candidate_gcd == 0)
		{
			break;
		}
		candidate_gcd--;
	}
	ft_putnum(candidate_gcd);
	write(1, "\n", 1);
}
