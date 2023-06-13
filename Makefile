# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 14:05:08 by kafortin          #+#    #+#              #
#    Updated: 2023/06/13 14:20:45 by kafortin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = minishell

MAKE_LIBFT = cd ./Libft/ && make

FILES = ./srcs/minishell.c \
		./srcs/builtins/echo.c \
		./srcs/parsing/parsing.c \

OBJS = $(FILES:.c=.o)

RM = @rm -f

.SILENT: $(OBJS)

all: $(NAME)

$(NAME): $(OBJS)
			@$(MAKE_LIBFT)
			@echo "Compiling minishell..."
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "Completed! 🕺"

clean:
			@$(MAKE) clean -C ./Libft
			$(RM) $(OBJS)

fclean:
			@$(MAKE) fclean -C ./Libft
			$(RM) $(OBJS)
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re