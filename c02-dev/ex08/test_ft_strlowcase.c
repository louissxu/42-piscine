#include <stdio.h>
#include "ft_strlowcase.c"

int main(void)
{
	char test0[] = "Hello";
	ft_strlowcase(test0);
	printf("Test string: \"Hello\"        Result: %s\n", test0);
	
	char test1[] = "heLLo World";
	ft_strlowcase(test1);
	printf("Test string: \"heLLo World\"  Result: %s\n", test1);

	char test2[] = "H 123 I";
	ft_strlowcase(test2);
	printf("Test string: \"H 123 I\"      Result: %s\n", test2);

	char test3[] = "H !@# !@# I";
	ft_strlowcase(test0);
	printf("Test string: \"H !@# !@# I\"  Result: %s\n", test3);

	printf("Input pointer should match returned pointer\n");
	char test[] = "HELLO";
	char* ret_val = ft_strlowcase(test);
	printf("Test string: \"hello\" (test)  Result: %s\n", test);
	printf("Input pointer is : %p\n", test);
	printf("Return pointer is: %p\n", ret_val);
}	
