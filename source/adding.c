/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:12:27 by dskrypny          #+#    #+#             */
/*   Updated: 2018/08/09 20:30:07 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		add_room(t_room **rooms, int *count, char *line)
{
	t_room	**temp;
	int		length;

	temp = rooms;
	while (*temp)
		temp = &(*temp)->next;
	*temp = (t_room *)malloc(sizeof(t_room));
	length = ft_strlen(line) - ft_strlen(ft_strchr(line, ' '));
	(*temp)->id = ft_strnew(length);
	(*temp)->id = ft_strncpy((*temp)->id, line, length);
	(*temp)->x = ft_atoi(ft_strchr(line, ' '));
	(*temp)->y = ft_atoi(ft_strrchr(line, ' '));
	(*temp)->next = NULL;
	*count += 1;
}
/*
void		create_links(t_lemin *lemin)
{
	t_room	*temp;
	t_links	*link;

	temp = lemin->rooms;
	link = lemin->links;
	while (temp)
	{
		link = (t_link *)malloc(sizeof(t_link));
		link->id = temp->id;
		link->branches = (char **)malloc(sizeof(char *) * lemin->
		link->next = NULL;
		temp = temp->next;
		link = link->next;
	}

void		add_link(t_link **links, t_lemin *lemin, char *line)
{
	char	*n1;
	char	*n2;
	int		len;
	t_link	**temp;

	if (!(*links))
		create_links(lemin);
	temp = links;
	n2 = ft_strchr(line, '-') + 1;
	n1 = line;
	len = ft_strlen(line) - ft_strlen(n2) - 1;
	while (*temp)
	{
		if ((*temp)->id
		temp = &(*temp)->next;
	}
}
*/
