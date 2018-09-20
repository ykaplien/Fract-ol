# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 14:06:53 by ykaplien          #+#    #+#              #
#    Updated: 2018/09/19 14:07:17 by ykaplien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = main.c\

FLAGS = -Wall -Werror -Wextra
HEADER = fdf.h
OBJS = $(SRCS:.c=.o)

all: $(NAME) 

%.o: %.c
	@ gcc -o $@ -c $< -I ./

$(NAME):
	@ make -C libft re
	@ gcc -lmlx -framework OpenGL -framework AppKit $(SRCS) libft/libft.a -o $(NAME) -lm

clean:
	@ make -C libft clean

fclean: clean
	@ rm -f $(NAME)
	@ make -C libft fclean

re: fclean all