#include "lem_in.h"

static void	    head(f_graph_node *ptr_gr)
{
	int index;

	index = -1;
	ft_putstr("\n\n");
	ft_putstr("\t   ");
	while (++index < (ptr_gr->room_count))
	{
		ft_putchar(' ');
		ft_putnbr((index > 9) ? (index % 10) : index);
	}
	ft_putstr("\n\n");
}

void		display_matrix(f_graph_node *ptr_gr)
{
	int row_i;
	int col_j;

	head(ptr_gr);
	row_i = -1;
	while (++row_i < ptr_gr->room_count)
	{
		ft_putchar('\t');
		ft_putnbr((row_i > 9) ? (row_i % 10) : row_i);
		ft_putstr("   ");
		col_j = -1;
		while (++col_j < ptr_gr->room_count)
		{
			ft_putnbr(ptr_gr->adjacency_matrix_table[row_i][col_j]);
			ft_putchar(' ');
		}
		ft_putstr("\t\t");
		ft_putchar('(');
		ft_putnbr(row_i);
		ft_putstr(")I -  ");
		ft_putendl(ptr_gr->room_vertex[row_i]);
	}
	ft_putstr("\n\n");
}