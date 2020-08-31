#include "lem_in.h"

static void	        display_ants(int ants, char *room)
{
	ft_putchar('L');
	ft_putnbr(ants);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

static void	        display_results(f_graph_node *ptr_gr, int num)
{
	int ants;

	if (num == (ptr_gr->path_f_indx + ptr_gr->ants + 1))
    {
		return ;
    }
	ants = ptr_gr->ants + 1;
	while (--ants > 0)
	{
		if (num - ants > 0 && (num - ants) <= ptr_gr->path_f_indx)
        {
			display_ants(ants, ptr_gr->room_vertex[ptr_gr->path_f[num - ants]]);
        }
	}
	ft_putchar('\n');
	display_results(ptr_gr, ++num);
}

void		path_result(f_graph_node *ptr_gr)
{
	int index;
	int i = -1;

	index = -1;
	ft_putendl(ptr_gr->ant_list);
	ft_putendl(ptr_gr->room_vertex_list);
	ft_putendl(ptr_gr->edge_links);
	ft_putchar('\n');
	display_results(ptr_gr, 2);
	ft_putchar('\n');
	while (++index <= ptr_gr->path_f_indx)
	{
		ft_putchar('(');
		ft_putnbr(ptr_gr->path_f[index]);
		ft_putchar(')');
		if (index != ptr_gr->path_f_indx)
		{
			ft_putchar('-');
		}
	}
	ft_putstr("\n\n");
	while (++i < ptr_gr->room_count)
	{
		ft_putchar('(');
		ft_putnbr(i);
		ft_putstr(")indx -  ");
		ft_putendl(ptr_gr->room_vertex[i]);
	}
}