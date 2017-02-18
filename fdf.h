/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:30:11 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/18 19:23:47 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define COLOR 0x00FFFFFF
# define ZOOM 5
# define R_TRANSLATE 100

# define RADIANCONV 0.017453259
# define ANGLE 5


typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	unsigned int	color;
	struct s_point	*nextx;
	struct s_point	*nexty;
}					t_point;
typedef struct		s_line
{
	int				x;
	int				y;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				p;
	int				ince;
	int				incne;
	int				stepx;
	int				stepy;
}					t_line;

typedef struct		s_screen
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sizeline;
	int				len;
	int				hight;
	int				endian;
	char			*data;
	t_point			*fp;
}					t_screen;

/************* MAIN.C ***************/

t_point		*test(t_point *fp, void (*f)(t_point *point));
void		print_point(t_point *point);

/************* PARSE.C **************/

t_point		*ft_get_map(char *str);
int			ft_erase_map(t_point *temp, t_point *temp2, t_point *temp3);

/*********** PROYECTION.C ***********/

t_point		*ft_proyection(t_point *fp);
void		ft_put_pix_map(t_point *fp, t_screen *fst, t_point *t, t_point *t2);

/************* LINE.C ***************/

void		ft_put_diagonal(t_point *pointa, t_point *pointb, t_screen *fst);
t_point		*new_point(float x, float y, float z, unsigned int color);

/*************  MAP.C  **************/

void		ft_center(t_point *fp, int lenght, int hight, int i);
t_point		*ft_find_centermap(t_point *fp);
//int		ft_maplong(t_point *fp);
//int		ft_maphight(t_point *fp);
//int		ft_maplenght(t_point *fp);

/************* BONUS.C **************/

void		ft_zoom(t_point *fp);
void		ft_movedown(t_point *fp);
void		ft_moveup(t_point *fp);
void		ft_mover(t_point *fp);
void		ft_movel(t_point *fp);

/************ FT_ATOI_HEXA.C ********/
unsigned int	ft_atoi_hexa(char *nbr);

/************ matrix.c **************/

void	matrice_rotate_x(t_point *temp);
void	matrice_rotate_y(t_point *temp);
void	matrice_rotate_z(t_point *temp);
void	matrice_translate(t_point *temp, int x);
#endif
