

NAME = minishell

SRCS =	./srcs/minishell.c \
		./srcs/signals.c \
		./srcs/utils.c \
		./srcs/parsing/parsing.c \
		./srcs/parsing/split.c \

OBJS = $(SRCS:.c=.o)

.SILENT: $(OBJS)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -fr
LIBS = ./includes/Libft/libft.a ./includes/dlist/dlist.a ./includes/readline/libreadline.a ./includes/readline/libhistory.a -lreadline -lcurses

$(NAME): $(OBJS)
	@$(MAKE) -C ./includes/Libft
	@$(MAKE) lib -C ./includes/dlist
	# @cd ./includes/readline && ./configure
	# @$(MAKE) everything -C ./includes/readline
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

all: $(NAME)

clean:
	@$(MAKE) clean -C ./includes/Libft
	@$(RM) $(OBJS)
	@$(RM) $(ODIR)
	@echo "🧹"

fclean: clean
	@$(MAKE) fclean -C ./includes/Libft
	@$(RM) $(NAME)

rclean:
	@$(MAKE) clean -C ./includes/readline

re: fclean all

.PHONY: all clean fclean rclean re