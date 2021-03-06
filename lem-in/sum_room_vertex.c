#include "lem_in.h"

static void	    validate(f_graph_node *ptr_gr, char **line, char **rooms, int end)
{
	if (++(ptr_gr->validate[end]) > 1)
	{
		free_arr_mem(rooms, ptr_gr, 0);
		free_arr_mem(line, ptr_gr, 1);
	}
}

static void		validate_vertex_indx(f_graph_node *ptr_gr, int index, char **rooms)
{
	int vertex_indx;

	vertex_indx = room_vertex_indx(ptr_gr, rooms[0], 0);
	if (vertex_indx > 0 && index != vertex_indx)
	{
		freefunction_exit(ptr_gr, 1);
	}
	ptr_gr->room_vertex[index] = ft_strdup(rooms[0]);
}

static void		check_vertex_start(f_graph_node *ptr_gr, char **rooms, int end)
{
	if (end)
	{
		ptr_gr->room_vertex[ptr_gr->room_count - 1] = ft_strdup(rooms[0]);
		(ptr_gr->validate[1])++;
		return ;
	}
	ptr_gr->room_vertex[0] = ft_strdup(rooms[0]);
	(ptr_gr->validate[0])++;
}

void			sum_room_vertex(f_graph_node *ptr_gr)
{
	char	**line;
	char	**rooms;
	int		i;
	int		j;

	i = -1;
	j = 1;
	line = ft_strsplit(ptr_gr->room_vertex_list, '\n');
	while (line[++i] && j < (ptr_gr->room_count))
	{
		rooms = ft_strsplit(line[i], ' ');
		if (!ft_strcmp("##start", line[i]))
		{
			validate(ptr_gr, line, rooms, 0);
		}
		else if (!ft_strcmp("##end", line[i]))
		{
			validate(ptr_gr, line, rooms, 1);
		}
		else if (line[i][0] != '#' && ptr_gr->validate[0] == 1)
		{
			check_vertex_start(ptr_gr, rooms, 0);
		}
		else if (line[i][0] != '#' && ptr_gr->validate[1] == 1)
		{
			check_vertex_start(ptr_gr, rooms, 1);
		}
		else if (line[i][0] != '#')
		{
			validate_vertex_indx(ptr_gr, j++, rooms);
		}
		free_arr_mem(rooms, ptr_gr, 0);
	}
	free_arr_mem(line, ptr_gr, 0);
}


