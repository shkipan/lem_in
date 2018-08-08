#include "lem_in.h"

int     check_ants_number(t_lemin *lemin, char *line)
{
    int     i;
    int     number;

    ft_printf("|ants| %s\n", line);
    i = -1;
    while (line[++i])
        if (!(ft_isdigit(line[i])) && (line[i] != '-'))
            return (-1);
    if ((number = ft_atoi(line)) < 0)
        return (-2);
    if (number == 0)
        return (-3);
    lemin->ants = number;
    return (0);
}