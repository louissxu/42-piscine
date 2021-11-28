#include <stdio.h>
#include "ft_str_is_numeric.c"

int main(void)
{
	printf("Test string: \"123\"          (1): %d\n", ft_str_is_numeric("123"));
	printf("Test string: \"Hello World\"  (0): %d\n", ft_str_is_numeric("Hello World"));
	printf("Test string: \"Hello123\"     (0): %d\n", ft_str_is_numeric("Hello123"));
	printf("Test string: \"!@#\"          (0): %d\n", ft_str_is_numeric("!@#"));
	printf("Test string: \"789456\"       (1): %d\n", ft_str_is_numeric("789456"));
	printf("Test string: \"\" (empty str) (1): %d\n", ft_str_is_numeric(""));
}
