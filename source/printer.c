/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 10:41:06 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/27 12:14:16 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void		print_rooms(t_lemin *lemin)
{
	t_room	*room;

	room = lemin->rooms;
	while (room)
	{
		if (!ft_strcmp(room->id, lemin->start))
			ft_printf("%-{red}5s %s|%d %d|\n", "start", room->id, room->x,
					room->y);
		else if (!ft_strcmp(room->id, lemin->end))
			ft_printf("%-{grn}5s %s|%d %d|\n", "end", room->id, room->x,
					room->y);
		else
			ft_printf("%-{yel}5s %s|%d %d|\n", "room", room->id, room->x,
					room->y);
		room = room->next;
	}
}

static void		print_pathes(t_lemin *lemin)
{
	t_path	*xx;
	int		j;
	int		i;

	xx = lemin->path;
	j = -1;
	ft_printf("%{grn}d %{grn}s\n", lemin->p_count, "pathaways found");
	while (++j < lemin->p_count)
	{
		ft_printf("  %{grn}s %{grn}d %{grn}s%{grn}d||",
				"path", j, "length=", xx->length);
		i = -1;
		while (++i < lemin->r_count && xx->branch[i])
			ft_printf("%{grn}s%{grn}s", xx->branch[i],
					(xx->branch[i + 1]) ? "->" : "");
		ft_printf("\n");
		xx = xx->next;
	}
}

void			print_lemin(t_lemin *lemin)
{
	t_link	*x;
	int		i;

	print_rooms(lemin);
	x = lemin->links;
	while (x)
	{
		ft_printf("%{blu}s %{blu}s|", "link", x->id);
		i = -1;
		while (++i < lemin->r_count && x->branch[i])
			ft_printf("%s|", x->branch[i]);
		ft_printf("\n");
		x = x->next;
	}
	print_pathes(lemin);
}
