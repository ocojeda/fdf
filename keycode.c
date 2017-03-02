/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:04:50 by myernaux          #+#    #+#             */
/*   Updated: 2017/03/02 11:32:32 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		keycode126(t_point *temp, t_point *fp, int k, t_screen *fst)
{
	int		i;

	i = 70;
	if (k == 126)
	{
		test2(fp, matrice_rotate_x, 5);
		test3(fp, matrice_translate_rl, (temp->x - fp->x));
		test3(fp, matrice_translate_ud, (temp->y - fp->y));
	}
	else
	{
		ft_resetmap(fst->fp, fst->cpy);
		while (i--)
			ft_set_zoom(fst->fp);
		ft_center(fst->fp, fst->center, fst->len, fst->hight);
	}
}

static void		ft_rotate(int keycode, t_screen *fst, t_point *temp)
{
	temp = new_point(fst->fp->x, fst->fp->y, 0, 0);
	if (keycode == 126)
		keycode126(temp, fst->fp, 126, fst);
	if (keycode == 125)
	{
		test2(fst->fp, matrice_rotate_x, -5);
		test3(fst->fp, matrice_translate_rl, (temp->x - fst->fp->x));
		test3(fst->fp, matrice_translate_ud, (temp->y - fst->fp->y));
	}
	if (keycode == 123)
	{
		test2(fst->fp, matrice_rotate_y, 5);
		test3(fst->fp, matrice_translate_rl, (temp->x - fst->fp->x));
		test3(fst->fp, matrice_translate_ud, (temp->y - fst->fp->y));
	}
	if (keycode == 124)
	{
		test2(fst->fp, matrice_rotate_y, -5);
		test3(fst->fp, matrice_translate_rl, (temp->x - fst->fp->x));
		test3(fst->fp, matrice_translate_ud, (temp->y - fst->fp->y));
	}
	free(temp);
}

static void		ft_translate(int keycode, t_screen *fst)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		ft_zoom(fst->fp);
	if (keycode == 78)
		ft_zoom_out(fst->fp);
	if (keycode == 84)
		test3(fst->fp, matrice_translate_ud, 10);
	if (keycode == 86)
		test3(fst->fp, matrice_translate_rl, -10);
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
	if (keycode == 6)
		ft_higher(fst->fp);
	if (keycode == 7)
		ft_lower(fst->fp);
}

static void		choose_action(int keycode, t_screen *fst)
{
	if (keycode > 100)
		ft_rotate(keycode, fst, NULL);
	if (keycode >= 6 && keycode <= 86)
		ft_translate(keycode, fst);
	if (keycode == 91)
		test3(fst->fp, matrice_translate_ud, -10);
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
	if (keycode == 87)
		keycode126(NULL, fst->fp, 87, fst);
}

int				my_key_func(int keycode, t_screen *fst)
{
	choose_action(keycode, fst);
	ft_putnbr(keycode);
	mlx_destroy_image(fst->mlx, fst->img);
	fst->img = mlx_new_image(fst->mlx, fst->len, fst->hight);
	ft_put_pix(fst->fp, fst, NULL, NULL);
	mlx_put_image_to_window(fst->mlx, fst->win, fst->img, 0, 0);
	return (1);
}
