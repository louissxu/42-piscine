#include <stdio.h>
#include <string.h>
#include "ft_strcpy.c"

int main(void)
{
	char src_string[] = "Src test";
	char dest_string[] = "Dest test";
	printf("ft_before - SRC: %s  DEST: %s\n", src_string, dest_string);
	char* return_ptr = ft_strcpy(dest_string, src_string);
	printf("ft_after  - SRC: %s  DEST: %s\n", src_string, dest_string);
	printf("pointers  - SRC: %p  DEST: %p  RETURN: %p\n", src_string, dest_string, return_ptr);

	char src_string2[] = "Src test";
	char dest_string2[] = "Dest test";
	printf("inbuilt pre  - SRC: %s  DEST: %s\n", src_string2, dest_string2);
	char* return_ptr2 = strcpy(dest_string2, src_string2);
	printf("inbuilt post - SRC: %s  DEST: %s\n", src_string2, dest_string2); 
	printf("pointers  - SRC: %p  DEST: %p  RETURN: %p\n", src_string2, dest_string2, return_ptr2);
}

