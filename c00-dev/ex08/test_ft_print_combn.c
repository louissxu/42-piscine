#include "ft_print_combn.c"
#include <stdio.h>

void ft_print_combn(int n);

int main(void)
{
	printf("Testing ft_print_combn(0)\n");
	printf("-------------------------\n");
	ft_print_combn(0);
	
	printf("\n");
	printf("Testing ft_print_combn(1)\n");
	printf("-------------------------\n");
	ft_print_combn(1);
	printf("\n");

	printf("Testing ft_print_combn(2)\n");
	printf("-------------------------\n");
	ft_print_combn(2);
	printf("\n");
	
	printf("Testing ft_print_combn(3)\n");
	printf("-------------------------\n");
	ft_print_combn(3);
	printf("\n");

	printf("Testing ft_print_combn(4)\n");
	printf("-------------------------\n");
	ft_print_combn(4);
	printf("\n");
	
	printf("Testing ft_print_combn(9)\n");
	printf("-------------------------\n");
	ft_print_combn(9);
	printf("\n"); 
	
	printf("Testing ft_print_combn(10)\n");
	printf("-------------------------\n");
	ft_print_combn(10);
	printf("\n"); 
}
