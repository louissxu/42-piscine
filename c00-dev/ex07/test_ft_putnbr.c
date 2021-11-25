#include <stdio.h>
#include <unistd.h>

void ft_putnbr(int nb);

int main(void)
{
	printf("-Test case- | -Returned answer-\n");
	write(1, "0           | ", 14);
	ft_putnbr(0);
	printf("\n");

	write(1, "3           | ", 14);
	ft_putnbr(3);
	printf("\n");	
	
	write(1, "10          | ", 14);
	ft_putnbr(10);
	printf("\n");
	
	write(1, "42          | ", 14);
	ft_putnbr(42);
	printf("\n");
	
	write(1, "-1          | ", 14);
	ft_putnbr(-1);
	printf("\n");
	
	write(1, "-42         | ", 14);
	ft_putnbr(-42);
	printf("\n");
	
	write(1, "2147483647  | ", 14);
	ft_putnbr(2147483647);
	printf("\n");
	
	write(1, "-2147483648 | ", 14);
	ft_putnbr(-2147483648);
	printf("\n");
}
