/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 20:32:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/14 11:14:17 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void			add_to_queue(t_lemin *lemin, char *id)
{
	t_room	*room;
	char	**queue;
	int		i;

	room = find_room(lemin, id);
	queue = lemin->queue;
	i = 0;
	while (queue[i])
		i++;
	queue[i] = id;
	room->status = 'q';
}

void			clear_queue(t_lemin *lemin)
{
	char	**queue;
	int		i;

	queue = lemin->queue;
	i = -1;
	while (queue[++i])
		queue[i] = NULL;
}

static char		*get_from_queue(t_lemin *lemin)
{
	char	*res;
	int		i;

	res = lemin->queue[0];
	i = -1;
	while (++i < lemin->r_count - 1)
		lemin->queue[i] = lemin->queue[i + 1];
	return (res);
}

short			bfs(t_lemin *lemin)
{
	char	*id;
	t_room	*room;
	t_link	*link;
	int		i;

	if (!(id = get_from_queue(lemin)))
		return (-1);
	if (!ft_strcmp(id, lemin->end))
		return (1);
	room = find_room(lemin, id);
	room->status = 'w';
	link = find_link(lemin, room->id);
	i = -1;
	while (link->branch[++i])
	{
		if (find_room(lemin, link->branch[i])->status == 'o')
		{
			find_room(lemin, link->branch[i])->father = id;
			add_to_queue(lemin, link->branch[i]);
		}
	}
	return (0);
}
