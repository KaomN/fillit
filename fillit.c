/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:34:32 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/11 09:06:30 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(void)
{
	// char			**tets;
	// int				fd;
	// int				x;
	unsigned int	size;
	// char			**map;

	// x = 0;
	// fd = open("test", O_RDONLY);
	size = get_min_map_size(4);
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
