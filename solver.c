/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:29:55 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/18 15:00:30 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_bounds_x(t_tet *tetrimino, int map_size)
{
	if (tetrimino->coords[0][0] + tetrimino->x < map_size &&
		tetrimino->coords[1][0] + tetrimino->x < map_size &&
		tetrimino->coords[2][0] + tetrimino->x < map_size &&
		tetrimino->coords[3][0] + tetrimino->x < map_size)
		return (1);
	return (0);
}

static int	check_bounds_y(t_tet *tetrimino, int map_size)
{
	if (tetrimino->coords[0][1] + tetrimino->y < map_size &&
		tetrimino->coords[1][1] + tetrimino->y < map_size &&
		tetrimino->coords[2][1] + tetrimino->y < map_size &&
		tetrimino->coords[3][1] + tetrimino->y < map_size)
		return (1);
	return (0);
}

static int	check_overlap(t_tet *tetrimino, char **map)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	x = tetrimino->coords[0][0] + tetrimino->x;
	y = tetrimino->coords[0][1] + tetrimino->y;
	while (z <= 3 && map[y][x] == '.')
	{
		z++;
		x = tetrimino->coords[z][0] + tetrimino->x;
		y = tetrimino->coords[z][1] + tetrimino->y;
	}
	if (z == 4)
		return (0);
	return (1);
}

static void	place_remove(t_tet *tetrimino, char **map, int ch)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	while (z <= 3)
	{
		x = tetrimino->coords[z][0] + tetrimino->x;
		y = tetrimino->coords[z][1] + tetrimino->y;
		map[y][x] = ch;
		z++;
	}
}

int	solver(t_tet *tetrimino, char **map, int map_size)
{
	if (!tetrimino)
		return (1);
	tetrimino->y = 0;
	tetrimino->x = 0;
	while (check_bounds_y(tetrimino, map_size))
	{
		while (check_bounds_x(tetrimino, map_size))
		{
			if (!check_overlap(tetrimino, map))
			{
				place_remove(tetrimino, map, tetrimino->ch);
				if (solver(tetrimino->next, map, map_size))
					return (1);
				else
					place_remove(tetrimino, map, '.');
			}
			tetrimino->x++;
		}
		tetrimino->x = 0;
		tetrimino->y++;
	}
	return (0);
}
