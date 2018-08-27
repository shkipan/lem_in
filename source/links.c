/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:12:27 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/27 18:42:16 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"
#define LBR_I link->branch[i]

static void	create_links(t_lemin *lemin)
{
	t_room	*temp;
	t_link	**link;
	int		i;

	temp = lemin->rooms;
	link = &(lemin->links);
	while (temp)
	{
		*link = (t_link *)malloc(sizeof(t_link));
		(*link)->id = ft_strdup(temp->id);
		(*link)->branch = (char **)malloc(sizeof(char *) * lemin->r_count);
		i = -1;
		while (++i < lemin->r_count)
			(*link)->branch[i] = NULL;
		(*link)->next = NULL;
		link = &(*link)->next;
		temp = temp->next;
	}
	lemin->queue = (char **)malloc(sizeof(char *) * lemin->r_count);
	i = -1;
	while (++i < lemin->r_count)
		lemin->queue[i] = NULL;
}

static int	add_rooms_to_link(t_lemin *lemin, char *n1, char *n2)
{
	t_room	*room1;
	t_room	*room2;
	t_link	*link;
	int		i;

	if (!(room1 = find_room(lemin, n1)) ||
			!(room2 = find_room(lemin, n2)))
	{
		lemin->end_read = 1;
		return (0);
	}
	link = find_link(lemin, n1);
	i = 0;
	while (i < lemin->r_count && LBR_I && ft_strcmp(LBR_I, n2))
		i++;
	if (!link->branch[i])
		link->branch[i] = ft_strdup(n2);
	link = find_link(lemin, n2);
	i = 0;
	while (i < lemin->r_count && LBR_I && ft_strcmp(LBR_I, n1))
		i++;
	if (!link->branch[i])
		link->branch[i] = ft_strdup(n1);
	return (1);
}

void		add_link(t_lemin *lemin, char *line)
{
	char	*n1;
	char	*n2;
	int		len;
	t_link	**temp;

	if (lemin->r_count == 0)
		error(lemin, 1);
	if (!lemin->links)
		create_links(lemin);
	temp = &(lemin->links);
	n2 = ft_strchr(line, '-') + 1;
	n1 = line;
	len = ft_strlen(line) - ft_strlen(n2) - 1;
	n1[len] = '\0';
	if (!ft_strcmp(n1, n2))
		error(lemin, 15);
	if (add_rooms_to_link(lemin, n1, n2))
		lemin->l_count += 1;
}

t_link		*find_link(t_lemin *lemin, char *id)
{
	t_link *link;

	link = lemin->links;
	while (ft_strcmp(link->id, id))
		link = link->next;
	return (link);
}
