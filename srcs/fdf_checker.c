#include "../includes/fdf.h"

int	 ft_errorcheck(int error)
{
	if(error == 1)
		ft_error("Need 2 arguments\n", 0);
	return (0);
}
int  fdf_basic_checks(int argc, char **argv, int fd)
{
	char *line;
	int i;
	int temp;

	temp = 0;
	i = 0;
	if (argc != 2)
		ft_error("Only one argument is valid\n", 0);
	ft_file(argv[1]);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("unable to open the file\n", 0);
	while((temp = get_next_line(fd, &line)))
	{
		if(temp == -1)
			ft_error("unable to open the file\n", 0);
		free(line);
		i++;
	}
	if (i == 1)
		ft_error("1 only line, is not a valide argument\n", 0);
	close(fd);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("unable to open the file\n", 0);
	return(fd);
}

int	 fdf_checker(t_screen *fst , int argc, char **argv)
{
	int		 fd;
	char		**linep;
	char		*line;
	int		 i;
	int		 flag;
	int		 e;
	int		 l;
	int		 c;
	int p;

	flag = 0;
	i = 0;
	e = 0;
	l = 0;
	c = 0;
	fd = 0;

	
	fd = fdf_basic_checks(argc, argv, fd);
	i  = get_next_line(fd, &line);
	p = i;
	if (line == NULL)
		ft_error("Empty first line\n", fd);
	if (i == -1)
		ft_error("Invalid File\n", fd);
	if(!ft_strchr(line, ' '))
		ft_error("Minimun of at least 2 parameters in line\n", fd);
	if(line[0] == '\0' || line == NULL)
		ft_error("Invalid File, first line its empty\n", fd);
	linep = ft_strsplit(line, ' ');
	i = 0;
	while(linep[i])
	{
		e = 0;
		while(linep[i][e])
		{
			if(linep[i][e] == ',')
				flag++;
			if(flag > 1)
				ft_error("only one coma to generate colors\n", fd);
			e++;
		}
		flag = 0;
		free(linep[i]);
		i++;
	}
	free(line);
	fst->columns_total = i;
	while(get_next_line(fd, &line))
	{
        if (line == NULL)
		    ft_error("Empty first line\n", fd);
	    if (i == -1)
		    ft_error("Invalid File\n", fd);
	    if(!ft_strchr(line, ' '))
		    ft_error("Minimun of at least 2 parameters in every line\n", fd);
	    if(line[0] == '\0' || line == NULL)
		    ft_error("Invalid File\n", fd);
		i = 0;
		if((linep = ft_strsplit(line, ' ')))
		{
			i = 0;
			while(linep[i])
			{
				e = 0;
				while(linep[i][e])
				{
					if(linep[i][e] == ',')
						flag++;
					if(flag > 1)
						ft_error("only one coma to generate colors\n", fd);
					e++;
				}
				flag = 0;
				free(linep[i++]);
			}
			if(i != fst->columns_total)
				ft_error("the number of columns is not the same in every line\n", fd);  
		}
	}
	close(fd);
	return (0);
}