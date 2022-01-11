/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:35:57 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/11 12:54:04 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <unistd.h>

//delete!
# include <stdio.h>

// typedef struct s_tetrimino
// {
// 	int				pos[4][2];
// 	struct s_tet	*next;
// }	t_tetrimino;

/*
** tetrimino.c
*/

int				validate_tet(char **tets, int pos[4][2]);
void			transform_tet(char **tets, unsigned int ch, int x, int y);
int				check_tet(char **tets, int lines, unsigned int ch);
int				check_input(char **tets, int lines);

/*
** map.c
*/

unsigned int	get_min_map_size(unsigned int num_tets);
char			**create_map(unsigned int size);
char			**increment_map(char **map, unsigned int size);

#endif