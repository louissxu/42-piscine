void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);

#include <stdio.h>
#include <string.h>

int	main(void)
{
	ft_putchar('a');
	ft_putstr("Testing putstr");
	printf("Strlen of hello is: %d\n", ft_strlen("hello"));
	printf("ft_strcmp of hello and world is :%d\n", ft_strcmp("hello", "world"));
	printf("strcmp of hello and world is %d\n", strcmp("hello", "world"));
	int a = 5;
	int b = 7;
	printf("a: %d, b: %d\n", a, b);
	ft_swap(&a, &b);
	printf("a: %d, b: %d\n", a, b);
}
