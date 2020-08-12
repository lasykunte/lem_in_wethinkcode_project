#include "lem_in.h"

static void     check_int(char **vertex, f_graph_node *ptr_gr, char *str)
{
	int index;
    int int_digit;

	index = 0;
	if (str[0] == '-' || ft_isdigit(str[0]))
	{
		while (str[index])
		{
			int_digit = ft_isdigit(str[index])
            if (!int_digit)
				free_arr_mem(vertex, ptr_gr, 1);
            ++index;
		}
	}
	else
    {
		free_arr_mem(vertex, ptr_gr, 1);
    }
}
