/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:07:02 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/14 10:58:00 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	add_path(t_lemin *lemin)
{
	t_path	**path;
	int		i;

	path = &(lemin->path);
	while (*path)
		path = &(*path)->next;
	*path = (t_path *)malloc(sizeof(t_path));
	(*path)->length = 0;
	(*path)->branch = (char **)malloc(sizeof(char *) * lemin->r_count);
	i = -1;
	while (++i < lemin->r_count)
		(*path)->branch[i] = NULL;
	(*path)->next = NULL;
	(*path)->branch[0] = lemin->start;
	fill_path(lemin, path);
	lemin->p_count++;
}

void	fill_path(t_lemin *lemin, t_path **path)
{
	t_room	*room;
	int		size;

	size = -1;
	room = find_room(lemin, lemin->end);
	while (room->father)
	{
		size++;
		room = find_room(lemin, room->father);
	}
	size++;
	(*path)->length = size;
	room = find_room(lemin, lemin->end);
	while (room->father)
	{
		(*path)->branch[size] = room->id;
		room = find_room(lemin, room->father);
		size--;
	}
	(*path)->branch[size] = room->id;
}
