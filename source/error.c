/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 11:09:19 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/09 20:47:30 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void	freesher(t_lemin *lemin)
{
	t_room	*room;
	t_room	*temp;

	room = lemin->rooms;
	while (room)
	{
		temp = room;
		free(temp->id);
		room = room->next;
		free(temp);
	}
}

static void	room_errors(short code)
{
	if (code == 3)
		ft_printf("Room coordinates muxt be numbers\n");
	if (code == 4)
		ft_printf("Invalid symbol in room's definition\n");
	if (code == 5)
		ft_printf("Invalid number of spaces\n");
	if (code == 6)
		ft_printf("Room's name can't begin with L\n");
}

static void	link_errors(short code)
{
	if (code == 8)
		ft_printf("Invalid symbol in link definiton\n");
	if (code == 9)
		ft_printf("Wrong numbers of minuses in link\n");
	if (code == 10)
		ft_printf("Spaces in link definiton\n");
	if (code == 11)
		ft_printf("Room's definition can't be here\n");
	if (code == 12)
		ft_printf("Invalid link\n");
}

static void	parse_errors(t_lemin *lemin)
{
	if (!lemin->start)
		ft_printf("No start point\n");
	if (!lemin->end)
		ft_printf("No end point\n");
	if (!lemin->r_count)
		ft_printf("No rooms\n");
	if (!lemin->l_count)
		ft_printf("No links\n");
}

void		error(t_lemin *lemin, short code)
{
	ft_printf("ERROR\n");
	if (code == 1 && CHECK_FLAG(lemin->opt, 'e'))
		parse_errors(lemin);
	if (code == -1 && CHECK_FLAG(lemin->opt, 'e'))
		ft_printf("Ant's number must contain only digits\n");
	if (code == -2 && CHECK_FLAG(lemin->opt, 'e'))
		ft_printf("Ant's number must be a positive number\n");
	if (code == -3 && CHECK_FLAG(lemin->opt, 'e'))
		ft_printf("Ant's number must be a nonzero number\n");
	if (code == 41 && CHECK_FLAG(lemin->opt, 'e'))
		ft_printf("Second start has arrived\n");
	if (code == 42 && CHECK_FLAG(lemin->opt, 'e'))
		ft_printf("Second end has arrived\n");
	if (code > 2 && code < 7 && CHECK_FLAG(lemin->opt, 'e'))
		room_errors(code);
	if (code > 7 && code < 12 && CHECK_FLAG(lemin->opt, 'e'))
		link_errors(code);
	freesher(lemin);
	if (CHECK_FLAG(lemin->opt, 'l'))
		system("leaks lem-in");
	exit(1);
}
