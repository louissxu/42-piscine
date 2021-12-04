#include "header.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int return_value;

	if (argc != 2)
	{
		write(2, "Usage ./solve_puzzle \"<constraints>\"", 20);
		return (1);
	}
	else
	{
		return_value = solve_puzzle(argv[1]);
		return (return_value);
	}
}
