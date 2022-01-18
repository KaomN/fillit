/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:35:57 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/18 15:38:07 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <unistd.h>

typedef struct s_tet
{
	int				coords[4][2];
	int				ch;
	int				x;
	int				y;
	struct s_tet	*next;
}	t_tet;

/*
** validator.c
*/

int				read_input(const int fd, t_tet **tetrimino);

/*
** map.c
*/

unsigned int	get_min_map_size(t_tet *tetrimino);
char			**create_map(unsigned int size);
char			**increment_map(char **map, unsigned int size);

/*
** tetrimino.c
*/

t_tet			*create_list(char **tetarray, int lines, int ch);

/*
** free.c
*/

void			free_list(t_tet *list);
void			free_array(char** tetsarray, int lines);
void			free_map(char **map, int map_size);
void			free_coords(int	**coords);

/*
** solve.c
*/

int				solver(t_tet *tetrimino, char **map, int map_size);

#endif