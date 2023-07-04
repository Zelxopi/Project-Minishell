/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:26:15 by kafortin          #+#    #+#             */
/*   Updated: 2023/07/04 15:18:30 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*INCLUDES*/
# include "Libft/libft.h"
# include "dlist/dlist.h"
# include "./readline/history.h"
# include "./readline/readline.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/signal.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

/*ERROR MESSAGES*/
# define UNCLOSED_QUOTES "Unclosed quotes\n"
# define FORK_ERROR "Error: fork did not work."
# define PIPE_ERROR "Error: pipe did not work."
# define ARG_NUM_ERROR "Error: invalid number of arguments."
# define PATH_ERROR "Error: path not found."
# define COMMAND_ERROR "Error: command not found."
# define ENV_ERROR "Error: PATH is not an environment variable."
# define OPEN_ERROR "Error: file could not be opened."

/*STRUCTS*/

typedef struct path
{
	char	*path;
	char	*join;
	char	**env;
}				t_path;

typedef struct cmd
{
	t_path	path;
	char	**cmd;
}				t_cmd;

typedef struct files
{
	int		fd[2];
	int		input;
	int		output;
	pid_t	pid1;
	pid_t	pid2;
}			t_files;


/*FUNCTIONS*/

//utils
void				error_message(char *message, t_dlist *t);

/*----------parsing--------*/
//parsing
void				ft_parse(char *line, t_dlist *tokens);
char				*ft_clean_quotes(char *old_str);
char				*ft_trim_char(char *str, int ptr);
void				ft_repetition_check(t_dlist *t);
void				ft_init_dlist(t_dlist *tokens);
//split
int					ft_splitable(char c);
void				ft_minishell_split(char *args, t_dlist *t);
int					ft_quotes(char *args, int i, t_dlist *t);
int					ft_create_token(char *args, int i, int start, t_dlist *t);

/*signals*/
void				ft_signals(void);
void				ft_sigint_handler(int signum);

void run_minishell(t_dlist *t);

#endif