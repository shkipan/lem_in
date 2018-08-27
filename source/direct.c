/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 18:09:54 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/24 18:14:20 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		direct(t_lemin *lemin)
{
	if (!ft_strcmp(lemin->path->branch[0], lemin->start) &&
			!ft_strcmp(lemin->path->branch[1], lemin->end))
		return (1);
	return (0);
}
