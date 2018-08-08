#include "lem_in.h"

void     error(int code)
{
    ft_printf("ERROR\n");
    if (code == -1)
        ft_printf("Ant's number must contain only digits\n");
    if (code == -2)
        ft_printf("Ant's number must be a positive number\n");
    if (code == -3)
        ft_printf("Ant's number must be a nonzero number\n");
    exit(1);
}

int     main(void)
{
    t_lemin lemin;
    char    *line;
    int     c;

    get_next_line(0, &line);
    if ((c = check_ants_number(&lemin, line)) != 0)
        error(c);
    free(line);
    while (get_next_line(0, &line))
    {
        if ((c = check_line(&lemin, line)) != 0)
            error(c);
        free(line);
    }
    return (0);
}