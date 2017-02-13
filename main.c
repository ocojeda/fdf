/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:10:26 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/13 17:13:15 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
int	my_key_func(int keycode, void *param)
{
	if(keycode == 53)
		exit(0);
	ft_putendl("key event");
	ft_putnbr(keycode);
	return 1;
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
t_point *test(t_point *fp, void (*f)(t_point *point))
{
	t_point *temp;
	t_point *temp2;
	temp = fp;
	temp2 = fp;
	while(temp)
	{
		temp2 = temp;
		while(temp2)
		{
			f(temp2);
			temp2 = temp2->nextx;
		}
		temp= temp->nexty;
	}
	return fp;
}

int main(int argc, char **argv)
{
	t_screen fst;
	t_point *fp;
	t_point *center;

	fp = ft_get_map(argv[1], 0, 0, 0x00ff00ef, NULL);
	fst.length = 800;
	fst.hight = 800;
	fst.mlx_ptr = mlx_init();
	fst.img_ptr = mlx_new_image(fst.mlx_ptr, fst.length, fst.hight);
	fst.data = mlx_get_data_addr(fst.img_ptr, &fst.bpp, &fst.sizeline, &fst.endian);	

	int w;
	w= 4;
	while(w--)
	test(fp, ft_zoom);
//	ft_center(fp, fst.length, fst.hight);
	test(fp, print_point);
	ft_proyection(fp);
//	ft_center(fp, fst.length, fst.hight);
	//test(fp, print_point);
	ft_put_pix_map(fp, &fst, NULL, NULL);	
	fst.win_ptr = mlx_new_window(fst.mlx_ptr, fst.length, fst.hight, argv[1]);
	mlx_put_image_to_window(fst.mlx_ptr, fst.win_ptr, fst.img_ptr, 0,0);
	mlx_key_hook(fst.win_ptr, my_key_func, 0);
	mlx_loop(fst.mlx_ptr);
	ft_erase_map(fp, NULL, NULL);
	return 0;
}
