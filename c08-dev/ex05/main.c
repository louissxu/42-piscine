#include "../ex04/ft_strs_to_tab.c"
#include "ft_show_tab.c"

int	main(int argc, char **argv)
{
	t_stock_str *arr;

	arr = ft_strs_to_tab(argc, argv);
	ft_show_tab(arr);
}
