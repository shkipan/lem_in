/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 10:41:06 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/14 11:28:53 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	print_lemin(t_lemin *lemin)
{
	t_link	*x;
	t_path	*xx;
	t_room	*room;
	int		i;
	int		j;

	room = lemin->rooms;
	while (room)
	{
		if (!ft_strcmp(room->id, lemin->start))
			ft_printf("%{red}s %s|%d %d|%c %s\n", "start", room->id, room->x,
					room->y, room->status, room->father);
		else if (!ft_strcmp(room->id, lemin->end))
			ft_printf("%{grn}s %s|%d %d|%c %s\n", "end", room->id, room->x,
					room->y, room->status, room->father);
		else
			ft_printf("%{yel}s %s|%d %d|%c %s\n", "room", room->id, room->x,
					room->y, room->status, room->father);
		room = room->next;
	}
	x = lemin->links;
	while (x)
	{
		ft_printf("link %{blu}s|", x->id);
		i = -1;
		while (++i < lemin->r_count && x->branch[i])
			ft_printf("%s|", x->branch[i]);
		ft_printf("\n");
		x = x->next;
	}
	ft_printf("queue |");
	i = -1;
	while (++i < lemin->r_count && lemin->queue[i])
		ft_printf("%s->", lemin->queue[i]);
	ft_printf("|\n");
	xx = lemin->path;
	j = -1;
	ft_printf("%d pathways found\n", lemin->p_count);
	while (++j < lemin->p_count)
	{
		ft_printf("  %s %d %s%d||", "path", j, "length=", xx->length);
		i = -1;
		while (++i < lemin->r_count && xx->branch[i])
			ft_printf("%s->", xx->branch[i]);
		ft_printf("\n");
		xx = xx->next;
	}
	ft_printf("\n");
}
