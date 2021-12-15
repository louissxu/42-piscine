int ft_strlen(char *str)
{
	int count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

void ft_swap(char *c1, char *c2)
{
	char tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

char *ft_strrev(char *str)
{
	int str_len = ft_strlen(str);
	int i = 0;

	while (i < str_len / 2)
	{
		ft_swap(&str[i], &str[str_len - 1 - i]);
		i++;	
	}
	return (str);
}
