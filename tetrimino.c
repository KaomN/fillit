/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:10:43 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/12 12:56:08 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list(t_tet *list)
{
	t_tet	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

static void	add_end(t_tet **alst, t_tet *new)
{
	t_tet	*temp;

	if (!(*alst))
		*alst = new;
	else
	{
		temp = *alst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	append_to_list(t_tet **list, int pos[4][2], int ch)
{
	t_tet	*newpiece;
	int		x;

	x = -1;
	newpiece = (t_tet *)malloc(sizeof(t_tet));
	if (newpiece == NULL)
		return ;
	newpiece->ch = ch;
	newpiece->next = NULL;
	while (++x < 4)
	{
		newpiece->pos[x][0] = pos[x][0];
		newpiece->pos[x][1] = pos[x][1];
	}
	add_end(list, newpiece);
}
