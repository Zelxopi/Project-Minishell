#include "../includes/minishell.h"

void	error_message(char *message, t_dlist *t)
{
	printf("ERROR - ");
	printf("%s", message);
	t->error = 1;
}
