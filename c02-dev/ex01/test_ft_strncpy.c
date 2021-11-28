#include <stdio.h>
#include <string.h>
#include "ft_strncpy.c"

int main(void)
{	
	printf("\n----------------------------------------\n");
	printf("Testing with n = 10, (n > len(src)) => should terminate dest with \\0)\n");
	char src_string[] = "source";
	char dest_string[] = "....................";
	printf("ft_before - SRC: %s  DEST: %s\n", src_string, dest_string);
	char* return_ptr = ft_strncpy(dest_string, src_string, 10);
	printf("ft_after  - SRC: %s  DEST: %s\n", src_string, dest_string);
	printf("pointers  - SRC: %p  DEST: %p  RETURN: %p\n", src_string, dest_string, return_ptr);
	printf("\n");
	
	char src_string2[] = "source";
	char dest_string2[] = "....................";
	printf("inbuilt pre  - SRC: %s  DEST: %s\n", src_string2, dest_string2);
	char* return_ptr2 = strncpy(dest_string2, src_string2, 10);
	printf("inbuilt post - SRC: %s  DEST: %s\n", src_string2, dest_string2);
	printf("pointers  - SRC: %p  DEST: %p  RETURN: %p\n", src_string2, dest_string2, return_ptr2);

	printf("\n----------------------------------------\n");
	printf("Testing with n = 5 (n < len(src)) => dest should continue/concat)\n");
	char src_string3[] = "source";
	char dest_string3[] = "....................";
	printf("ft_before - SRC: %s  DEST: %s\n", src_string3, dest_string3);
	char* return_ptr3 = ft_strncpy(dest_string3, src_string3, 5);
	printf("ft_after  - SRC: %s  DEST: %s\n", src_string3, dest_string3); 
	printf("pointers  - SRC: %p  DEST: %p  RETURN: %p\n", src_string3, dest_string3, return_ptr3);
	printf("\n");

	char src_string4[] = "source";
	char dest_string4[] = "....................";
	printf("inbuilt pre  - SRC: %s  DEST: %s\n", src_string4, dest_string4);
	char* return_ptr4 = strncpy(dest_string4, src_string4, 5);
	printf("inbuilt post - SRC: %s  DEST: %s\n", src_string4, dest_string4); 
	printf("pointers  - SRC: %p  DEST: %p  RETURN: %p\n", src_string4, dest_string4, return_ptr4);
}

