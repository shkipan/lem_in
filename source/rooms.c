/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 10:38:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/14 13:01:47 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		add_room(t_lemin *lemin, char *line)
{
	t_room	**temp;
	int		length;
	int		x;
	int		y;

	temp = &(lemin->rooms);
	x = ft_atoi(ft_strchr(line, ' '));
	y = ft_atoi(ft_strrchr(line, ' '));
	while (*temp)
	{
		if ((*temp)->x == x && (*temp)->y == y)
			error(lemin, 7);
		temp = &(*temp)->next;
	}
	*temp = (t_room *)malloc(sizeof(t_room));
	length = ft_strlen(line) - ft_strlen(ft_strchr(line, ' '));
	(*temp)->id = ft_strnew(length);
	(*temp)->id = ft_strncpy((*temp)->id, line, length);
	(*temp)->father = NULL;
	(*temp)->x = x;
	(*temp)->y = y;
	(*temp)->ant = 0;
	(*temp)->status = 'o';
	(*temp)->next = NULL;
	lemin->r_count += 1;
}

t_room		*find_room(t_lemin *lemin, char *id)
{
	t_room	*room;

	room = lemin->rooms;
	while (room && ft_strcmp(room->id, id))
		room = room->next;
	return (room);
}

void		check_start_end(t_lemin *lemin)
{
	t_link	*link;

	if (!lemin->start || !lemin->end || !lemin->r_count || !lemin->l_count)
		error(lemin, 1);
	link = find_link(lemin, lemin->start);
	if (!link->branch[0])
		error(lemin, 21);
	link = find_link(lemin, lemin->end);
	if (!link->branch[0])
		error(lemin, 22);
}
