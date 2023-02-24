/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidboufk <oidboufk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:04:28 by oidboufk          #+#    #+#             */
/*   Updated: 2023/02/23 11:35:59 by oidboufk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_env;

t_tree	*add_to_tree(t_tree **parent, char *content, char c)
{
	t_tree	*node;

	node = malloc(sizeof(t_tree));
	if (!parent)
		node->parent = NULL;
	else
		node->parent = (*parent);
	if (!c)
		return (free(node), NULL);
	if (parent && c == 'l')
	{
		(*parent)->left_child = node;
		(*parent)->right_child = NULL;
	}
	else if (parent && c == 'r')
	{
		(*parent)->left_child = NULL;
		(*parent)->right_child = node;
	}
	node->data = content;
	node->left_child = NULL;
	node->right_child = NULL;
	return (node);
}

t_env	*new_line(char	*line)
{
	t_env	*node;
	char	**str;
	int		i;

	i = 0;
	str = ft_split(line, '=');
	node = malloc(sizeof(t_env));
	node->var_name = ft_strdup(str[0]);
	if (len_double_char(str) == 2)
		node->line = ft_strdup(str[1]);
	else if (len_double_char(str) == 1)
		node->line = NULL;
	node->next = NULL;
	while (str[i])
		free(str[i++]);
	free(str);
	return (node);
}

size_t	nb_lines(char **env)
{
	size_t	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

t_env	*create_env(char **env)
{
	t_env	*head;
	t_env	*fetch;
	int		i;

	i = 0;
	head = new_line(env[i++]);
	fetch = head;
	while (env[i])
	{
		head->next = new_line(env[i++]);
		head = head->next;
	}
	head = fetch;
	return (head);
}

int	main(int ac, char *av[], char **env)
{
	t_env	*env_stru;
	char	*str;

	(void)ac;
	(void)av;
	env_stru = create_env(env);
	str = readline("bash -$ ");
	handle_cmd(str, env_stru);
	while (str)
	{
		free(str);
		str = readline("bash -$ ");
		handle_cmd(str, env_stru);
	}
	return (1);
}
