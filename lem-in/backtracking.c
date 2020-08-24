#include "lem_in.h"

static int	    find_edge_link(f_graph_node *ptr_gr, int vertex_i, int door_i)
{
	while (door_i < ptr_gr->room_count)
	{
		if (ptr_gr->adjacency_matrix_table[vertex_i][++door_i] == 1)
        {
			return (door_i);
        }
	}
	return (0);
}

static int      check_end_vertex(f_graph_node *ptr_gr, int index)
{
	if (ptr_gr->adjacency_matrix_table[index][ptr_gr->room_count - 1])
	{
		ptr_gr->path_f[++(ptr_gr->path_f_indx)] = index;
		ptr_gr->path_f[++(ptr_gr->path_f_indx)] = ptr_gr->room_count - 1;
		return (1);
	}
	return (0);
}

static void	    kill_node(f_graph_node *ptr_gr, int index, int path)
{
	ptr_gr->adjacency_matrix_table[ptr_gr->current_room][index] = 0;
	ptr_gr->adjacency_matrix_table[index][ptr_gr->current_room] = 0;
	if (path)
	{
		ptr_gr->path_f[ptr_gr->path_f_indx] = -1;
		ptr_gr->path_f_indx--;
	}
}

static int	    along_path(f_graph_node *ptr_gr, int vertex_i)
{
	int index;

	index = -1;
	while (ptr_gr->path_f[++index] != -1)
	{
		if (ptr_gr->path_f[index] == vertex_i)
        {
			return (1);
        }
	}
	return (0);
}

int			    backtracking(f_graph_node *ptr_gr, int index)
{
	if (ptr_gr->adjacency_matrix_table[0][ptr_gr->room_count - 1])
	{
		ptr_gr->path_f[++(ptr_gr->path_f_indx)] = ptr_gr->room_count - 1;
		return (1);
	}
	while ((index = find_edge_link(ptr_gr, ptr_gr->current_room, index)))
	{
		if (check_end_vertex(ptr_gr, index))
        {
			return (1);
        }
		else if (along_path(ptr_gr, index))
        {
			kill_node(ptr_gr, index, 0);
        }
	}
	if ((ptr_gr->current_room = find_edge_link(ptr_gr, ptr_gr->current_room, 0)) == 0)
	{
		if (ptr_gr->current_room == 0 || ptr_gr->path_f_indx == 0)
        {
			return (0);
        }
		ptr_gr->current_room = ptr_gr->path_f[ptr_gr->path_f_indx - 1];
		kill_node(ptr_gr, ptr_gr->path_f[ptr_gr->path_f_indx], 1);
		if (backtracking(ptr_gr, 0))
        {
			return (1);
        }
	}
	ptr_gr->path_f[++(ptr_gr->path_f_indx)] = ptr_gr->current_room;
	if (backtracking(ptr_gr, 0))
    {
		return (1);
    }
	return (0);
}