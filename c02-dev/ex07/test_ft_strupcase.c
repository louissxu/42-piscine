#include <stdio.h>
#include "ft_strupcase.c"

int main(void)
{
	char test0[] = "Hello";
	ft_strupcase(test0);
	printf("Test string: \"Hello\"        Result: %s\n", test0);

	char test1[] = "heLLo World";
	ft_strupcase(test1);
	printf("Test string: \"heLLo World\"  Result: %s\n", test1);

	char test2[] = "h 123 i";
	ft_strupcase(test2);
	printf("Test string: \"h 123 i\"      Result: %s\n", test2);

	char test3[] = "h !@# !@# i";
	printf("Test string: \"h !@# !@# i\"  Result: %s\n", test3);

	printf("Input pointer should match returned pointer\n");
	char test[] = "hello";
	char* ret_val = ft_strupcase(test);
	printf("Test string: \"hello\" (test)  Result: %s\n", test);
	printf("Input pointer is : %p\n", test);
	printf("Return pointer is: %p\n", ret_val);
}	
