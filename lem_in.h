/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 10:56:54 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/09 20:34:39 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct s_link	t_link;

struct			s_link
{
	char	*id;
	char	**branches;
	t_link	*next;
};

typedef struct s_room	t_room;

struct			s_room
{
	char	*id;
	int		x;
	int		y;
	char	status;
	t_room	*next;
};

typedef struct	s_lemin
{
	char			status;
	short			n_r_status;
	int				ants;
	int				r_count;
	int				l_count;
	unsigned int	opt;
	char			*start;
	char			*end;
	t_room			*rooms;
	t_link			*links;
}				t_lemin;

short			check_link(t_lemin *lemin, char *line);
short			check_room(t_lemin *lemin, char *line);
int				check_line(t_lemin *lemin, char *line);
void			pull_se(t_lemin *lemin, char *line);

void			add_room(t_room **rooms, int *count, char *line);
//void			add_link(t_lemin *lemin, char *line);

void			error(t_lemin *lemin, short code);

#endif
