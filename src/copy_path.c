/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bghandou <bghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:48:03 by bghandou          #+#    #+#             */
/*   Updated: 2019/05/02 18:27:46 by bghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	copy_path2(t_path **tmp, t_path **head, t_path **prv, t_path **tmp2)
{
	if (!*head)
	{
		*head = *tmp;
		*prv = *head;
		*tmp2 = *head;
	}
	else
	{
		(*prv)->next = *tmp;
		*prv = (*prv)->next;
		(*prv)->prev = *tmp2;
		*tmp2 = *tmp;
	}
}

t_path	*copy_path(t_path *path)
{
	t_path	*head;
	t_path	*tmp;
	t_path	*prv;
	t_path	*tmp2;

	tmp = NULL;
	head = NULL;
	prv = NULL;
	tmp2 = NULL;
	while (path)
	{
		if (!(tmp = (t_path*)malloc(sizeof(t_path))))
			return (NULL);
		tmp->room = path->room;
		tmp->next = NULL;
		tmp->prev = NULL;
		copy_path2(&tmp, &head, &prv, &tmp2);
		path = path->next;
	}
	return (head);
}
