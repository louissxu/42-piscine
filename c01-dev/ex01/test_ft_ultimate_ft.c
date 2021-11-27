#include "ft_ultimate_ft.c"
#include <stdio.h>

int main(void)
{
	int a = 0;

	int* b = &a;
	int** c = &b;
	int*** d = &c;
	int**** e = &d;
	int***** f = &e;
	int****** g = &f;
	int******* h = &g;
	int******** i = &h;
	int********* j = &i;

	printf("The prior value of a is %d\n", a);
	ft_ultimate_ft(j);
	printf("The current value of a is: %d\n", a);
}
