#include <stdio.h>
#include "ft_str_is_lowercase.c"

int main(void)
{
	printf("Test string: \"hello\"            (1): %d\n", ft_str_is_lowercase("hello"));
	printf("Test string: \"HelloWorld\"       (0): %d\n", ft_str_is_lowercase("HelloWorld"));
	printf("Test string: \"hello123\"         (0): %d\n", ft_str_is_lowercase("hello123"));
	printf("Test string: \"!@#\"              (0): %d\n", ft_str_is_lowercase("!@#"));
	printf("Test string: \"hello with space\" (0): %d\n", ft_str_is_lowercase("hello with space"));
	printf("Test string: \"\" (empty str)     (1): %d\n", ft_str_is_lowercase(""));
}
