#include <stdio.h>
#include "ft_convert_base.c"
#include "ft_convert_base2.c"

int main(void)
{
	char* return_val =  ft_convert_base("7b", "0123456789abcdef", "01");
	printf("Testing 7b (hex) -> (binary). Expects: 1111011. Returns: ");
	printf("%s\n", return_val);
	free(return_val);

	char* return_val0 =  ft_convert_base("-4", "0123456789", "01");
	printf("Testing -4 (decimal) -> (binary). Expects: -100. Returns: ");
	printf("%s\n", return_val0);
	free(return_val0);

	char* return_val1 =  ft_convert_base("30074", "01234567", "0123456789abcdef");
	printf("Testing 30074 (octal) -> (hex). Expects: 303c. Returns: ");
	printf("%s\n", return_val1);
	free(return_val1);

	char* return_val2 =  ft_convert_base("a", "abcd", "wxyz");
	printf("Testing a (abcd) -> (wxyz) - checks handles value == 0. Expects: w. Returns: ");
	printf("%s\n", return_val2);
	free(return_val2);

	char* return_val3 =  ft_convert_base("   \t\n\v\f\r 567", "0123456789", "0123456789abcdef");
	printf("Testing ___567 (decimal) -> (hex). Expects: 237. Returns: ");
	printf("%s\n", return_val3);
	free(return_val3);

	char* return_val4 =  ft_convert_base("  -+--51", "0123456789", "01");
	printf("Testing __-+--51 (decimal) -> (binary). Expects: -11011. Returns: ");
	printf("%s\n", return_val4);
	free(return_val4);

	char* return_val5 =  ft_convert_base(" 1a234", "0123456789", "0123456789");
	printf("Testing _1a234 (decimal) -> (decimal) - checks stops once it reaches no longer base char. Expects: 1. Returns: ");
	printf("%s\n", return_val5);
	free(return_val5);

	char* return_val6 =  ft_convert_base("  -15+234", "0123456789", "0123456789abcdef");
	printf("Testing _-15+123 (decimal) -> (hex). Expects: -f. Returns: ");
	printf("%s. ", return_val6);
	printf("Pointer: %p (negative control for null pointers)\n", return_val6);
	free(return_val6);

	char* return_val7 =  ft_convert_base("123", "0123416789", "01");
	printf("Testing base contains duplicate. Expects: null pointer. Returns: ");
	printf("Pointer: %p\n", return_val7);
	free(return_val7);

	char* return_val8 =  ft_convert_base("123", "0123 456789", "01");
	printf("Testing base contains whitespace. Expects: null pointer. Returns: ");
	printf("Pointer: %p\n", return_val8);
	free(return_val8);

	char* return_val9 =  ft_convert_base("0", "0", "01");
	printf("Testing len(base) == 1. Expects: null pointer. Returns: ");
	printf("Pointer: %p\n", return_val9);
	free(return_val9);

	char* return_val10 =  ft_convert_base("a", "", "01");
	printf("Testing len(base) == 0. Expects: null pointer. Returns: ");
	printf("Pointer: %p\n", return_val10);
	free(return_val10);
}
