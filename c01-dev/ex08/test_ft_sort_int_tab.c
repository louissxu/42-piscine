#include <stdio.h>
#include "ft_sort_int_tab.c"

int main(void)
{
	int test_array[] = {5, 15, 200, 7, 100};
	printf("Original array values were ");
	for (int i = 0; i < 5; i++)
		printf("%d, ", test_array[i]);
	printf("\n");
	
	ft_sort_int_tab(test_array, 5); 
	
	printf("Updated array vales are    ");
	for (int i = 0; i < 5; i++)
		printf("%d, ", test_array[i]);
	printf("\n");


	int test_array_2[] = {20, 10, 60, 50, 40, 30};
	printf("Original array values were ");
	for (int i = 0; i < 6; i++)
		printf("%d, ", test_array_2[i]);
	printf("\n");
	
	ft_sort_int_tab(test_array_2, 6); 
	
	printf("Updated array vales are    ");
	for (int i = 0; i < 6; i++)
		printf("%d, ", test_array_2[i]);
	printf("\n");
}
