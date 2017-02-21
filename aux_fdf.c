/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:40:30 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/21 17:47:36 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"fdf.h"
t_point		*ft_resetcenter(t_point *fp)
{
	t_point *temp;

	temp = fp;
/*	while(temp->nexty)
		temp = temp->nexty;
	while(temp->nextx)
		temp = temp->nextx;
	free(temp);
	temp = fp;
	while(temp->nexty)
		temp = temp->nexty;
	while(temp->nextx)
		temp = temp->nextx;
	temp->nextx = addcenter(fp);*/
	return fp;
}
t_point		*ft_resetmap(t_point *fp, int *z0)
{
	int x;
	int y;
	t_point *temp;
	t_point *temp2;
	
	x = 0;
	y = 0;
	while (temp)
	{
		x = 0;
		temp2 = temp;
		while (temp2)
		{
			temp2->x = x;
			temp2->y = y;
			temp2->z = z0[x];
			temp2 = temp2->nextx;
			x++;
		}
		y++;
		temp= temp->nexty;
	}
	ft_resetcenter(fp);
	return fp;
}
float		*ft_mapcpy(t_point *fp)
{
	t_point		*temp;
	t_point		*temp2;
	int			x;
	float 		*z;
	
	temp = fp;
	x = 0;
	while (temp)
	{
		temp2 = temp;
		while (temp2)
		{
			temp2 = temp2->nextx;
			x++;
		}
			temp= temp->nexty;
	}
	z = (float *)malloc(sizeof(float)*(x+1));
	temp = fp;
	x = 0;
	while (temp)
	{
		temp2 = temp;
		while (temp2)
		{
			z[x++] = temp2->z;
			temp2 = temp2->nextx;
		}
			temp= temp->nexty;
	}
	z[x] = '\0';
	test(fp, print_point);
	while(x--)
		printf("%f ",z[x]);
	return (z);
}
