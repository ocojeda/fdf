/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:42:19 by tfaure            #+#    #+#             */
/*   Updated: 2017/02/24 16:58:42 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		matrice_rotate_x(t_point *temp, int angle)
{
	double	y;
	double	rangle;

	y = temp->y;
	rangle = angle * RADIANCONV;
	temp->y = y * cos(rangle) + temp->z * -(sin(rangle));
	temp->z = y * sin(rangle) + temp->z * cos(rangle);
}

void	matrice_rotate_y(t_point *temp, int angle)
{
	double	x;
	double	rangle;
	
	x = temp->x;
	rangle = angle * RADIANCONV;
	temp->x = temp->x * cos(rangle) + temp->z * sin(rangle);
	temp->z = -sin(rangle) * x + temp->z * cos(rangle);
}

void	matrice_rotate_z(t_point *temp, int angle)
{
	double	x;
	double	rangle;
	
	x = temp->x;
	rangle = angle * RADIANCONV;
	temp->x = x * cos(rangle) + temp->y * -(sin(rangle));
	temp->y = x * sin(rangle) + temp->y * cos(rangle);
}

void	matrice_translate_rl(t_point *temp, int dist)
{
	temp->x = temp->x + dist;
}

void	matrice_translate_ud(t_point *temp, int dist)
{
	temp->y = temp->y + dist;
}
