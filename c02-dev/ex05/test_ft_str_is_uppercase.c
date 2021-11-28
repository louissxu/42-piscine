#include <stdio.h>
#include "ft_str_is_uppercase.c"

int main(void)
{
	printf("Test string: \"HELLO\"        (1): %d\n", ft_str_is_uppercase("HELLO"));
	printf("Test string: \"\" (empty str) (1): %d\n", ft_str_is_uppercase(""));
	printf("Test string: \"hello\"        (0): %d\n", ft_str_is_uppercase("hello123"));
	printf("Test string: \"123\"          (0): %d\n", ft_str_is_uppercase("123"));
	printf("Test string: \" \"            (0): %d\n", ft_str_is_uppercase(" "));
	printf("Test string: \"!@#\"          (0): %d\n", ft_str_is_uppercase("!@#"));
}
