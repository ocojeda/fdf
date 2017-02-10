/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 19:16:44 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/02/10 19:19:21 by ocojeda-         ###   ########.fr       */
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
void	ft_put_pix_map(t_point *fp, t_screen *fst, t_point *temp, t_point *temp2)
{
	temp = fp;
	while(temp)
	{
		temp2 = temp;
		while(temp2)
		{
			temp2->x *= 4;
			temp2->y *= 2;
			temp2->x += 100;
			temp2->y += 105;
			temp2 = temp2->nextx;
		}
		temp = temp->nexty;
	}
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
