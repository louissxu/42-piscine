char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	int src_i;
	int dest_i;

	dest_i = 0;
	while (dest[dest_i])
	{
		dest_i++;
	}
	src_i = 0;
	while (src[src_i] && nb)
	{
		dest[dest_i + src_i] = src[src_i];
		src_i++;
		nb--;
	}
	dest[dest_i + src_i] = '\0';
	return (dest);
}
