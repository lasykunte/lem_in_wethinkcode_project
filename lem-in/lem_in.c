#include "lem_in.h"

static int		    check_empty_line(char *str)
{
	unsigned int index;

	index = 0;
	while (ft_isspace(str[index]) && str[index])
    {
		index++;
    }
	if (index == ft_strlen(str))
    {
		return (1);
    }
	return (0);
}

static f_graph_node *initialize_farm_graph(void)
{
	f_graph_node *ptr_gr;

	ptr_gr = (f_graph_node*)malloc(sizeof(f_graph_node));
	ptr_gr->edge_links = ft_strnew(1);
	ptr_gr->ant_list = ft_strnew(1);
	ptr_gr->room_vertex_list = ft_strnew(1);
	ptr_gr->room_count = 0;
	ptr_gr->ants = 0;
	ptr_gr->start = 0;
	ptr_gr->current_room = 0;
	ptr_gr->path_f_indx = 0;
	ptr_gr->initialiaze_validate = 0;
	ptr_gr->validate[0] = 0;
	ptr_gr->validate[1] = 0;
	ptr_gr->room_vertex = NULL;
	ptr_gr->adjacency_matrix_table = NULL;
	ptr_gr->path_f = NULL;
	return (ptr_gr);
}

static f_graph_node	*initialize_validate_f(f_graph_node *ptr_gr)
{
	int j;
	int k;

	j = -1;
	ptr_gr->initialiaze_validate = 1;
	ptr_gr->path_f = (int*)malloc(sizeof(int) * 1000);
	ptr_gr->adjacency_matrix_table = (int**)malloc(sizeof(int*) * ptr_gr->room_count);
	ptr_gr->room_vertex = (char**)malloc(sizeof(char*) * (ptr_gr->room_count + 1));
	while (++j < ptr_gr->room_count)
	{
		ptr_gr->path_f[j] = -1;
		ptr_gr->room_vertex[j] = NULL;
		ptr_gr->adjacency_matrix_table[j] = (int*)malloc(sizeof(int) * ptr_gr->room_count);
		k = -1;
		while (ptr_gr->adjacency_matrix_table[j][++k])
        {
			ptr_gr->adjacency_matrix_table[j][k] = 0;
        }
	}
	ptr_gr->room_vertex[j] = NULL;
	ptr_gr->path_f[0] = 0;
	return (ptr_gr);
}

static void		    read_file_line(f_graph_node *ptr_gr)
{
	char *line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ptr_gr->ants == 0)
        {
			ants_num_count(ptr_gr, line);
        }
		else if (ptr_gr->start == 3 || ft_strchr(line, '-'))
        {
			edge_links(ptr_gr, line);
        }
		else if ((ptr_gr->start == 1 || ptr_gr->start == 2) && !(check_empty_line(line)))
        {
			rooms_vertex(ptr_gr, line);
        }
		else
			freefunction_exit(ptr_gr, 1);
	}
	if (!(ptr_gr->ants) || !(ptr_gr->edge_links[0]))
    {
		freefunction_exit(ptr_gr, 1);
    }
	ptr_gr = initialize_validate_f(ptr_gr);
}

int				    main(void)
{
	f_graph_node *ptr_gr;

	ptr_gr = initialize_farm_graph();
	read_file_line(ptr_gr);
	sum_room_vertex(ptr_gr);
	if (!(ptr_gr->validate[0]) || !(ptr_gr->validate[1]))
    {
		freefunction_exit(ptr_gr, 1);
    }
	adjacency_matrix(ptr_gr);
	display_matrix(ptr_gr);
	if (backtracking(ptr_gr, 0))
    {
		path_result(ptr_gr);
    }
	else
		freefunction_exit(ptr_gr, 1);
	freefunction_exit(ptr_gr, 0);
}