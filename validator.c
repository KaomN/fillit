/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:11:26 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/12 13:03:42 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	validate_tet(char **tets, int pos[4][2], t_tet **list, int ch)
{
	int	x;
	int	s_x;
	int	s_y;

	x = 0;
	s_x = pos[0][0];
	s_y = pos[0][1];
	while (++x < 4)
	{
		if (tets[pos[x][0]][pos[x][1]] == '#')
			return (-1);
		if (s_x > pos[x][0])
			s_x = pos[x][0];
		if (s_y > pos[x][1])
			s_y = pos[x][1];
	}
	x = -1;
	while (++x < 4)
	{
		pos[x][0] = pos[x][0] - s_x;
		pos[x][1] = pos[x][1] - s_y;
	}
	append_to_list(list, pos, ch);
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

static int	check_tet(char **tets, int lines, unsigned int ch, t_tet **list)
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
				return (-1);
			if (tets[x][y] == '#' && ++c < 4)
				pos[c][0] = x;
			if (tets[x][y] == '#' && c < 4)
				pos[c][1] = y;
		}
		if (y != 4 || (x == 3 && c != 3))
			return (-1);
	}
	transform_tet(tets, ch, pos[0][0], pos[0][1]);
	return (validate_tet(tets, pos, list, ch));
}

int	check_input(char **tets, int lines, t_tet **list)
{
	int				x;
	unsigned int	ch;
	int				num_tets;
	int				y;

	x = -1;
	ch = 65;
	num_tets = 0;
	while (++x <= lines)
	{
		y = 0;
		while (x != lines && tets[x][y] != '\0')
			y++;
		if (y != 4 && (x + 1) % 5 != 0)
			return (-1);
		if ((x + 1) % 5 == 0 && !check_tet(&tets[x - 4], 4, ch++, list))
			return (-1);
		if ((x + 1) % 5 == 0)
			num_tets++;
	}
	if (num_tets * 5 - 1 != lines)
		return (-1);
	return (1);
}

// int	check_input(char **tets, int lines)
// {
// 	int				x;
// 	int				check;
// 	unsigned int	ch;
// 	int				num_tets;

// 	x = -1;
// 	check = 1;
// 	ch = 65;
// 	num_tets = 0;
// 	while (++x <= lines)
// 	{
// 		if (check == 5)
// 		{
// 			num_tets++;
// 			check = 0;
// 		}
// 		if (check == 0 && x != lines && tets[x][0] != '\0')
// 			return (-1);
// 		if (check == 0 && check_tet(&tets[x - 4], 4, ch++) == -1)
// 			return (-1);
// 		check++;
// 	}
// 	if (num_tets * 5 - 1 != lines)
// 		return (-1);
// 	return (1);
// }
