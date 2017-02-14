/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 19:16:44 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/14 08:49:58 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		**ft_iscolor(char *str, int *z)
{
	if(ft_strchr(str, ','))
	{
		*z = ft_atoi(&str[0]);
		return (ft_strsplit(str, ','));
	}
	return 0;
}
int	ft_erase_map(t_point *temp, t_point *temp2, t_point *temp3)
{
	if(temp)
	{
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
		return 1;
	}
	return 0;
}
t_point		*ft_set_the_ends(t_point *fp, int a, t_point *temp, t_point *temp2)
{
	temp = fp;
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
	return fp;
}
t_point		*ft_get_map(char *str, int x, int y, unsigned int col, char *line)
{
	char **color;
	int fd;
	char **linep;
	t_point *temp;
	t_point *fp;
	int z;

	if((fd = (open(str, O_RDONLY))) == -1)
		return 0;
	temp = new_point(0, 0 , 0, col);
	fp = temp;
	while(get_next_line(fd, &line))
	{
		x = 0;
		linep = ft_strsplit(line, ' ');
		while(*linep)
		{
			if((color = ft_iscolor(*linep, &z)))
				while(*color)
					free(*color++);
			else
				z = ft_atoi(*linep);
			temp->nextx = new_point(x++, y, z, col);
			temp = temp->nextx;
			free(*linep++);
		}
		y++;
		free(line);
	}
	close(fd);
	temp = fp->nextx;
	free(fp);
	return ((ft_set_the_ends(temp, --x, NULL, NULL)));
}
t_point		*ft_proyection(t_point *fp)
{
	int x;
	t_point *temp;
	t_point *temp2;
	
	temp = fp;	
	while(temp)
	{
		temp2 = temp;
		while(temp2)
		{
			x = temp2->x;
			temp2->x = temp2->x*cos(0.75) - temp2->y*sin(0.5);
			temp2->y = x*sin(0.5) + temp2->y*cos(0.75);
			temp2->x = temp2->z + (0.75 * temp2->x);
			temp2->y = temp2->y + (0.75/2 * temp2->z);
			temp2 = temp2->nextx;
		}
		temp= temp->nexty;
	}
//	test(fp, print_point);
	return (fp);
}
void	ft_zoom(t_point *fp)
{
	fp->x *= 2;
	fp->y *= 2;
}
void	ft_movedown(t_point *fp)
{
	fp->y += 1;
}
void	ft_moveup(t_point *fp)
{
	fp->y -= 1;
}
void	ft_mover(t_point *fp)
{
	fp->x += 1;
}
void	ft_movel(t_point *fp)
{
	fp->x -= 1;
}
int		ft_objlong(t_point *fp)
{
	t_point *temp;
	int i;

	i = 0;
	temp = fp;
	while(temp)
	{
		i++;
		temp = temp->nextx;
	}
	return (i);
}
int		ft_objhigh(t_point *fp)
{
	t_point *temp;
	int i;

	i = 0;
	temp = fp;
	while(temp)
	{
		i++;
		temp = temp->nexty;
	}
	return (i);
}

int		ft_objlength(t_point *fp)
{
	t_point *temp;
	int i;

	i = 0;
	temp = fp;
	while(temp)
	{
		i++;
		temp = temp->nextx;
	}
	return (i);
}
t_point		*find_centerobj(t_point *fp)
{
	t_point *temp;
	float x;
	float y;
	int dec;

	x = fp->x;
	y = fp->y;
	temp = fp;
	while(temp->nextx)
		temp=temp->nextx;
	x = (temp->x - x)/2 + x;
	temp = fp;
	while(temp->nexty)
		temp=temp->nexty;
	y = (temp->y -y)/2 + y;
	return new_point(x, y, 0, 0);
}

void	ft_center(t_point *fp, int length, int hight)
{
	int i;
	t_point *center;
	center = find_centerobj(fp);	
	if(center->x < length /2)
	{
		i = length / 2 - center->x;
		while(i--)
			test(fp, ft_mover);
	}
	if(center->x > length/2) 
	{
		i = center->x - length/2;
		while(i--)
			test(fp, ft_movel);
	}
	if(center->y < hight/2) 
	{
		i = hight/2 - center->y;
		while(i--)
			test(fp, ft_movedown);
	}
	if(center->y > length/2) 
	{
		i = center->y - length/2;
		while(i--)
			test(fp, ft_moveup);
	}
	free(center);
}

void	ft_put_pix_map(t_point *fp, t_screen *fst, t_point *temp, t_point *temp2)
{
	temp = fp;
	while(temp)
	{
		temp2 = temp;
		while(temp2)
		{
			ft_put_pix_diagonal(temp2, temp2->nextx, fst);
			ft_put_pix_diagonal(temp2, temp2->nexty, fst);
			temp2 = temp2->nextx;
		}
		temp = temp->nexty;
	}
}
