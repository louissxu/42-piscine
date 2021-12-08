#include <string.h>
#include <stdio.h>
#include "ft_strdup.c"

int main(void)
{
	char str[] = "Hello World";
	char* str_ft_strdup = ft_strdup(str);
	char* str_strdup = strdup(str);

	printf("--------------------\n");
	printf("Testing regular string - string should be same, pointers should be different\n");
	printf("Initial string: %s    Pointer: %p\n", str, str);
	printf("ft_strcpy str : %s    Pointer: %p\n", str_ft_strdup, str_ft_strdup);
	printf("inbuilt strcpy: %s    Pointer: %p\n", str_strdup, str_strdup);

	free(str_ft_strdup);
	free(str_strdup);

	char str1[] = "";
	char* str1_ft_strdup = ft_strdup(str1);
	char* str1_strdup = strdup(str1);

	printf("--------------------\n");
	printf("Testing empty string - string should be same, pointers should be different\n");
	printf("Initial string: %s    Pointer: %p\n", str1, str1);
	printf("ft_strcpy str : %s    Pointer: %p\n", str1_ft_strdup, str1_ft_strdup);
	printf("inbuilt strcpy: %s    Pointer: %p\n", str1_strdup, str1_strdup);

	free(str_ft_strdup);
	free(str_strdup);
}
