/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:10:26 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/10 16:57:47 by ocojeda-         ###   ########.fr       */
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
t_point		*ft_get_map(char *str, int *x, int *y, unsigned int col, char *line)
{
	char **color;
	int fd;
	char **linep;
	t_point *temp;
	t_point *temp2;
	t_point *fp;
	int z;
	int j = 0;
	int i = 0;
	int a;
	int b;

	if((fd = (open(str, O_RDONLY))) == -1)
			return 0;
	temp = new_point(0, 0 , 0, col);
	fp = temp;
	while(get_next_line(fd, &line))
	{
			a = 0;
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
				temp->nextx = new_point(a++, b, z, col);
				temp = temp->nextx;
				free(*linep++);
			}
			b++;
			free(line);
	}
	close(fd);
	temp = fp->nextx;
	free(fp);
	fp = temp;
	temp =fp;
	a--;
	b--;
	temp =fp;
	ft_putnbr(a);
	ft_putendl("hello a");
	while(temp)
	{
		temp2 = temp;
		while(temp2)
		{
			if((temp->y == temp2->y - 1) && temp->x == temp2->x && temp->nexty == NULL)
			{
				temp->nexty = temp2;
				temp2 = NULL;
			}
			else
				temp2 = temp2->nextx;
		}
		if(temp->x == a)         
		{
			temp2 = temp->nextx;
			temp->nextx = NULL;
			temp = temp2;
		}
		else
			temp = temp->nextx;
	}
	*x = a;
	*y = b;
	return fp;
}
int main(int argc, char **argv)
{
	t_screen fst;
	t_point *temp;
	t_point *fp;
	t_point *temp2;
	t_point *temp3;

	int fd;
	int x;
	int x1;
	int y;
	int y1;
	int i = 0;
	unsigned int col = 0x00ff00ef;

	fp = ft_get_map(argv[1], &x, &y, col, NULL);
	temp = fp;
	temp2 = fp;
	while(temp)
	{
		temp2 = temp;
		while(temp2)
		{
			temp2->x *= 4;
			temp2->y *= 2;
	//		temp2->x += 100;
	//		temp2->y += 105;
			temp2 = temp2->nextx;
		}
		temp = temp->nexty;
	}	
	temp = fp;
	ft_putnbr(x);
	ft_putnbr(y);
	fst.length = 2200;
	fst.hight = 1200;
	fst.mlx_ptr = mlx_init();
	fst.img_ptr = mlx_new_image(fst.mlx_ptr, fst.length, fst.hight);
	fst.data = mlx_get_data_addr(fst.img_ptr, &fst.bpp, &fst.sizeline, &fst.endian);
	temp2 = fp;
	while(temp)
	{
		temp2 = temp;
		while(temp2)
		{
			ft_put_pix_diagonal(temp2, temp2->nextx, &fst);
			ft_put_pix_diagonal(temp2, temp2->nexty, &fst);
			temp2 = temp2->nextx;
		}
		temp = temp->nexty;
	}
	ft_putstr("youpi");
	temp = fp;
	temp2 = fp;
	while(temp)
	{
		temp2 = temp;
		temp = temp->nextx;
		while(temp2)
		{
			temp3 = temp2->nexty;
			free(temp2);
			temp2 = temp3;
		}
	}
	fst.win_ptr = mlx_new_window(fst.mlx_ptr, fst.length, fst.hight, "test 1");
	mlx_put_image_to_window(fst.mlx_ptr, fst.win_ptr, fst.img_ptr, 0,0);
	mlx_key_hook(fst.win_ptr, my_key_func, 0);
	mlx_loop(fst.mlx_ptr);
	return 0;
}
