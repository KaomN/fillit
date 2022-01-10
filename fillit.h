/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:35:57 by conguyen          #+#    #+#             */
/*   Updated: 2022/01/10 09:47:54 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

//delete!
#include <stdio.h>

/*
** tetrimino.c
*/

int		validate_tet(char **tets, int pos[4][2]);
void	transform_tet(char **tets, unsigned int ch, int x, int y);
int		check_tet(char **tets, int lines, unsigned int ch);
int		check_input(char **tets, int lines);

#endif