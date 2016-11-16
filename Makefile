# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglens <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 17:25:06 by cglens            #+#    #+#              #
#    Updated: 2016/10/23 13:16:39 by cglens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gcc 

SRC = fractol.c\
	  main.c\
	  mouse_event.c\
	  key_event.c\
	  color.c\
	  init_model.c

OBJ = $(SRC:.c=.o) 

EXEC = fractol

$(NAME) :
	make -C libft	
	gcc -lmlx -framework OpenGL -framework AppKit -o $(EXEC) libft/libft.a $(SRC) -I libft/includes
clean:
	rm -f $(OBJ) $(EXEC)
	make clean -C libft

fclean: clean
	make fclean -C libft

re: fclean $(NAME)
	make fclean all -C libft
