#include "lem_in.h"

static void     check_int(char **vertex_room, f_graph_node *ptr_gr, char *str)
{
	int index;
    int int_digit;

	index = 0;
	if (ft_isdigit(str[0] || str[0] == '-'))
	{
		while (str[index])
		{
			int_digit = ft_isdigit(str[index])
            if (!int_digit)
				free_arr_mem(vertex_room, ptr_gr, 1);
            ++index;
		}
	}
	else
    {
		free_arr_mem(vertex_room, ptr_gr, 1);
    }
}

static void	    check_room(f_graph_node *ptr_gr, char *line)
{
	char **vertex_room;

	vertex_room = ft_strsplit(line, ' ');
	if (vertex_room[3] != NULL || vertex_room[0][0] == 'L')
    {
		free_arr_mem(vertex_room, ptr_gr, 1);
    }
	check_int(vertex_room, ptr_gr, vertex_room[1]);
	check_int(vertex_room, ptr_gr, vertex_room[2]);
	free_arr_mem(vertex_room, ptr_gr, 0);
}

void		rooms_vertex(f_graph_node *ptr_gr, char *line)
{
	ptr_gr->start = 2;
	ptr_gr->room_vertex_list = combine_ant_string(ptr_gr->room_vertex_list, line, 0);
	if (line[0] == '#')
		return ;
	check_room(ptr_gr, line);
	ptr_gr->room_count++;
}
