# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/07 14:30:48 by dskrypny          #+#    #+#              #
#    Updated: 2018/08/24 13:02:22 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SOURCE = check_line.c \
		 error.c \
		 links.c \
		 main.c \
		 move.c \
		 path.c \
		 pull_start_end.c \
		 rooms.c \
		 queue.c\
		 printer.c \

OBJ_DIR = ./objects/
SRC_DIR = ./source/

OBJ = $(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))

HEADER = lem_in.h

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB)
	@echo "$(NAME) compiled"

$(OBJ_DIR)%.o: %.c
	@gcc $(FLAGS) -c -o $@ $< 

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)
	@echo "obj files deleted"

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)
	@echo "$(NAME) file deleted"

re: fclean all

vpath %.c $(SRC_DIR)
