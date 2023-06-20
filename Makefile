

NAME = minishell

SRCS =	./srcs/minishell.c \
		./srcs/signals.c \
		./srcs/utils.c \
		./srcs/parsing/parsing.c \
		./srcs/parsing/split.c \

OBJS = $(SRCS:.c=.o)

ODIR = obj
OFIX = $(addprefix $(ODIR)/, $(OBJS))

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -fr
LIBS = ./includes/Libft/libft.a ./includes/dlist/dlist.a ./includes/readline/libreadline.a ./includes/readline/libhistory.a -lreadline -lcurses

$(ODIR):
	@mkdir -p $(ODIR)
	@mkdir -p $(ODIR)/parsing $(ODIR)/builtins

# $(ODIR)/%.o:srcs/%.c
# 	@$(CC) $(CFLAGS) -c $< -o $@
# 	@echo "\033[92m.\033[0m\c"

$(NAME): $(OBJS)
	@$(MAKE) -C ./includes/Libft
	@$(MAKE) lib -C ./includes/dlist
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

re: fclean all

.PHONY: all clean fclean re