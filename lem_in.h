/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 10:56:54 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/27 18:42:13 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <ncurses.h>

typedef struct s_room	t_room;

struct			s_room
{
	int		ant;
	char	status;
	int		x;
	int		y;
	char	*id;
	char	*father;
	t_room	*next;
};

typedef struct s_link	t_link;

struct			s_link
{
	char	*id;
	char	**branch;
	t_link	*next;
};

typedef struct s_path	t_path;

struct			s_path
{
	int		length;
	char	**branch;
	t_path	*next;
};

typedef struct	s_lemin
{
	short			status;
	short			direct;
	short			n_r_status;
	short			end_read;
	long			ants;
	long			curr_ant;
	int				r_count;
	int				l_count;
	int				p_count;
	unsigned int	opt;
	char			*ants_end;
	char			*start;
	char			*end;
	char			**queue;
	t_path			*path;
	t_room			*rooms;
	t_link			*links;

}				t_lemin;

short			check_link(t_lemin *lemin, char *line);
short			check_room(t_lemin *lemin, char *line);
int				check_line(t_lemin *lemin, char *line);
void			pull_se(t_lemin *lemin, char *line);

void			add_room(t_lemin *lemin, char *line);
t_room			*find_room(t_lemin *lemin, char *id);
void			check_start_end(t_lemin *lemin);

void			add_link(t_lemin *lemin, char *line);
t_link			*find_link(t_lemin *lemin, char *id);

void			add_to_queue(t_lemin *lemin, char *id);
void			clear_queue(t_lemin *lemin);
short			bfs(t_lemin *lemin);

void			add_path(t_lemin *lemin);
void			fill_path(t_lemin *lemin, t_path **path);
int				direct(t_lemin *lemin);

int				push_ants(t_lemin *lemin);

void			error(t_lemin *lemin, short code);

void			print_lemin(t_lemin *lemin);
void			print_path(t_lemin *lemin);
void			print_ants(t_lemin *lemin);

#endif
