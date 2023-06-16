#include "../includes/minishell.h"

void	ft_signals(void)
{
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_sigint_handler(int signum)
{
	(void)signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}