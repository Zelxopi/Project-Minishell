

#include "../includes/minishell.h"

int	main(void)
{
	t_dlist	*tokens;
	char	*line;

	tokens = malloc(sizeof(t_dlist));
	ft_signals();
	while (1)
	{
		line = readline("minishell$> ");
		if (line && *line)
		{
			add_history(line);
			ft_parse(line, tokens);
		}
		if (!line)
			break ;
		free(line);
	}
	rl_clear_history();
	free(tokens);
	return (0);
}
