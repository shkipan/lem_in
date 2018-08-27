/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_start_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:11:48 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/27 12:11:52 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	pull_se(t_lemin *lemin, char *line)
{
	char	*temp;
	size_t	length;

	if (lemin->start && lemin->n_r_status == 1)
		error(lemin, 41);
	if (lemin->end && lemin->n_r_status == 2)
		error(lemin, 42);
	if (!(temp = ft_strchr(line, ' ')))
		error(lemin, 16);
	length = ft_strlen(line) - ft_strlen(temp);
	if (lemin->n_r_status == 1)
	{
		lemin->start = ft_strnew(length);
		ft_strncpy(lemin->start, line, length);
	}
	if (lemin->n_r_status == 2)
	{
		lemin->end = ft_strnew(length);
		ft_strncpy(lemin->end, line, length);
	}
	lemin->n_r_status = 0;
}
