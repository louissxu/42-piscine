unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	j = 0;
	while (src[j] && (j < size))
	{
		dest[i+j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + j);
}
