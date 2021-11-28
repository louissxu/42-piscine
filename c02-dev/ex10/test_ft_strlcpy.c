#include <stdio.h>
#include <string.h>
#include "ft_strlcpy.c"

int main(void)
{	
	printf("\n----------------------------------------\n");
	printf("Testing with n = 10, (n > len(src)) => should terminate dest with \\0)\n");
	char src_string[] = "source";
	char dest_string[] = "....................";
	printf("ft_before - SRC: %s  DEST: %s\n", src_string, dest_string);
	unsigned int ret_val = ft_strlcpy(dest_string, src_string, 10);
	printf("ft_after  - SRC: %s  DEST: %s\n", src_string, dest_string);
	printf("return val (6): %u\n", ret_val);
	printf("\n");
	
	char src_string2[] = "source";
	char dest_string2[] = "....................";
	printf("inbuilt pre  - SRC: %s  DEST: %s\n", src_string2, dest_string2);
	unsigned int ret_val2 = strlcpy(dest_string2, src_string2, 10);
	printf("inbuilt post - SRC: %s  DEST: %s\n", src_string2, dest_string2);
	printf("return val (6): %u\n", ret_val2);

	printf("\n----------------------------------------\n");
	printf("Testing with n = 5 (n < len(src)) => dest should terminate short)\n");
	char src_string3[] = "sources";
	char dest_string3[] = "....................";
	printf("ft_before - SRC: %s  DEST: %s\n", src_string3, dest_string3);
	unsigned int ret_val3 = ft_strlcpy(dest_string3, src_string3, 5);
	printf("ft_after  - SRC: %s  DEST: %s\n", src_string3, dest_string3); 	
	printf("return val (7): %u\n", ret_val3);
	printf("\n");

	char src_string4[] = "sources";
	char dest_string4[] = "....................";
	printf("inbuilt pre  - SRC: %s  DEST: %s\n", src_string4, dest_string4);
	unsigned int ret_val4 = strlcpy(dest_string4, src_string4, 5);
	printf("inbuilt post - SRC: %s  DEST: %s\n", src_string4, dest_string4); 
	printf("return val (7): %u\n", ret_val4);
	
	printf("\n----------------------------------------\n");
	printf("Testing with n = 5 (n < len(src)) but long src string => dest should terminate short with correct return value)\n");
	char src_string5[] = "source--------------------";
	char dest_string5[] = "....................";
	printf("ft_before - SRC: %s  DEST: %s\n", src_string5, dest_string5);
	unsigned int ret_val5 = ft_strlcpy(dest_string5, src_string5, 5);
	printf("ft_after  - SRC: %s  DEST: %s\n", src_string5, dest_string5); 	
	printf("return val (26): %u\n", ret_val5);
	printf("\n");

	char src_string6[] = "source--------------------";
	char dest_string6[] = "....................";
	printf("inbuilt pre  - SRC: %s  DEST: %s\n", src_string6, dest_string6);
	unsigned int ret_val6 = strlcpy(dest_string6, src_string6, 5);
	printf("inbuilt post - SRC: %s  DEST: %s\n", src_string6, dest_string6); 
	printf("return val (26): %u\n", ret_val6);
}

