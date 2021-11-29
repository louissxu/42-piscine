#include <stdio.h>
#include "ft_strcapitalize.c"

int main(void)
{	
	char test0[] = "hello";
	ft_strcapitalize(test0);
	printf("Test string: \"hello\"                       Result: %s\n", test0);

	char test1[] = "Hello";
	ft_strcapitalize(test1);
	printf("Test string: \"heLLo world\"                 Result: %s\n", test1);

	char test2[] = "hello world something-test";
	ft_strcapitalize(test2);
	printf("Test string: \"hello world something-test\"  Result: %s\n", test2);
	
	char test3[] = "!fizz &buzz*baz 42test";
	ft_strcapitalize(test3);
	printf("Test string: \"!fizz &buzz*baz 42test\"      Result: %s\n", test3);

	printf("Input pointer should match returned pointer\n");
	char test[] = "heLLo";
	char* ret_val = ft_strcapitalize(test);
	printf("Test string: \"hello\" (test)  Result: %s\n", test);
	printf("Input pointer is : %p\n", test);
	printf("Return pointer is: %p\n", ret_val);
}	
