#include "2-5-ft_strrev.c"
#include <stdio.h>

int main(void)
{
	char a[] = "hello world";

	printf("Word: %s\n", a);
	printf("Return ptr: %p\n", ft_strrev(a));
	printf("Word: %s\n", a);
	printf("Prev ptr  : %p\n", a);
}	
