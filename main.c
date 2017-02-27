/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:10:26 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/27 10:19:41 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_point(t_point *point)
{
	ft_putstr(" x = ");
	ft_putnbr(point->x);
	ft_putstr(" y = ");
	ft_putnbr(point->y);
	ft_putstr(" z = ");
	ft_putnbr(point->z);
	if(point->nextx)
	{
		ft_putstr("----> et mon nextx is x =");
		ft_putnbr(point->nextx->x);
		ft_putstr(" y = ");
		ft_putnbr(point->nextx->y);
		ft_putstr(" z = ");
		ft_putnbr(point->nextx->z);
	}
	else(ft_putstr("--> et mon nextx is NULL"));
	if(point->nexty)
	{
		ft_putstr("--> et mon nexty is x =");
		ft_putnbr(point->nexty->x);
		ft_putstr(" y = ");
		ft_putnbr(point->nexty->y);
		ft_putstr(" z = ");
		ft_putnbr(point->nexty->z);
		ft_putchar('\n');
	}
	else(ft_putendl("--> et je point vers NULL"));
}

t_point			*test(t_point *fp, void (*f)(t_point *point))
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
			f(temp2);
			temp2 = temp2->nextx;
		}
		temp= temp->nexty;
	}
	return (fp);
}

t_point			*test3(t_point *fp, void (*f)(t_point *point, int gle), int gle)
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
			f(temp2, gle);
			temp2 = temp2->nextx;
		}
		temp= temp->nexty;
	}
	return (fp);

}

t_point			*test2(t_point *fp, void (*f)(t_point *point, int angle), int angle, t_point *center)
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
			f(temp2, angle);
			temp2 = temp2->nextx;
		}
		temp= temp->nexty;
	}
	return (fp);
}

t_point			*addcenter(t_point *fp)
{
	t_point		*temp;
	t_point		*temp2;
	int			flag;

	flag = 1;
	temp = fp;
	temp2 = fp;
	while (temp)
	{
		temp2 = temp;
		while (temp2)
		{
		if(temp2->nexty == NULL && temp2->nextx == NULL && flag)
		{
			temp2->nextx = ft_find_centermap(fp, fp->x, fp->x, fp->y);
			return (temp2->nextx);
			flag = 0;
		}
			temp2 = temp2->nextx;
		}
		temp= temp->nexty;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_screen	fst;
	
	if (argc != 2)
		ft_error("Need 2 arguments");
	fst.fp = ft_get_map(argv[1]);
	fst.len = 1500;
	fst.hight = 1200;
	fst.mlx = mlx_init();
	fst.img = mlx_new_image(fst.mlx, fst.len, fst.hight);
	fst.data = mlx_get_data_addr(fst.img, &fst.bpp, &fst.sizeline, &fst.endian);	
	fst.cpy = ft_mapcpy(fst.fp);
	fst.center = addcenter(fst.fp);
	my_key_func(87, &fst);
	ft_put_pix_map(fst.fp, &fst, NULL, NULL);	
	fst.win = mlx_new_window(fst.mlx, fst.len, fst.hight, argv[1]);
	mlx_put_image_to_window(fst.mlx, fst.win, fst.img, 0, 0);
	mlx_hook(fst.win, 2, 3, my_key_func, &fst);
	mlx_loop(fst.mlx);
	ft_erase_map(fst.fp, NULL, NULL);
	free(fst.cpy);
	return (0);
}
