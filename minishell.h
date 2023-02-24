/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidboufk <oidboufk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:41:09 by oidboufk          #+#    #+#             */
/*   Updated: 2023/02/24 11:21:22 by oidboufk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <dirent.h>
# include <sys/stat.h>
# include <termios.h>
# include "GNL/get_next_line.h"

typedef struct s_tree
{
	char			*data;
	struct s_tree	*parent;
	struct s_tree	*right_child;
	struct s_tree	*left_child;
}	t_tree;
typedef struct s_env
{
	char			*line;
	char			*var_name;
	struct s_env	*next;
}	t_env;
typedef struct s_data
{
	char			*str;
	struct s_data	*next;
}	t_data;

int		handle_cmd(char *str, t_env *env);
char	*get_variable(char *str);
int		show_env_in_order(t_env *env);
t_env	*new_line(char	*line);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str, char *cmd);
char	*get_next_line(int fd);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
int		export(char *str, t_env *env);
int		is_in_env(char	*var, t_env *env);
char	*get_variable(char *str);
size_t	len_double_char(char **strs);
int		ft_free(char **str);
char	**parse_vars(char	*str);
char	**get_key_value(char	**str);
char	symbole(char *str);
char	*save_change_quoted_value(char **str);
#endif