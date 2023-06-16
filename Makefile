

NAME = minishell

SRCS =	minishell.c \
		signals.c \
		parsing/parsing.c \
		parsing/split.c \

OBJ = $(SRCS:.c=.o)

SDIR = srcs
ODIR = obj
SFIX = $(addprefix $(SDIR)/, $(SRCS))
OFIX = $(addprefix $(ODIR)/, $(OBJ))

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -fr
LIBS = ./includes/Libft/libft.a ./includes/dlist/dlist.a ./includes/readline/libreadline.a ./includes/readline/libhistory.a -lreadline -lcurses

$(ODIR):
	@mkdir -p $(ODIR)
	@mkdir -p $(ODIR)/parsing $(ODIR)/builtins

$(ODIR)/%.o:$(SDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[92m.\033[0m\c"

$(NAME): $(ODIR) $(OFIX)
	@$(MAKE) -C ./includes/Libft
	@$(MAKE) lib -C ./includes/dlist
	@$(CC) $(CFLAGS) $(OFIX) -o $(NAME) $(LIBS)


all: $(NAME)

clean:
	@$(MAKE) clean -C ./includes/Libft
	@$(RM) $(OFIX) $(ODIR)
	@echo "🧹"

fclean: clean
	@$(MAKE) fclean -C ./includes/Libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re