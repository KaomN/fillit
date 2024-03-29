/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:11:26 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/18 17:22:46 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	validate_tet(char **tets, int pos[4][2])
{
	int	x;

	x = 0;
	while (++x < 4)
	{
		if (tets[pos[x][0]][pos[x][1]] == '#')
			return (0);
	}
	return (1);
}

static void	transform_tet(char **tets, unsigned int ch, int x, int y)
{
	if ((unsigned int)tets[x][y] == ch || tets[x][y] == '.')
		return ;
	tets[x][y] = ch;
	if (x > 0)
		transform_tet(tets, ch, x - 1, y);
	if (y > 0)
		transform_tet(tets, ch, x, y - 1);
	if (x < 3)
		transform_tet(tets, ch, x + 1, y);
	if (y < 3)
		transform_tet(tets, ch, x, y + 1);
}

static int	check_tet(char **tets, int lines)
{
	int	y;
	int	pos[4][2];
	int	c;
	int	x;

	c = -1;
	x = -1;
	while (++x < lines)
	{
		y = -1;
		while (tets[x][++y] != '\0')
		{
			if (tets[x][y] != '.' && tets[x][y] != '#')
				return (0);
			if (tets[x][y] == '#' && ++c < 4)
				pos[c][0] = x;
			if (tets[x][y] == '#' && c < 4)
				pos[c][1] = y;
		}
		if (y != 4 || (x == 3 && c != 3))
			return (0);
	}
	transform_tet(tets, 65, pos[0][0], pos[0][1]);
	return (validate_tet(tets, pos));
}

static int	check_input(char **tets, int lines)
{
	int	x;
	int	num_tets;
	int	y;

	x = -1;
	num_tets = 0;
	while (++x < lines)
	{
		y = 0;
		while (tets[x][y] != '\0')
			y++;
		if ((x + 1) % 5 != 0 && y != 4)
			return (0);
		if ((x + 1) % 5 == 0)
		{
			if (y != 0)
				return (0);
			if (!check_tet(&tets[x - 4], 4))
				return (0);
			num_tets++;
		}
	}
	if (num_tets * 5 - 1 != lines - 1)
		return (0);
	return (1);
}

int	read_input(const int fd, t_tet **tetrimino)
{
	char	**tetsarray;
	int		x;

	x = 0;
	tetsarray = (char **)malloc(sizeof(*tetsarray) * 131);
	if (!tetsarray)
		return (0);
	while (get_next_line(fd, &tetsarray[x]))
	{
		x++;
		if (x > 130)
			break ;
	}
	close(fd);
	if (x > 130)
	{
		free_array(tetsarray, x - 1);
		return (0);
	}
	if (check_input(tetsarray, x) == 0)
		ft_putstr("error\n");
	else
		*tetrimino = create_list(tetsarray, x, 65);
	free_array(tetsarray, x);
	return (1);
}
