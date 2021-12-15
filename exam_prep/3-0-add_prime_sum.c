#include <unistd.h>
#include <stdio.h>

int is_prime(int n)
{
	if (n < 2)
	{
		return (0);
	}	
	int i = 2;
	while (i * i <= n && i < 46341)
	{
		if (n % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int ft_atoi(char *str)
{
	int n = 0;
	int digit_val;

	while(*str)
	{
		if (*str > '9' || *str < '0')
		{
			return (0);
		}
		digit_val = *str - '0';
		n = n * 10;
		n = n + digit_val;
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
	char c = n % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	
	int n = ft_atoi(argv[1]);

	int i = 0;
	int sum = 0;

	while (i <= n)
	{
		if (is_prime(i))
		{
			sum += i;
		}
		i++;
	}
	ft_putnum(sum);
	write(1, "\n", 1);
}
