#include <stdio.h>
#include "ft_str_is_alpha.c"

int main(void)
{
	printf("Test string: \"Hello\" (1): %d\n", ft_str_is_alpha("Hello"));
	printf("Test string: \"Hello World\" (0): %d\n", ft_str_is_alpha("Hello World"));
	printf("Test string: \"Hello123\" (0): %d\n", ft_str_is_alpha("Hello123"));
	printf("Test string: \"!@#\" (0): %d\n", ft_str_is_alpha("!@#"));
	printf("Test string: \"HelloAgain\" (1): %d\n", ft_str_is_alpha("HelloAgain"));
	printf("Test string: \"\" (empty str) (1): %d\n", ft_str_is_alpha(""));
}
