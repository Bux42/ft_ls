# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: videsvau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/29 11:47:13 by videsvau          #+#    #+#              #
#    Updated: 2017/09/04 18:51:50 by videsvau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror libft/libft.a

SRC = count_spaces.c \
	  flags.c \
	  ft_ls.c \
	  ft_strcolor.c \
	  insert_list.c \
	  l_flag.c \
	  list.c \
	  print_av.c \
	  print_list.c \
	  sort_av.c \
	  string_manipulation.c \
	  list_manipulation.c \
	  compare_time.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all
