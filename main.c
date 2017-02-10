/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:10:26 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/10 07:53:55 by ocojeda-         ###   ########.fr       */
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
	t_point *fp;
	t_point *temp2;
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
		temp = new_point(0, 0 , 0, 0);
		fp = temp;
		while(get_next_line(fd, &line))
		{
			x = 0;
			linep = ft_strsplit(line, ' ');
			while(*linep)
			{
				if((color = ft_iscolor(*linep)))
				{
					z = ft_atoi(color[0]);
					while(*color)
						free(*color++);
				}
				else
					z = ft_atoi(*linep);
				temp->nextx = new_point(x++, y, z, 0);
				temp = temp->nextx;
				free(*linep++);
			}
			y++;
			free(line);
		}
		close(fd);
	}
	temp = fp->nextx;
	free(fp);
	fp = temp;
	temp = fp;
	while(temp)
	{
		ft_putnbr(temp->x);
		ft_putchar('-');
		ft_putnbr(temp->y);
		ft_putchar('-');
		ft_putnbr(temp->z);
		ft_putendl("-");
		temp2 = temp->nextx;
		free(temp);
		temp = temp2;
	}
	ft_putnbr(x);
	ft_putnbr(y);
	ft_putendl("hello!");
	fst.length = 400;
	fst.hight = 400;
	pointB = new_point(150, 300, 0, 0x00ff00ef);
	pointA = new_point(50, 300, 0, 0x00ff00ef);
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
