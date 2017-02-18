/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:42:19 by tfaure            #+#    #+#             */
/*   Updated: 2017/02/18 19:41:21 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void		matrice_rotate_x(t_point *temp)
{
	int y;
	double rangle;

	y = temp->y;
	rangle = ANGLE * RADIANCONV;
	temp->y = y * cos(rangle) + temp->z * -(sin(rangle));
	temp->z = y * sin(rangle) + temp->z * cos(rangle);
}

void	matrice_rotate_y(t_point *temp)
{
	int x;
	double rangle;
	
	x = temp->x;
	rangle = ANGLE * RADIANCONV;
	temp->x = temp->x * cos(rangle) + temp->z * sin(rangle);
	temp->z = -sin(rangle) * x + temp->z * cos(rangle);
}

/*
void	matrice_rotate_z(t_point *temp)
{
	temp->x = x * cos(45) + temp->y * -(sin(45));
	temp->y = x * sin(45) + temp->y * cos(45);
}*/

void	matrice_translate(t_point *temp, int x)
{
	temp->x = x + R_TRANSLATE;
	temp->y = temp->y + R_TRANSLATE;
}
