# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglens <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 17:25:06 by cglens            #+#    #+#              #
#    Updated: 2016/09/27 18:03:16 by cglens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gcc 

SRC = fractol.c\
	  init.c\
	  event.c\
	  model.c\
	  color.c\

OBJ = $(SRC:.c=.o) 

EXEC = fractol

$(NAME) :
	make -C libft	
	gcc -g  -lmlx -framework OpenGL -framework AppKit -o $(EXEC) libft/libft.a $(SRC)
clean:
	rm -f $(OBJ) $(EXEC)
	make clean -C libft

fclean: clean
	make fclean -C libft

re: fclean $(NAME)
	make fclean all -C libft
