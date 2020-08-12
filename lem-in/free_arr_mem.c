#include "lem_in.h"

void    free_arr_mem(char **arr, f_graph_node *ptr_gr, int err)
{
    int index;

    index = 0;
    while (arr[index])
    {
		if(arr[index])
        {
            free(arr[index++]);    
        }
    }
	free(arr);
	if (err)
		exit(1));
	arr = NULL;
}