/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:53:20 by myernaux          #+#    #+#             */
/*   Updated: 2017/02/26 15:17:00 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_zoom(t_point *fp)
{
	t_point		*temp;
	t_point		*temp2;
	t_point		*temp3;

	temp3 = new_point(fp->x, fp->y, 0, 0);
	temp = fp;
	temp2 = fp;
	while (temp)
	{
		temp2 = temp;
		while (temp2)
		{
			temp2->x *= 1.01;
			temp2->y *= 1.01;
			temp2 = temp2->nextx;
		}
		temp = temp->nexty;
	}
	test3(fp, matrice_translate_rl, (temp3->x - fp->x));
	test3(fp, matrice_translate_ud, (temp3->y - fp->y));
	free(temp3);
}

void	ft_set_zoom(t_point *fp)
{
	while (ft_maplength(fp) < 750 && ft_maphight(fp) < 600)
	{
		ft_zoom(fp);
	}
}
