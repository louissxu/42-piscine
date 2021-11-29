#include <stdio.h>
#include "ft_str_is_printable.c"

int main(void)
{
	printf("Test string: \"HELLO\"        (1): %d\n", ft_str_is_printable("HELLO"));
	printf("Test string: \"\" (empty str) (1): %d\n", ft_str_is_printable(""));
	printf("Test string: \"hello\"        (1): %d\n", ft_str_is_printable("hello123"));
	printf("Test string: \"123\"          (1): %d\n", ft_str_is_printable("123"));
	printf("Test string: \" \"            (1): %d\n", ft_str_is_printable(" "));
	printf("Test string: \"!@#\"          (1): %d\n", ft_str_is_printable("!@#"));
	printf("Test string: \" ~!\"{|}\"      (1): %d\n", ft_str_is_printable(" ~!\"{|}"));
	printf("Test string: \"\\t\" (tab)     (0): %d\n", ft_str_is_printable("\n"));
	printf("Test string: \"\\n\" (newline) (0): %d\n", ft_str_is_printable("\t"));
}
