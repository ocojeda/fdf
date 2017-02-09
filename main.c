/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:10:26 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/09 18:07:24 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>

int	my_key_func(int keycode, void *param)
{
	if(keycode == 53)
		exit(0);
	ft_putendl("key event");
	ft_putnbr(keycode);
	return 1;
}
char		**ft_iscolor(char *str)
{
	if(ft_strchr(str, ','))
		return (ft_strsplit(str, ','));
	return 0;
}
int main(int argc, char **argv)
{
	t_screen fst;
	t_point *pointA;
	t_point *pointB;
	t_point *temp;
	t_point *temp2;
	t_point *fp;

	int fd;
	char *line;
	char **linep;
	char **color;
	int x;
	int y;
	int z;
	int i;
	
	if(argc == 2)
	{
		if((fd = (open(argv[1], O_RDONLY))) == -1)
			return 0;
		y = 0;
		fp = new_point(0, 0, 0, 0, 0, 0);
		temp = fp; 
		while(get_next_line(fd, &line))
		{
			x = 0;
			linep = ft_strsplit(line, ' ');
			while(*linep)
			{
				ft_putchar('-');
				if((color = ft_iscolor(*linep)))
				{
			//		ft_putnbr(ft_atoi(color[0]));
					z = ft_atoi(color[0]);
					while(*color)
						free(*color++);
					linep++;
				}
				else
				{
					z = ft_atoi(*linep);
			//		ft_putnbr(ft_atoi(*linep++));
				}
				temp2 = new_point(x, y, z, 0, 0, 0);
				temp->nextx = temp2;
				temp = temp2;
				x++;
			}
			y++;
//			ft_putchar('\n');
			while(*linep)
				free(*linep++);
			if(line != NULL)
				free(line);
		}
		close(fd);
	}
	temp = fp;
	while(fp)
	{
		ft_putnbr(temp->x);
		ft_putchar("-");
		ft_putnbr(temp->y);
		ft_putchar("-");
		ft_putnbr(temp->z);
		ft_putendl("-");
		temp = fp->nextx;
		free(fp);
		fp = temp;
	}
	ft_putnbr(x);
	ft_putnbr(y);
	ft_putendl("hello!");
	fst.length = 400;
	fst.hight = 400;
	pointB = new_point(150, 300, 0, 0x00ff00ef, NULL, NULL);
	pointA = new_point(50, 300, 0, 0x00ff00ef, NULL, NULL);
	ft_order_points(pointA, pointB);
	fst.mlx_ptr = mlx_init();
	fst.img_ptr = mlx_new_image(fst.mlx_ptr, fst.length, fst.hight);
	fst.data = mlx_get_data_addr(fst.img_ptr, &fst.bpp, &fst.sizeline, &fst.endian);
	ft_put_pix_diagonal(pointA, pointB, &fst);
	free(pointA);
	free(pointB);
	fst.win_ptr = mlx_new_window(fst.mlx_ptr, fst.length, fst.hight, "test 1");
	mlx_put_image_to_window(fst.mlx_ptr, fst.win_ptr, fst.img_ptr, 0,0);
	mlx_key_hook(fst.win_ptr, my_key_func, 0);
	mlx_loop(fst.mlx_ptr);
	return 0;
}
