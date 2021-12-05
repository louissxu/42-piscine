#include "header.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int return_value;
	
	if (argc != 2)
	{
		write(2, "Usage ./solve_puzzle \"<constraints\"", 20);
		return (1);
	}

	printf("\n\n================\nSTARTING\n================\n");
	printf("The constraint string is %s\n", argv[1]);
	//return_value = bf_solve_puzzle(argv[1]);
	return_value = bt_solve_puzzle(argv[1]);
	printf("The final return value is %d\n", return_value);
	return (return_value);
}
