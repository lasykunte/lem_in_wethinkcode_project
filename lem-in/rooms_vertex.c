#include "lem_in.h"

static void     check_int(char **rooms, f_graph_node *ptr_gr, char *str)
{
	int index;

	index = 0;
	if (ft_isdigit(str[0]) || str[0] == '-')
	{
		while (str[++index])
		{
            if (!(ft_isdigit(str[index])))
			{
				free_arr_mem(rooms, ptr_gr, 1);
			}
		}
	}
	else
    {
		free_arr_mem(rooms, ptr_gr, 1);
    }
}

static void	    check_room(f_graph_node *ptr_gr, char *line)
{
	char **rooms;

	rooms = ft_strsplit(line, ' ');
	if (rooms[3] != NULL || rooms[0][0] == 'L')
    {
		free_arr_mem(rooms, ptr_gr, 1);
    }
	check_int(rooms, ptr_gr, rooms[1]);
	check_int(rooms, ptr_gr, rooms[2]);
	free_arr_mem(rooms, ptr_gr, 0);
}

void		rooms_vertex(f_graph_node *ptr_gr, char *line)
{
	ptr_gr->start = 2;
	ptr_gr->room_vertex_list = combine_ant_string(ptr_gr->room_vertex_list, line, 0);
	if (line[0] == '#')
	{
		return ;
	}
	check_room(ptr_gr, line);
	ptr_gr->room_count++;
}
