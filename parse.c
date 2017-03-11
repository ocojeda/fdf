/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:29:52 by myernaux          #+#    #+#             */
/*   Updated: 2017/03/11 09:55:35 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_erase_map(t_point *temp, t_point *temp2, t_point *temp3)
{
	if (temp)
	{
		while (temp)
		{
			temp2 = temp;
			temp = temp->nextx;
			while (temp2)
			{
				temp3 = temp2->nexty;
				free(temp2);
				temp2 = temp3;
			}
		}
		return (1);
	}
	return (0);
}

static t_point	*ft_set_the_end(t_point *fp, int a, t_point *t, t_point *t2)
{
	t = fp;
	while (t)
	{
		t2 = t;
		while (t2)
		{
			if ((t->y == t2->y - 1) && t->x == t2->x && t->nexty == NULL)
			{
				t->nexty = t2;
				t2 = NULL;
			}
			else
				t2 = t2->nextx;
		}
		if (t->x == a)
		{
			t2 = t->nextx;
			t->nextx = NULL;
			t = t2;
		}
		else
			t = t->nextx;
	}
	return (fp);
}

int				ft_makepoint(char **linep, t_point *t, int x, int y)
{
	char		**color;
	int			z;

	if ((color = ft_iscolor(*linep)))
	{
		t->nextx = new_point(x++, y, ft_atoi(color[0]), \
				ft_atoi_hexa(color[1]));
		while (*color)
			free(*color++);
	}
	else
	{
		z = ft_atoi(*linep);
		t->nextx = new_point(x++, y, z, COLOR);
	}
	return (x);
}

static t_point	*get_map(int fd, t_point *temp, int y, t_point *fp)
{
	char		**linep;
	char		*line;
	int			x;

	while (get_next_line(fd, &line) == 1 && ++y >= -1)
	{
		x = 0;
		if (!(linep = ft_strsplit(line, ' ')))
			ft_error("Invalid File");
		while (*linep)
		{
			x = ft_makepoint(linep, temp, x, y);
			temp = temp->nextx;
			free(*linep++);
		}
		free(line);
	}
	temp = fp;
	fp = fp->nextx;
	free(temp);
	return ((ft_set_the_end(fp, --x, NULL, NULL)));
}

t_point			*ft_get_map(char *str)
{
	int		fd;
	t_point	*fp;
	t_point	*temp;

	if ((fd = open(str, O_RDONLY)) == -1)
		ft_error("Invalid File");
	temp = new_point(0, 0, 0, COLOR);
	fp = get_map(fd, temp, -1, temp);
	close(fd);
	return (fp);
}
