/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:26:15 by kafortin          #+#    #+#             */
/*   Updated: 2023/06/19 15:00:40 by kafortin         ###   ########.fr       */
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
# define UNEXPECTED_TOKEN "Syntax error near unexpected token '%c'\n"
# define UNCLOSED_QUOTES "Unclosed quotes\n"

/*STRUCTS*/

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

#endif