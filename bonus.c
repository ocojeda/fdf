/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:53:20 by myernaux          #+#    #+#             */
/*   Updated: 2017/02/18 14:17:37 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_point *fp)
{
	fp->x *= 2;
	fp->y *= 2;
}

void	ft_movedown(t_point *fp)
{
	fp->y += 1;
}

void	ft_moveup(t_point *fp)
{
	fp->y -= 1;
}

void	ft_mover(t_point *fp)
{
	fp->x += 1;
}

void	ft_movel(t_point *fp)
{
	fp->x -= 1;
}
