/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:10:26 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/01/18 16:38:37 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft/libft.h"

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int y = 50;
	int x = 50;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 400, 400, "test 1");
	while(y < 150)
	{
		x = 50;
		while(y<150)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FFFFFF);
			x++;
		}
		usleep(500);
	}
	mlx_loop(mlx_ptr);
}
