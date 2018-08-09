/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:01:52 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/09 20:28:23 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_lemin	*init_lemin(int ac, char **av)
{
	t_lemin *ret;

	ret = (t_lemin *)malloc(sizeof(t_lemin));
	ret->ants = 0;
	ret->r_count = 0;
	ret->l_count = 0;
	ret->status = 'a';
	ret->opt = (ac == 2 && av[1][0] == '-') ? ft_options(av[1]) : 0;
	ret->rooms = NULL;
	ret->start = NULL;
	ret->end = NULL;
	return (ret);
}

int		main(int ac, char **av)
{
	t_lemin	*lemin;
	char	*line;
	t_room	*x;

	lemin = init_lemin(ac, av);
	while (get_next_line(0, &line))
	{
		check_line(lemin, line);
		if (lemin->n_r_status && line[0] != '#')
			pull_se(lemin, line);
		free(line);
	}
	if (!lemin->start || !lemin->end || !lemin->r_count || !lemin->l_count)
		error(lemin, 1);
	x = lemin->rooms;
	while (x)
	{
		ft_printf("room %s %d %d\n", x->id, x->x, x->y);
		x = x->next;
	}
	ft_printf("start = %s\nend = %s\nr_count = %d l_count = %d\n", lemin->start, lemin->end, lemin->r_count, lemin->l_count);
	if (CHECK_BIT(lemin->opt, 11))
		system("leaks lem-in");
	return (0);
}
