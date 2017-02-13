/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:30:11 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/13 15:53:05 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#include <mlx.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

typedef struct  s_line
{
 int x;
 int y;
 int dx;
 int dy;
 int p;
 int ince;
 int incne;
 int stepx;
 int stepy;
}				t_line;
typedef struct	s_screen
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
}			t_screen;
typedef struct	s_point
{
	float x;
	float y;
	float z;
	unsigned int color;
	struct s_point *nextx;
	struct s_point *nexty;
}			t_point;

t_point     *find_centerobj(t_point *fp);
void    ft_zoom(t_point *fp);
void    ft_center(t_point *fp, int length, int hight);
char        **ft_iscolor(char *str, int *z);
int ft_erase_map(t_point *temp, t_point *temp2, t_point *temp3);
t_point     *ft_set_the_ends(t_point *fp, int a, t_point *temp, t_point *temp2);
t_point     *ft_get_map(char *str, int x, int y, unsigned int col, char *line);
void    ft_put_pix_map(t_point *fp, t_screen *fst, t_point *temp, t_point *temp2);
void ft_order_points(t_point *pointA, t_point *pointB);
t_point     *new_point(float x, float y, float z, unsigned int color);
void ft_put_pix_diagonal(t_point *pointA, t_point *pointB, t_screen *fst);
t_point *test(t_point *fp, void (*f)(t_point *point));
void    print_point(t_point *point);
t_point *update(t_point *fp);
t_point 	*ft_proyection(t_point *fp);
#endif
