
#include "../../includes/minishell.h"

void run_minishell(t_dlist *t)
{
	t_node *token;

	token = t->first;

	if (!ft_strcmp((char *)token->content, "<<"))
		printf("here_doc\n");
	else if (!ft_strncmp((char *)token->content, "<", 1) || !ft_strncmp((char *)token->content, ">", 1))
		printf("redirection\n");
	else if (!ft_strncmp((char *)token->content, "|", 1))
		printf("pipe\n");
	else
		printf("try command\n");
	

}