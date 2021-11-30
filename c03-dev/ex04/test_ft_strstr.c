#include <stdio.h>
#include "ft_strstr.c"

int main(void)
{
printf("ft_strstr haystack needle: %s\n", ft_strstr("haystack", "needle"));	
printf("ft_strstr haystack : %s\n", ft_strstr("haystack", ""));
printf("ft_strstr haystack hay: %s\n", ft_strstr("haystack", "hay"));	
printf("ft_strstr haystack stack: %s\n", ft_strstr("haystack", "stack"));
}
