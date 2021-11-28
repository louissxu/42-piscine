#include <stdio.h>
#include "ft_strupcase.c"

int main(void)
{
	printf("Test string: \"Hello\"        Result: %s\n", ft_strupcase("Hello"));
	printf("Test string: \"heLLo World\"  Result: %s\n", ft_strupcase("heLLo World"));
	printf("Test string: \"h 123 i\"      Result: %s\n", ft_strupcase("h 123 i"));
	printf("Test string: \"h !@# !@# i\"  Result: %s\n", ft_strupcase("h !@# !@# i"));
	printf("Input pointer should match returned pointer\n");
	char test[] = "hello";
	char* ret_val = ft_strupcase(test);
	printf("Test string: \"hello\" (test)  Result: %s\n", test);
	printf("Input pointer is : %p\n", test);
	printf("Return pointer is: %p\n", ret_val);
}	
