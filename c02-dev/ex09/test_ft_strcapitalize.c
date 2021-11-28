#include <stdio.h>
#include "ft_strcapitalize.c"

int main(void)
{
	printf("Test string: \"hello\"        Result: %s\n", ft_strcapitalize("hello"));
	printf("Test string: \"heLLo world\"  Result: %s\n", ft_strcapitalize("heLLo world"));
	printf("Test string: \"hello world something-test\"      Result: %s\n", ft_strcapitalize("hello world something-test"));
	printf("Test string: \"!hello &world 42test\"  Result: %s\n", ft_strcapitalize("!hello &world 42test"));
	printf("Input pointer should match returned pointer\n");
	char test[] = "heLLo";
	char* ret_val = ft_strcapitalize(test);
	printf("Test string: \"hello\" (test)  Result: %s\n", test);
	printf("Input pointer is : %p\n", test);
	printf("Return pointer is: %p\n", ret_val);
}	
