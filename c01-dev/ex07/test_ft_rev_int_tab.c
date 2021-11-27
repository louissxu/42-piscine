#include <stdio.h>
#include "ft_rev_int_tab.c"

int main(void)
{
	int test_array[] = {5, 15, 200, 7, 11};
	printf("Original array values were ");
	for (int i = 0; i < 5; i++)
		printf("%d, ", test_array[i]);
	printf("\n");
	
	ft_rev_int_tab(test_array, 5); 
	
	printf("Updated array vales are    ");
	for (int i = 0; i < 5; i++)
		printf("%d, ", test_array[i]);
	printf("\n");


	int test_array_2[] = {10, 20, 30, 40, 50, 60};
	printf("Original array values were ");
	for (int i = 0; i < 6; i++)
		printf("%d, ", test_array_2[i]);
	printf("\n");
	
	ft_rev_int_tab(test_array_2, 6); 
	
	printf("Updated array vales are    ");
	for (int i = 0; i < 6; i++)
		printf("%d, ", test_array_2[i]);
	printf("\n");
}
