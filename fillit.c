/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:34:32 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/12 12:51:20 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



int	main(void)
{
	char			**tets;
	int				fd;
	int				x;
	t_tet			*list;
	t_tet			*listhead;
	// unsigned int	size;
	// char			**map;

	x = 0;
	fd = open("test", O_RDONLY);
	tets = (char **)malloc(sizeof(*tets) * 105);
	list = NULL;
	if (!tets)
		return (-1);
	while (get_next_line(fd, &tets[x]))
		x++;
	close(fd);
	printf("Validate returned: [%d]\n", check_input(tets, x, &list));
	// size = get_min_map_size(5);
	// printf("%u", size);
	// map = create_map(size);
	// for (int z = 0; z <= x; z++)
	// 	printf("[%s]\n", tets[z]);
	while (x >= 0)
		free(tets[x--]);
	free(tets);
	listhead = list;
	while(list)
	{
		printf("listch: %d\n", list->ch);
		list = list->next;
	}
	free_list(listhead);
	// for (unsigned int x = 0; x < size; x++)
	// 	printf("[%s]\n", map[x]);
	// for (unsigned int x = 0; x < size; x++)
	// 	free(map[x]);
	// free(map);
	return (0);
}
