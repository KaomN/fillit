/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:48:21 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/18 17:23:00 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	get_min_map_size(t_tet *tetrimino)
{
	unsigned int	size;
	unsigned int	squares_required;
	unsigned int	num_tets;
	t_tet			*tmp;

	tmp = tetrimino;
	num_tets = 0;
	while (tmp)
	{
		num_tets++;
		tmp = tmp->next;
	}
	squares_required = num_tets * 4;
	size = 2;
	while (size * size < squares_required)
		size++;
	return (size);
}

char	**create_map(unsigned int size)
{
	char			**map;
	unsigned int	x;

	map = (char **)malloc(sizeof(*map) * size + 1);
	if (map == NULL)
		return (NULL);
	x = 0;
	while (x < size)
	{
		map[x] = ft_strnew(size + 1);
		if (map[x] == NULL)
			return (NULL);
		ft_memset(map[x], '.', size);
		x++;
	}
	map[x] = NULL;
	return (map);
}

char	**increment_map(char **map, unsigned int size)
{
	char			**new_map;
	unsigned int	x;

	new_map = (char **)malloc(sizeof(*new_map) * size + 1);
	if (new_map == NULL)
		return (NULL);
	x = 0;
	while (x < size)
	{
		new_map[x] = ft_strnew(size + 1);
		if (new_map[x] == NULL)
			return (NULL);
		ft_memset(new_map[x], '.', size);
		free(map[x]);
		x++;
	}
	new_map[x] = NULL;
	free(map);
	return (new_map);
}
