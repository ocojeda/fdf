/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:47:22 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/26 11:51:16 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_basic_check0(int argc, char **argv)
{
	char	*line;
	int		i;
	int		temp;
	int		fd;

	temp = 0;
	i = 0;
	if (argc != 2)
		ft_error("Only one argument is valid\n", 0);
	ft_file(argv[1]);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("unable to open the file\n", 0);
	while ((temp = get_next_line(fd, &line)))
	{
		if (temp == -1)
			ft_error("unable to open the file\n", 0);
		free(line);
		i++;
	}
	if (i == 1)
		ft_error("1 only line, is not a valide argument\n", 0);
	close(fd);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("unable to open the file\n", 0);
	return (fd);
}

void	fdf_check_invalid_fd(t_check *check)
{
	if (check->line == NULL)
		ft_error("Empty first line\n", check->fd);
	if (check->i == -1)
		ft_error("Invalid File\n", check->fd);
	if (!ft_strchr(check->line, ' '))
		ft_error("Minimun of at least 2 parameters in line\n", check->fd);
	if (check->line[0] == '\0' || check->line == NULL)
		ft_error("Invalid File, first line its empty\n", check->fd);
	check->i = 0;
}

void	fdf_basicheck1(t_check *check, int argc, char **argv)
{
	check->fd = fdf_basic_check0(argc, argv);
	check->i = get_next_line(check->fd, &check->line);
	check->linep = ft_strsplit(check->line, ' ');
	fdf_check_invalid_fd(check);
	while (check->linep[check->i])
	{
		check->e = 0;
		while (check->linep[check->i][check->e])
		{
			if (check->linep[check->i][check->e] == ',')
				check->flag++;
			if (check->flag > 1)
				ft_error("only one coma to generate colors\n", check->fd);
			check->e++;
		}
		check->flag = 0;
		free(check->linep[check->i]);
		check->i++;
	}
	free(check->line);
}

void	fdf_line_checker(t_check *check, t_screen *fst)
{
	check->i = 0;
	while (check->linep[check->i])
	{
		check->e = 0;
		while (check->linep[check->i][check->e])
		{
			if (check->linep[check->i][check->e] == ',')
				check->flag++;
			if (check->flag > 1)
				ft_error("only one coma to generate colors\n", check->fd);
			check->e++;
		}
		check->flag = 0;
		free(check->linep[check->i++]);
	}
	if (check->i != fst->columns_total)
		ft_error("the number of columns is not the same in every line\n",
				check->fd);
}

int		fdf_checker(t_screen *fst, int argc, char **argv)
{
	t_check		check;

	fdf_basicheck1(&check, argc, argv);
	fst->columns_total = check.i;
	while (get_next_line(check.fd, &check.line))
	{
		fdf_check_invalid_fd(&check);
		if ((check.linep = ft_strsplit(check.line, ' ')))
			fdf_line_checker(&check, fst);
		free(check.line);
	}
	close(check.fd);
	return (0);
}
