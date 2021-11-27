#include <stdio.h>
#include "ft_ft.c"

int main(void)
{
	int a = 5;
	printf("The prior value of a is: %d\n", a);
	ft_ft(&a);
	printf("The current value of a is: %d\n", a);
}

