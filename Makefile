# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 18:15:56 by ocojeda-          #+#    #+#              #
#    Updated: 2017/03/03 08:59:35 by myernaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAMEBIN = fdf.a
FLAGS = -Wall -Wextra -Werror
INC = includes
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
SRC_PATH = srcs
OBJ_PATH = obj
LIBFT_PATH = libft
LIBFTA = libft.a
LIBFT = $(addprefix $(LIBFT_PATH)/,$(LIBFTA))
SRC_NAME = bonus.c ft_atoi_hexa.c proyection.c map.c line.c parse.c matrix.c bonus1.c aux_fdf.c fl_to_int.c line2.c error.c keycode.c main.c fdf_checker.c
SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I $(INC) -o $@ -c $<

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT) ./$(NAMEBIN)
	@ar rc $(NAMEBIN) $(OBJS)
	@ranlib $(NAMEBIN)
	@gcc -o $(NAME) $(NAMEBIN) $(MLXFLAGS)
	@echo "$(GREEN)--------Fdf compiled--------$(NC)"

clean:
	@make clean -C $(LIBFT_PATH)
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@/bin/rm -rf $(NAMEBIN)
	@/bin/rm -rf $(NAME)
	@echo "$(GREEN)---Fdf removed completely---$(NC)"

re: fclean all