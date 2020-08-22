#include "lem_in.h"

int		room_vertex_indx(f_graph_node *ptr_gr, char *room_vertex_name, int begin)
{
	int i;

	if(begin)
	{
		i = -1;
	}
	else
		i = 0;
	while (ptr_gr->room_vertex[++i] && i < (ptr_gr->room_count))
	{
		if (ft_strcmp(ptr_gr->room_vertex[i], room_vertex_name) == 0)
		{
			return (i);
		}
	}
	return (i);
}