#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "z\n", 2);
		return (0);
	}
	while (*argv[1])
	{
		if (*argv[1] == 'z')
		{
			write(1, argv[1], 1); 
			write(1, "\n", 1);
			return (0);
		}
		argv[1]++;
	}
	write(1, "z\n", 2);
	return (0);
}
