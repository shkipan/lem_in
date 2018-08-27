/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:39:19 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/24 19:29:07 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	print_end(t_lemin *lemin, int c, int i, t_path *path)
{
	find_room(lemin, path->branch[i])->ant += 1;
	lemin->ants_end[find_room(lemin, path->branch[i - 1])->ant] = 'a';
	find_room(lemin, path->branch[i - 1])->ant = 0;
	return (c);
}

static int	print_move(t_lemin *lemin, int c, int i, t_path *path)
{
	find_room(lemin, path->branch[i])->ant =
		find_room(lemin, path->branch[i - 1])->ant;
	find_room(lemin, path->branch[i - 1])->ant = 0;
	return (c);
}

static int	move_ants(t_lemin *lemin)
{
	t_path	*path;
	int		i;
	int		c;

	c = 0;
	path = lemin->path;
	while (path)
	{
		i = path->length + 1;
		while (--i > 1)
		{
			if (!ft_strcmp(lemin->end, path->branch[i]) &&
					find_room(lemin, path->branch[i - 1])->ant > 0)
			{
				c = print_end(lemin, c, i, path);
			}
			if (find_room(lemin, path->branch[i])->ant == 0 &&
					find_room(lemin, path->branch[i - 1])->ant != 0)
			{
				c = print_move(lemin, c, i, path);
			}
		}
		path = path->next;
	}
	return (c);
}

static int	print_direct(t_lemin *lemin)
{
	while (lemin->curr_ant <= lemin->ants)
	{
		ft_printf("L%d-%s%s", lemin->curr_ant, lemin->end,
				(lemin->curr_ant == lemin->ants) ? "\n" : " ");
		lemin->curr_ant++;
	}
	return (0);
}

int			push_ants(t_lemin *lemin)
{
	t_path	*path;
	int		i;
	int		c;

	i = -1;
	if (find_room(lemin, lemin->end)->ant == lemin->ants)
		return (0);
	path = lemin->path;
	if (lemin->direct)
		return (print_direct(lemin));
	c = move_ants(lemin);
	while (path)
	{
		if (find_room(lemin, path->branch[1])->ant == 0 &&
				lemin->curr_ant <= lemin->ants &&
				find_room(lemin, path->branch[0])->ant > 0)
		{
			find_room(lemin, path->branch[1])->ant = lemin->curr_ant;
			find_room(lemin, path->branch[0])->ant--;
			lemin->curr_ant++;
		}
		path = path->next;
	}
	print_ants(lemin);
	return (1);
}
