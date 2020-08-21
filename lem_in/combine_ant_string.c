#include "lem_in.h"

char	*combine_ant_string(char *str, char *str1, int cln)
{
	char *combined_str;

	combined_str = ft_strnew(ft_strlen(str) + ft_strlen(str1) + 1);
	if (str[0] == 0)
    {
		return (str1);
    }
	ft_strcat(combined_str, str);
	ft_strcat(combined_str, "\n");
	ft_strcat(combined_str, str1);
	ft_strdel(&str);
    if (cln)
	{
        ft_strdel(&str1);
	}
	return (combined_str);
}