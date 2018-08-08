#include "lem_in.h"

int     check_comment(char *line)
{
    return ((line[0] == '#' && ft_strcmp(line, "##start")
             && ft_strcmp(line, "##end")));
}

int     check_room(char *line)
{
    return (0);
}

int     check_link(char *line)
{
    return (0);
}

int     check_status(char *line)
{
    if (!ft_strcmp(line, "##start"))
        return (1);
    if (!ft_strcmp(line, "##end"))
        return (2);
    return (0);
}

int     check_line(t_lemin *lemin, char *line)
{
    if (check_comment(line))
        ft_printf("|comment| ");
    if (check_room(line))
        ft_printf("|room| ");
     if (check_link(line))
        ft_printf("|link| ");
    if (check_status(line) == 1)
        ft_printf("|start| ");
    if (check_status(line) == 2)
        ft_printf("|end| ");
    ft_printf("%s\n", line);
    return (0);
}
