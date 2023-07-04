

#include "../../includes/minishell.h"

void	ft_parse(char *line, t_dlist *tokens)
{
	char	*args;

	args = line;
	tokens->error = 0;
	ft_minishell_split(args, tokens);
	ft_repetition_check(tokens);
	view(*tokens);
	if (!tokens->error)
		run_minishell(tokens);
	dlist_free_content(tokens);
}

char	*ft_clean_quotes(char *str)
{
	char	quote;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quote = str[i];
			str = ft_trim_char(str, i);
			while (str[i] && str[i] != quote)
				i++;
			if (str[i])
				str = ft_trim_char(str, i);
		}
		else
			i++;
	}
	return (str);
}

char	*ft_trim_char(char *str, int ptr)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		if (i != ptr)
			newstr[j++] = str[i];
		i++;
	}
	free(str);
	return (newstr);
}

void	ft_repetition_check(t_dlist *t)
{
	t_node	*temp;
	char	*str;
	char	c;

	temp = t->first;
	while (temp)
	{
		str = temp->content;
		if (*str == '<' || *str == '>' || *str == '|')
		{
			c = *str;
			if (!temp->next)
				break ;
			str = temp->next->content;
			if (*str == c)
			{
				printf("Syntax error near unexpected token '%c'\n", c);
				t->error = 1;
				break ;
			}
		}
		c = '\0';
		temp = temp->next;
	}
}
