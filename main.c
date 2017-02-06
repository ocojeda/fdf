/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:10:26 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/06 17:56:23 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct	t_screen
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	int	bpp;
	int sizeline;
	int length;
	int hight;
	int endian;
	char *data;
};	
struct	t_point
{
	int	x;
	int y;
	unsigned int color;
};
int	my_key_func(int keycode, void *param)
{
	if(keycode == 53)
		exit(0);
	ft_putendl("key event");
	ft_putnbr(keycode);
	return 1;
}
void ft_put_pix_paral(struct t_point *pointA, struct t_point *pointB, struct t_screen *fst, int x)
{
	while(x <= pointB->x)
	{
		((unsigned int *)fst->data)[x + pointA->y + ((pointB->y - pointA->y) 
			*(x - pointA->x))/(pointB->x - pointA->x)  ] = pointB->color;
		x++;
	}
}
void ft_put_pix_vertical(struct t_point *pointA, struct t_point *pointB, struct t_screen *fst, int x, int y)
{
	while(y <= pointB->y)
	{
		((unsigned int *)fst->data)[y + pointA->x + ((pointB->x - pointA->x) 
			*(y - pointA->y))/(pointB->y - pointA->y) ] = pointB->color;
		y = y + fst->length ;
	}
}
void ft_order_points(struct t_point *pointA, struct t_point *pointB, int *x, int *y)
{
	if(pointA->x > pointB->x)
	{
		*x = pointB->x;
		pointB->x = pointA->x;
		pointA->x = *x;
	}
	else 
		*x = pointA->x;
	if(pointA->y > pointB->y)
	{
		*y = pointB->y;
		pointB->y = pointA->y;
		pointA->y = *y;
	}
	else 
		*y = pointA->y;
}
int	ft_steps(struct t_point *d, struct t_point *steps, struct t_point *pointA, struct t_point *pointB, struct t_screen *fst) 
{

	d->x = pointB->x - pointA->x;
	d->y = (pointB->y/fst->length - pointA->y/fst->length);

	if(d->y < 0)
	{
		d->y = (d->y) * -1;
		steps->y = -1;
	}
	else 
		steps->y = 1;
	if(d->x < 0)
	{
		d->x = -(d->x);
		steps->y = -1;
	}
	else 
		steps->x = 1;
	if(d->x > d->y)
		return 1;
	else
		return 0;
	
}
void ft_put_pix_diagonal(struct t_point *pointA, struct t_point *pointB, struct t_screen *fst)
{
	struct t_point steps;
	struct t_point t;
	struct t_point d;
	int a = 2 * (pointB->y/fst->length - pointA->y/fst->length);
	int b = 2*a - 2*(pointB->x - pointA->x);
	int p = 2*a - (pointB->x - pointA->x);
	t.x = pointA->x;
	t.y = pointA->y/fst->length;
	if(ft_steps(d, steps, pointA, pointB, fst))
	{
		p = (2 * d.y) - d.x;
		
		while(steps.x--)
	{
		if(p < 0)
		{
			((unsigned int *)fst->data)[t.x + t.y*fst->length] = pointB->color;
			p = p +a;
		}
		if(p > 0)
		{
			((unsigned int *)fst->data)[t.x + t.y*fst->length] = pointB->color;
			p = p + b;
			t.y++;
		}
			t.x++;
	}
	}
}

/*int	ft_steps(struct t_point *pointA, struct t_point *pointB, struct t_screen *    fst)
{
	float dx;
	float dy;
	int steps;
	float x_inc;
	float y_inc;

	dx = pointB->x - pointA->x;
	dy = (pointB->y/fst->length - pointA->y/fst->length);

	if(fabsf(dx) > fabsf(dy))
		steps = fabsf(dx);
	else
		steps = fabs(dy);
	return steps;
}*/
void ft_put_pix_line(struct t_point *pointA, struct t_point *pointB, struct t_screen *fst)
{
	int x;
	int y;


	if(pointA && pointB && fst)
	{
//		if((pointA->x > pointB->x) || (pointA->y > pointB->x))
//			ft_order_points(pointA, pointB, &x, &y);
/*		ft_putnbr(pointA->x);
		ft_putendl("-------------");
		ft_putnbr(pointB->x);
		ft_putendl("-------------");
		ft_putnbr(pointA->y);
		ft_putendl("-------------");
		ft_putnbr(pointB->y);
		ft_putendl("-------------");
		ft_putnbr(x);
		ft_putendl("-------------");
		ft_putnbr(y);
		ft_putendl("-------------");
		if((pointA->x != pointB->x) && (pointA->y == pointB->y))
			ft_put_pix_paral(pointA, pointB, fst, x);
		if((pointA->x == pointB->x) && (pointA->y != pointB->y))
			ft_put_pix_vertical(pointA, pointB, fst, x, y);*/
//	if((pointA->x != pointB->x) && (pointA->y != pointB->y))
			ft_put_pix_diagonal(pointA, pointB, fst);
	}
}
int main()
{
	struct t_screen fst;
	struct t_point pointA;
	struct t_point pointB;

	fst.length = 400;
	fst.hight = 400;	
	pointB.color = 0x00ff00ef;
	pointA.x = 100;
	pointA.y = fst.length*10;
	pointB.y = fst.length*120;
	pointB.x = 50;
	fst.mlx_ptr = mlx_init();
	fst.img_ptr = mlx_new_image(fst.mlx_ptr, fst.length, fst.hight);
	fst.data = mlx_get_data_addr(fst.img_ptr, &fst.bpp, &fst.sizeline, &fst.endian);
	ft_put_pix_line(&pointA, &pointB, &fst);
	fst.win_ptr = mlx_new_window(fst.mlx_ptr, fst.length, fst.hight, "test 1");
	mlx_put_image_to_window(fst.mlx_ptr, fst.win_ptr, fst.img_ptr, 0,0);
	mlx_key_hook(fst.win_ptr, my_key_func, 0);
	mlx_loop(fst.mlx_ptr);
}
