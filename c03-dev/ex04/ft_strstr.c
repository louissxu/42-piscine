int	is_match(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (1);
}

char	*ft_strstr(char *str, char*to_find)
{
	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str)
	{
		if (is_match(str, to_find))
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
