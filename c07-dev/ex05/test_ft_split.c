#include <stdio.h>
#include "ft_split.c"

int main(void)
{
	char** results = ft_split("hello worldreallylonasfkeljfklasefjlksaejfl;saefklsjflksjlksfegword man    a    stuff", " o");
	while(*results)
	{
		printf("pointer: %p. string contents: %s\n", *results, *results);
		results++;
	}
	printf("final pointer: %p\n", *results);
	results++;
	printf("pointer: %p\n", *results);
}
