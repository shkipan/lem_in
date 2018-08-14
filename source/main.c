/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:01:52 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/14 11:19:29 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static t_lemin	*init_lemin(int ac, char **av)
{
	t_lemin *ret;

	ret = (t_lemin *)malloc(sizeof(t_lemin));
	ret->ants = 0;
	ret->status = 'a';
	ret->r_count = 0;
	ret->l_count = 0;
	ret->p_count = 0;
	ret->opt = (ac == 2 && av[1][0] == '-') ? ft_options(av[1]) : 0;
	ret->rooms = NULL;
	ret->path = NULL;
	ret->start = NULL;
	ret->end = NULL;
	return (ret);
}

static void		read_lemin(t_lemin *lemin)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		check_line(lemin, line);
		if (lemin->n_r_status && line[0] != '#')
			pull_se(lemin, line);
		free(line);
	}
	check_start_end(lemin);
}

static void		lock_rooms(t_lemin *lemin)
{
	t_path	*path;
	int		i;

	path = lemin->path;
	while (path)
	{
		i = -1;
		while (path->branch[++i])
			if (ft_strcmp(path->branch[i], lemin->start) &&
					ft_strcmp(path->branch[i], lemin->end))
				find_room(lemin, path->branch[i])->status = 'w';
		path = path->next;
	}
}

static int		spin_lemin(t_lemin *lemin)
{
	t_room	*room;
	int		r;

	add_to_queue(lemin, lemin->start);
	while (!(r = bfs(lemin)))
		NULL;
	if (r == -1 && !lemin->p_count)
		error(lemin, 20);
	if (r == -1 && lemin->p_count)
		return (0);
	add_path(lemin);
	room = lemin->rooms;
	while (room)
	{
		room->status = 'o';
		room->father = NULL;
		room = room->next;
	}
	lock_rooms(lemin);
	clear_queue(lemin);
	return (1);
}

int				main(int ac, char **av)
{
	t_lemin	*lemin;

	lemin = init_lemin(ac, av);
	read_lemin(lemin);
	while (spin_lemin(lemin))
		NULL;
	print_lemin(lemin);
	if (CHECK_FLAG(lemin->opt, 'l'))
		system("leaks lem-in");
	return (0);
}
