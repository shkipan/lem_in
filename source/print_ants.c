/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:39:19 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/24 19:25:54 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	search_lem(t_lemin *lemin, int i, int c)
{
	t_path	*path;
	int		k;

	path = lemin->path;
	while (path)
	{
		k = 1;
		while (k < path->length)
		{
			if (find_room(lemin, path->branch[k])->ant == i &&
					ft_strcmp(path->branch[k], lemin->end))
				c = ft_printf("%sL%d-%s",
						(c) ? " " : "", i, path->branch[k]);
			k++;
		}
		path = path->next;
	}
	return (c);
}

void		print_ants(t_lemin *lemin)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	while (++i < lemin->curr_ant)
	{
		if (lemin->ants_end[i] == 'a')
		{
			c = ft_printf("%sL%d-%s", (c) ? " " : "", i, lemin->end);
			lemin->ants_end[i] = '1';
		}
		else if (lemin->ants_end[i] == '0')
			c = search_lem(lemin, i, c);
	}
	ft_printf("\n");
}
