#include "lem_in.h"

void	freefunction_exit(f_graph_node *ptr_gr, int err)
{
	int index;

	free(ptr_gr->room_vertex_list);
	free(ptr_gr->edge_links);
	free(ptr_gr->ant_list);
	if (ptr_gr->initialiaze_validate)
	{
		free(ptr_gr->path_f);
		free_arr_mem(ptr_gr->room_vertex, ptr_gr, 0);
		index = -1;
		while (++index < ptr_gr->room_count)
		{
			free(ptr_gr->adjacency_matrix_table[index]);
		}
		free(ptr_gr->adjacency_matrix_table);
	}
	free(ptr_gr);
	if (err)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}