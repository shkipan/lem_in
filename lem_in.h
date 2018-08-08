#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
# include "libft/libft.h"

typedef struct  s_rooms t_rooms;

struct  s_rooms
{
    char    *id;
    int     x;
    int     y;
    char    visited;
    char    status;
    t_rooms *n_room;
};

typedef struct  s_links t_links;

struct  s_links
{
    char    *id;
    char    **links;
    t_links *n_link;
};

typedef struct  s_lemin
{
    int     ants;
    t_rooms *rooms;
    t_links *links;
    short   status;
}               t_lemin;

int     check_ants_number(t_lemin *lemin, char *line);
int     check_line(t_lemin *lemin, char *line);

#endif