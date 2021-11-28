#include <stdio.h>
#include "ft_strlowcase.c"

int main(void)
{
	printf("Test string: \"Hello\"        Result: %s\n", ft_strlowcase("Hello"));
	printf("Test string: \"heLLo World\"  Result: %s\n", ft_strlowcase("heLLo World"));
	printf("Test string: \"H 123 I\"      Result: %s\n", ft_strlowcase("H 123 I"));
	printf("Test string: \"H !@# !@# I\"  Result: %s\n", ft_strlowcase("H !@# !@# I"));
	printf("Input pointer should match returned pointer\n");
	char test[] = "HELLO";
	char* ret_val = ft_strlowcase(test);
	printf("Test string: \"hello\" (test)  Result: %s\n", test);
	printf("Input pointer is : %p\n", test);
	printf("Return pointer is: %p\n", ret_val);
}	
