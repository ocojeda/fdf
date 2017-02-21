/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:10:26 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/21 17:53:03 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		my_key_func(int keycode, t_screen *fst)
{
	t_point	*temp3;

	temp3 = new_point(fst->fp->x, fst->fp->y, 0, 0);
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
	{	
		test2(fst->fp, matrice_rotate_x, 5, fst->center);
		test3(fst->fp, matrice_translate_rl, (temp3->x - fst->fp->x));
		test3(fst->fp, matrice_translate_ud, (temp3->y - fst->fp->y));
	}
	if (keycode == 125)
	{
		test2(fst->fp, matrice_rotate_x, -5, fst->center);
		test3(fst->fp, matrice_translate_rl, (temp3->x - fst->fp->x));
		test3(fst->fp, matrice_translate_ud, (temp3->y - fst->fp->y));
	}
	if (keycode == 123)
	{
		test2(fst->fp, matrice_rotate_y, 5, fst->center);
		test3(fst->fp, matrice_translate_rl, (temp3->x - fst->fp->x));
		test3(fst->fp, matrice_translate_ud, (temp3->y - fst->fp->y));
	}
	if (keycode == 124)
	{
		test2(fst->fp, matrice_rotate_y, -5, fst->center );
		test3(fst->fp, matrice_translate_rl, (temp3->x - fst->fp->x));
		test3(fst->fp, matrice_translate_ud, (temp3->y - fst->fp->y));
	}
	if (keycode == 69)
		ft_zoom(fst->fp);
	if (keycode == 78)
		ft_zoom_out(fst->fp);
	if (keycode == 91)
		test3(fst->fp, matrice_translate_ud, -10);
	if (keycode == 84)
		test3(fst->fp, matrice_translate_ud, 10);
	if (keycode == 86)
		test3(fst->fp, matrice_translate_rl, -10);
	if (keycode == 88)
		test3(fst->fp, matrice_translate_rl, 10);
	if (keycode == 89)
	{
		test3(fst->fp, matrice_translate_ud, -10);
		test3(fst->fp, matrice_translate_rl, -10);
	}
	if (keycode == 92)
	{
		test3(fst->fp, matrice_translate_ud, -10);
		test3(fst->fp, matrice_translate_rl, 10);
	}
	if (keycode == 83)
	{
		test3(fst->fp, matrice_translate_ud, 10);
		test3(fst->fp, matrice_translate_rl, -10);
	}
	if (keycode == 85)
	{
		test3(fst->fp, matrice_translate_ud, 10);
		test3(fst->fp, matrice_translate_rl, 10);
	}
	if (keycode == 87)
	{
	}
	free(temp3);
	ft_putnbr(keycode);
	mlx_destroy_image(fst->mlx, fst->img);
	fst->img = mlx_new_image(fst->mlx, fst->len, fst->hight);
	ft_put_pix_map(fst->fp, fst, NULL, NULL);
	mlx_put_image_to_window(fst->mlx, fst->win, fst->img, 0, 0);
	return (1);
}

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
t_point			*test3(t_point *fp, void (*f)(t_point *point, int angle), int angle)
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
//	test(fp, print_point);
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
	//		if(temp2 != center)
				f(temp2, angle);
			temp2 = temp2->nextx;
		}
		temp= temp->nexty;
	}
//	test(fp, print_point);
	return (fp);
}
/*
t_point			*test_rota(t_point *fp, void (*f)(t_point *point), t_point *center)
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
			if(temp2 != center)
				f(temp2);
			temp2 = temp2->nextx;
		}
		temp= temp->nexty;
	}
	return (fp);
}
*/
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
			temp2->nextx = ft_find_centermap(fp);
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
	
	if(argc == 2)
	{
	fst.fp = ft_get_map(argv[1]);
	fst.len = 1500;
	fst.hight = 1200;
	fst.mlx = mlx_init();
	fst.img = mlx_new_image(fst.mlx, fst.len, fst.hight);
	fst.data = mlx_get_data_addr(fst.img, &fst.bpp, &fst.sizeline, &fst.endian);	
	fst.center = addcenter(fst.fp);
//	fst.cpy = ft_mapcpy(fst.fp);
//	fst.fp = ft_resetmap(fst.fp, fst.cpy);
	test(fst.fp, print_point);
	ft_center(fst.fp, fst.center, fst.len, fst.hight);
//	int w;
//	w = 60;
//	while(w--)
//	ft_zoom(fst.fp);
//	ft_center(fst.fp, fst.center, fst.len, fst.hight);
//	test(fst.fp, print_point);
//	w = 900;
//	while(w--)
//	test(fp, ft_mover);
//	center(fp, fst.len, fst.hight);
//	test(fst.fp, print_point);
//	test_rota(fp, ft_proyection, center);
//	ft_center(fp, center, fst.len, fst.hight);
//	test(fp, print_point);
	ft_put_pix_map(fst.fp, &fst, NULL, NULL);	
	fst.win = mlx_new_window(fst.mlx, fst.len, fst.hight, argv[1]);
	mlx_put_image_to_window(fst.mlx, fst.win, fst.img, 0, 0);
	mlx_hook(fst.win, 2, 3, my_key_func, &fst);
	mlx_loop(fst.mlx);
	ft_erase_map(fst.fp, NULL, NULL);
	}
	return (0);
}
