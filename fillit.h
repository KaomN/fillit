/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:35:57 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/12 12:48:16 by conguyen         ###   ########.fr       */
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

typedef struct s_tet
{
	int				pos[4][2];
	int				ch;
	struct s_tet	*next;
}	t_tet;

/*
** validator.c
*/

int				check_input(char **tets, int lines, t_tet **list);

/*
** map.c
*/

unsigned int	get_min_map_size(unsigned int num_tets);
char			**create_map(unsigned int size);
char			**increment_map(char **map, unsigned int size);

/*
** tetrimino.c
*/

void			append_to_list(t_tet **list, int pos[4][2], int ch);
void			free_list(t_tet *list);

#endif