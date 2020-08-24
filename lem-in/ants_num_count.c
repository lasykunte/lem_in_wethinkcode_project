#include "lem_in.h"

void	ants_num_count(f_graph_node *ptr_gr, char *line)
{
	char	*str;
    int		index = 0;

	ptr_gr->start = 1;
	ptr_gr->ant_list = combine_ant_string(ptr_gr->ant_list, line, 0);
	if (line[0] == '#')
		return ;
	str = ft_strtrim(line);
	ptr_gr->ants = ft_atoi(str);
	if ((ptr_gr->ants) <= 0)
		freefunction_exit(ptr_gr, 1);
	while (str[index] != 0 && str[index] != '\n')
	{
		if (!ft_isdigit(str[index++]))
		{
			freefunction_exit(ptr_gr, 1);
		}
	}
}