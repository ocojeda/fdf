#include "../includes/fdf.h"

int     ft_errorcheck(int error)
{
    if(error == 1)
        ft_error("Need 2 arguments\n");
    return (0);
}

int     fdf_checker(t_screen *fst , int argc, char **argv)
{
    int         fd;
    char		**linep;
	char		*line;
	int         i;

    i = 0;
    if (argc != 2)
    {
        fst->error = 1;
        return (1);
        ft_putstr(argv[1]);
    }
    ft_file(argv[1]);
    
    if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Invalid File\n");
    i  = get_next_line(fd, &line);
    if (line == NULL)
        ft_error("Empty file\n");
    if (i == -1)
        ft_error("Invalid File\n");
    if(!ft_strchr(line, ' '))
        ft_error("Invalid File\n");
    if(line[0] == '\0' || line == NULL)
        ft_error("Invalid File\n");
    linep = ft_strsplit(line, ' ');
    i = 0;
    while(linep[i])
    {
         free(linep[i]);
         i++;
    }
    free(line);
    fst->columns_total = i;
    if(get_next_line(fd, &line))
    {
        if((linep = ft_strsplit(line, ' ')))
        {
            i = 0;
            while(linep[i])
            {
                free(linep[i]);
                i++;
            }
            if(i != fst->columns_total)
                ft_error("the number of columns is not the same in every line\n");
            while(get_next_line(fd, &line))
            {
                if((linep = ft_strsplit(line, ' ')))
                {
                    i = 0;
                    while(linep[i])
                    {
                        free(linep[i]);
                        i++;
                    }
                    if(i != fst->columns_total)
                        ft_error("the number of columns is not the same in every line\n");
                }
            }  
        }
    }
    close(fd);
    return (0);
}