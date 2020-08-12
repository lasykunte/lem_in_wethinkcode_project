#ifndef _LEM_IN_H_
# define _LEM_IN_H_
# include <unistd.h>
# include <studio.h>
# include "libft/libft.h"

typedef struct		farm_graph
{
	int			    ants;
    int				room_count;
    int             current_room;
    int             **adjecency_matrix_table;
    int             *path_find;
    int             path_find_indx;
    int             validate[2];
	int				initialiaze_validate;
    int             valid_line;
    int             start;
    char            **room_vertex;
    char            *ant_list;
    char            *edge_links;
    char            *room_vertex_list;
}					f_graph_node;
