/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:26:15 by kafortin          #+#    #+#             */
/*   Updated: 2023/06/16 16:15:11 by mtrembla         ###   ########.fr       */
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
# define ERROR "ERROR\n"

/*STRUCTS*/

/*FUNCTIONS*/

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
void	ft_signals(void);
void	ft_sigint_handler(int signum);

#endif