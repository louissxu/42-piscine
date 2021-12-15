#include <unistd.h>

int main(int argc, char **argv)
{
	char *str = argv[1];
	
	if (argc != 2)
	{
		write(1, "a\n", 2);
		return (0);
	}
	while (*str)
	{
		if (*str == 'a')
		{
			write(1, str, 1);
			write(1, "\n", 1);
			return (0);
		}
		str++;
	}
	write(1, "a\n", 2);
	return (0);
}

