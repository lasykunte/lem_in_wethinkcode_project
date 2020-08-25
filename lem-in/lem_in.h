#ifndef _LEM_IN_H_
# define _LEM_IN_H_
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		farm_graph
{
	int			    ants;
    int				room_count;
    int             current_room;
    int             **adjacency_matrix_table;
    int             *path_f;
    int             path_f_indx;
    int             validate[2];
	int				initialiaze_validate;
    int             valid_line;
    int             start;
    char            **room_vertex;
    char            *ant_list;
    char            *edge_links;
    char            *room_vertex_list;
}					f_graph_node;

void	            ants_num_count(f_graph_node *ptr_gr, char *line);
void	            rooms_vertex(f_graph_node *ptr_gr, char *line);
void	            edge_links(f_graph_node *ptr_gr, char *line);
void			    sum_room_vertex(f_graph_node *ptr_gr);
void		        adjacency_matrix(f_graph_node *ptr_gr);
int			        backtracking(f_graph_node *ptr_gr, int index);
char	            *combine_ant_string(char *str, char *str1, int cln);
void                free_arr_mem(char **arr, f_graph_node *ptr_gr, int err);
int		            room_vertex_indx(f_graph_node *ptr_gr, char *room_vertex_name, int begin);
void		        path_result(f_graph_node *ptr_gr);
void		        display_matrix(f_graph_node *ptr_gr);
void	            freefunction_exit(f_graph_node *ptr_gr, int err);

#endif