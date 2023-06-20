

#include "../../includes/minishell.h"

int	ft_splitable(char c)
{
	if (c == ' ' || c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

void	ft_minishell_split(char *args, t_dlist *t)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (args && args[i])
	{
		while (args[i] == '\"' || args[i] == '\'')
			i = ft_quotes(args, i, t);
		if (ft_splitable(args[i]))
		{
			i = ft_create_token(args, i, start, t);
			start = i + 1;
		}
		if (args[i])
			i++;
	}
	if (!ft_splitable(args[i - 1]))
		dlist_add_back(t, ft_substr(args, start, (i - start)));
}

int	ft_quotes(char *args, int i, t_dlist *t)
{
	char	quote;

	quote = args[i++];
	while (args[i] && args[i] != quote)
		i++;
	if (args[i])
		return (i + 1);
	error_message(UNCLOSED_QUOTES, t);
	return (i);
}

int	ft_create_token(char *args, int i, int start, t_dlist *t)
{
	if (args[i - 1] && !ft_splitable(args[i - 1]))
	{
		dlist_add_back(t, ft_substr(args, start, (i - start)));
		start = i;
	}
	if (args[i + 1] && args[i] == args[i + 1])
		i++;
	if (args[i] != ' ')
		dlist_add_back(t, ft_substr(args, start, (i - start + 1)));
	return (i);
}
