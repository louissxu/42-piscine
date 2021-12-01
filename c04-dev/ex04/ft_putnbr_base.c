void	string_okay(char* str)
{
	int i;
	while (*str)
	{
		if (*str == '-' || *str == '+')
		{
			return (0);
		}
		i = 0;
		while(str[i])
		{
			if (str[i] == *str)
			{
				return (0);
			}
		}
		str++;
	}
	if (i <= 1)
	{
		return (0);
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
