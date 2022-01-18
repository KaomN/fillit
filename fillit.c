/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:34:32 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/18 15:40:37 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_solution(char **map, int map_size)
{
	int	x;

	x = 0;
	while (x < map_size)
	{
		ft_putstr(map[x]);
		ft_putchar('\n');
		x++;
	}
}

static void	start_solver(t_tet *tetrimino)
{
	int		map_size;
	char	**map;

	map_size = get_min_map_size(tetrimino);
	map = create_map(map_size);
	while (!solver(tetrimino, map, map_size))
	{
		map_size++;
		map = increment_map(map, map_size);
	}
	print_solution(map, map_size);
	free_map(map, map_size);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_tet	*tetrimino;

	if (argc != 2)
		ft_putstr("Usage: ./fillit 'filename'\n");
	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (read_input(fd, &tetrimino) == 1)
	{
		start_solver(tetrimino);
		free_list(tetrimino);
	}
	else
		ft_putstr("error\n");
	return (0);
}
