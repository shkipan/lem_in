/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:04:11 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/27 13:05:05 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static short	check_ants(t_lemin *lemin, char *line)
{
	int		i;
	int		number;

	i = -1;
	while (line[++i])
		if (!(ft_isdigit(line[i])) && (line[i] != '-'))
			error(lemin, -1);
	if ((number = ft_atoi(line)) < 0)
		error(lemin, -2);
	if (number == 0)
		error(lemin, -3);
	lemin->ants = number;
	lemin->status = 'r';
	return (0);
}

short			check_link(t_lemin *lemin, char *line)
{
	int		i;
	char	flag;

	if (lemin->status == 'l' && !check_room(lemin, line))
		return (11);
	lemin->status += 0;
	flag = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			flag += 1;
		if (line[i] == ' ')
			return (10);
		if (!ft_isprint(line[i]))
			return (8);
		i++;
	}
	if (flag != 1)
		return (9);
	if (lemin->status == 'l')
		add_link(lemin, line);
	lemin->status = 'l';
	return (0);
}

short			check_room(t_lemin *lemin, char *line)
{
	int		i;
	char	flag;

	if (line[0] == 'L')
		return (6);
	if (lemin->status == 'r' && !check_link(lemin, line))
		return (0);
	flag = 0;
	i = 0;
	while (line[i])
	{
		if (flag > 0 && line[i] != ' ' && line[i] != '-'
				&& !ft_isdigit(line[i]))
			return (3);
		if (!ft_isprint(line[i]))
			return (4);
		if (line[i] == ' ')
			flag++;
		i++;
	}
	if (flag != 2 || (ft_strrchr(line, ' ') - ft_strchr(line, ' ') == 1))
		return (5);
	if (lemin->status == 'r')
		add_room(lemin, line);
	return (0);
}

static short	check_status(t_lemin *lemin, char *line, short *ret)
{
	int x;

	x = 0;
	if ((!ft_strcmp(line, "##start") && (lemin->start || lemin->n_r_status)) ||
			(!ft_strcmp(line, "##end") && (lemin->end || lemin->n_r_status)))
	{
		*ret = (line[2] == 's') ? 41 : 42;
		x = 1;
	}
	if (!ft_strcmp(line, "##start") && !lemin->n_r_status)
		lemin->n_r_status = 1;
	if (!ft_strcmp(line, "##end") && !lemin->n_r_status)
		lemin->n_r_status = 2;
	if (!ft_strcmp(line, "##errors"))
		lemin->opt |= SET_BIT(0, 'e' - 'a');
	if (!ft_strcmp(line, "##leaks"))
		lemin->opt |= SET_BIT(0, 'l' - 'a');
	if (!ft_strcmp(line, "##results"))
		lemin->opt |= SET_BIT(0, 'r' - 'a');
	return (x);
}

int				check_line(t_lemin *lemin, char *line)
{
	short	ret;

	ret = 0;
	ft_printf("%s\n", line);
	if (line[0] == '#')
	{
		if (check_status(lemin, line, &ret))
			error(lemin, ret);
		return (0);
	}
	if (!lemin->ants)
		return (check_ants(lemin, line));
	if (lemin->status == 'r' && (ret = check_room(lemin, line)) > 0)
		error(lemin, ret);
	if (lemin->status == 'l' && (ret = check_link(lemin, line)) > 0)
		error(lemin, ret);
	return (0);
}
