#include "ft_split.c"
#include <stdlib.h>
#include <stdio.h>

void print_all_words(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		printf("String %d: %s\n", i, tab[i]);
		i++;
	}
}

int main(void)
{
	char *long_string = "hello wooorld, this is a long string";
	char *sep = " o";

	char **result = ft_split(long_string, sep);
	print_all_words(result);
	free(result);
}
