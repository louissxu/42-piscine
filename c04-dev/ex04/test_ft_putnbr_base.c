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
	
	printf("\nTesting: empty base\nAnswer: ");
	fflush(stdout);
	ft_putnbr_base(10, "");
	printf("\nCorrect answer: <nothing - 0 length base>\n");

	printf("\nTesting: 10, 1\nAnswer: ");
	fflush(stdout);
	ft_putnbr_base(10, "0");
	printf("\nCorrect answer: <nothing - 1 length base>\n");

	printf("\nTesting: 10, 0123456782\nAnswer: ");
	fflush(stdout);
	ft_putnbr_base(10, "0123456782");
	printf("\nCorrect answer: <nothing - repeated base char>\n");

	printf("\nTesting: 10, 0123+3456\nAnswer: ");
	fflush(stdout);
	ft_putnbr_base(10, "0123+456");
	printf("\nCorrect answer: <nothing - base contains + >\n");

	printf("\nTesting: 10, 0123-456\nAnswer: ");
	fflush(stdout);
	ft_putnbr_base(10, "0123-456");
	printf("\nCorrect answer: <nothing - base contains - >\n");

	printf("\nTesting: 1234567890, 123456!@#$\nAnswer: ");
	fflush(stdout);
	ft_putnbr_base(1234567890, "123456!@#$");
	printf("\nCorrect answer: 23456!@#$1\n");

}
