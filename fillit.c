/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:34:32 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/10 15:18:40 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	get_size(unsigned int num_tets)
{
	unsigned int	size;
	unsigned int	squares_required;

	squares_required = num_tets * 4;
	size = 4;
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

int	main(void)
{
	// char			**tets;
	// int				fd;
	// int				x;
	unsigned int	size;
	// char			**map;

	// x = 0;
	// fd = open("test", O_RDONLY);
	size = get_size(4);
	printf("[%d]", size);
	// map = create_map(size);
	// for (unsigned int x = 0; x < size; x++)
	// 	printf("[%s]\n", map[x]);
	// size++;
	// map = increment_map(map, size);
	// for (unsigned int x = 0; x < size; x++)
	// 	printf("[%s]\n", map[x]);
	// for (unsigned int x = 0; x < size; x++)
	// 	free(map[x]);
	// free(map);
	// tets = (char **)malloc(sizeof(*tets) * 105);
	// if (!tets)
	// 	return (-1);
	// while (get_next_line(fd, &tets[x]))
	// 	x++;
	// close(fd);
	// printf("Validate returned: [%d]\n", check_input(tets, x));
	// for (int z = 0; z <= x; z++)
	// 	printf("[%s]\n", tets[z]);
	// while (x >= 0)
	// 	free(tets[x--]);
	// free(tets);
	return (0);
}
