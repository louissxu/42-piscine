#include <stdio.h>
#include "ft_strjoin.c"

int main(void)
{
	int size = 3;
	char str1[] = "hello";
	char str2[] = "world";
	char str3[] = "blah";
	char *strs[3] = {str1, str2, str3};
	char sep[] = " ";
	char *returned_string;
	printf("Testing standard\n");
	returned_string = ft_strjoin(size, strs, sep);
	printf("The returned value was:\n");
	printf("%s\n\n", returned_string);
	free(returned_string);

	char *test1;
	printf("Testing size = 0\n");
	test1 = ft_strjoin(0, strs, sep);
	printf("The returned value was:\n");
	printf("%s<-should be empty to left of this arrow\n\n", test1);
	free (test1);

	int size2 = 5;
	char str2_1[] = "Tom";
	char str2_2[] = "Joe";
	char str2_3[] = "Bloggs";
	char str2_4[] = "Sam";
	char str2_5[] = "James";
	char *strs2[5] = {str2_1, str2_2, str2_3, str2_4, str2_5};
	char sep2[] = " and ";
	char *test2;
	printf("Testing len(sep) > 1\n");
	test2 = ft_strjoin(size2, strs2, sep2);
	printf("The returned value was:\n");
	printf("%s\n\n", test2);
	free (test2);

	int size3 = 3;
	char str3_1[] = "Words";
	char str3_2[] = "Concat";
	char str3_3[] = "Together";
	char *strs3[3] = {str3_1, str3_2, str3_3};
	char sep3[] = "";
	char *test3;
	printf("Testing len(sep) == 0\n");
	test3 = ft_strjoin(size3, strs3, sep3);
	printf("The returned value was:\n");
	printf("%s\n\n", test3);
	free (test3);

	int size4 = 2;
	char str4_1[] = "Two";
	char str4_2[] = "Words";
	char *strs4[2] = {str4_1, str4_2};
	char sep4[] = "<space>";
	char *test4;
	printf("Testing len(words) == 2\n");
	test4 = ft_strjoin(size4, strs4, sep4);
	printf("The returned value was:\n");
	printf("%s\n\n", test4);
	free (test4);
}
