#include "lem_in.h"

static void     valid_edge_link(f_graph_node *ptr_gr, char *link)
{
	char **room_edge;

	room_edge = ft_strsplit(link, '-');
	if (room_edge[2] != NULL)
    {
		free_arr_mem(room_edge, ptr_gr, 1);
    }
	free_arr_mem(room_edge, ptr_gr, 0);
}

void		adjacency_matrix(f_graph_node *ptr_gr)
{
	int		index;
	int		row_order_i;
	int		row_order_j;
	char	**room_l;
	char	**room_links;

	index = -1;
	room_links = ft_strsplit(ptr_gr->edge_links, '\n');
	while (room_links[++index])
	{
		if (room_links[index][0] == '#')
		{
			continue ;
		}
		valid_edge_link(ptr_gr, room_links[index]);
		room_l = ft_strsplit(room_links[index], '-');
		if ((row_order_i = room_vertex_indx(ptr_gr, room_l[0], 1))>= ptr_gr->room_count ||
						(row_order_j = room_vertex_indx(ptr_gr, room_l[1], 1)) >= ptr_gr->room_count)
		{
			free_arr_mem(room_l, ptr_gr, 0);
			free_arr_mem(room_links, ptr_gr, 1);
		}
		(row_order_j) ? (ptr_gr->adjacency_matrix_table[row_order_i][row_order_j] = 1) : 0;
		(row_order_i) ? (ptr_gr->adjacency_matrix_table[row_order_j][row_order_i] = 1) : 0;
		free_arr_mem(room_l, ptr_gr, 0);
	}
	free_arr_mem(room_links, ptr_gr, 0);
}
