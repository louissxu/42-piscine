#include <stdio.h>
#include "ft_putnbr_base.c"

int main(void)
{
	printf("Testing: 19, 01\nAnswer: ");
	fflush(stdout);
	ft_putnbr_base(19, "01");
	printf("\nCorrect answer: 10011\n");

	printf("\nTesting: 78786, 0123456789\nAnswer: ");
	fflush(stdout);
	ft_putnbr_base(79786, "0123456789");
	printf("\nCorrect answer: 78786\n");

	printf("\nTesting: 15678925, 0123456789abcdef\nAnswer: ");
	fflush(stdout);
	ft_putnbr_base(15678925, "0123456789abcdef");
	printf("\nCorrect answer: ef3dcd\n");

	printf("\nTesting: -31, 0123456789abcdef\nAnswer: ");
	fflush(stdout);
	ft_putnbr_base(-31, "0123456789abcdef");
	printf("\nCorrect answer: -1f\n");

	printf("\nTesting: 0, 0123456789\nAnswer: ");
	fflush(stdout);
	ft_putnbr_base(0, "0123456789");
	printf("\nCorrect answer: 0\n");
}
