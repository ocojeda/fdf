# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 18:15:56 by ocojeda-          #+#    #+#              #
#    Updated: 2017/02/27 09:23:50 by myernaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra  
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
SRCS = bonus.c ft_atoi_hexa.c proyection.c map.c line.c parse.c matrix.c bonus1.c aux_fdf.c fl_to_int.c line2.c ft_error.c
LIBRARIES = libft/libft.a fdf.a
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./libft
	@gcc -c $(FLAGS) $(SRCS)
	@ar rc fdf.a $(OBJECTS)
	@ranlib fdf.a
	@gcc $(FLAGS) main.c $(LIBRARIES) -o $(NAME) $(MLXFLAGS)

clean:
	@rm -f $(OBJECTS) fdf.a main.o
	@make clean -C ./libft

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
