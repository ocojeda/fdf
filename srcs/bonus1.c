/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:38:15 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/03/03 09:37:30 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	**ft_iscolor(char *str)
{
	if (ft_strchr(str, ','))
		return (ft_strsplit(str, ','));
	return (0);
}

void	ft_zoom_out(t_point *fp)
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
			temp2->x /= 1.05;
			temp2->y /= 1.05;
			temp2 = temp2->nextx;
		}
		temp = temp->nexty;
	}
	test3(fp, matrice_translate_rl, (temp3->x - fp->x));
	test3(fp, matrice_translate_ud, (temp3->y - fp->y));
	free(temp3);
}

void	ft_higher(t_point *fp)
{
	t_point		*temp;
	t_point		*temp2;

	temp = fp;
	temp2 = fp;
	while (temp)
	{
		temp2 = temp;
		while (temp2)
		{
			if (temp2->z > 0)
			{
				temp2->z *= 1.1;
			}
			temp2 = temp2->nextx;
		}
		temp = temp->nexty;
	}
}

void	ft_lower(t_point *fp)
{
	t_point		*temp;
	t_point		*temp2;

	temp = fp;
	temp2 = fp;
	while (temp)
	{
		temp2 = temp;
		while (temp2)
		{
			if (temp2->z > 0)
			{
				temp2->z /= 1.1;
			}
			temp2 = temp2->nextx;
		}
		temp = temp->nexty;
	}
}
