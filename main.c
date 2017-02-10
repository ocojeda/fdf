/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:10:26 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/10 19:59:50 by ocojeda-         ###   ########.fr       */
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
int main(int argc, char **argv)
{
	t_screen fst;
	t_point *fp;

	fp = ft_get_map(argv[1], 0, 0, 0x00ff00ef, NULL);
		fst.length = 2200;
	fst.hight = 1200;
	fst.mlx_ptr = mlx_init();
	fst.img_ptr = mlx_new_image(fst.mlx_ptr, fst.length, fst.hight);
	fst.data = mlx_get_data_addr(fst.img_ptr, &fst.bpp, &fst.sizeline, &fst.endian);	
	ft_put_pix_map(fp, &fst, NULL, NULL);	
	fst.win_ptr = mlx_new_window(fst.mlx_ptr, fst.length, fst.hight, argv[1]);
	mlx_put_image_to_window(fst.mlx_ptr, fst.win_ptr, fst.img_ptr, 0,0);
	mlx_key_hook(fst.win_ptr, my_key_func, 0);
	mlx_loop(fst.mlx_ptr);
	ft_erase_map(fp, NULL, NULL);
	return 0;
}
