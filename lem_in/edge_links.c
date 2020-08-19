#include "lem_in.h"

void	edge_links(f_graph_node *ptr_gr, char *line)
{
	if (ptr_gr->start == 2)
    {
		ptr_gr->start = 3;
    }
	if (ptr_gr->start != 3)
    {
		freefunction_exit(ptr_gr, 1);
    }
	ptr_gr->edge_link = combine_ant_stings(ptr_gr->edge_links, line, 0);
}