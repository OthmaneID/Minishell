/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidboufk <oidboufk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:28:28 by oidboufk          #+#    #+#             */
/*   Updated: 2023/02/23 12:44:05 by oidboufk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	list_size(t_env	*env)
{
	size_t	i;

	i = 0;
	while (env->next)
	{
		env = env->next;
		i++;
	}
	return (i);
}

char	**sort_vars(char	**strs, int len)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(strs[i], strs[j]) > 0)
			{
				tmp = ft_strdup(strs[i]);
				free(strs[i]);
				strs[i] = ft_strdup(strs[j]);
				free(strs[j]);
				strs[j] = ft_strdup(tmp);
				free(tmp);
			}
			j++;
		}
		i++;
	}
	return (strs);
}

int	is_in_env(char	*var, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (var && env)
	{
		if (!ft_strcmp(var, env->var_name))
		{
			env = tmp;
			return (1);
		}
		env = env->next;
	}
	env = tmp;
	return (0);
}

void	print_line(char *var, t_env *env)
{
	while (env)
	{
		if (!ft_strcmp(var, env->var_name))
		{
			printf("declare -x %s", env->var_name);
			if (env->line)
				printf("=\"%s\"\n", env->line);
			else
				printf("\n");
			break ;
		}
		env = env->next;
	}
}

int	show_env_in_order(t_env *env)
{
	size_t	len;
	char	**strs;
	size_t	i;
	t_env	*send;

	len = list_size(env);
	strs = malloc((len + 1) * sizeof(char *));
	i = 0;
	send = env;
	while (env)
	{
		strs[i++] = ft_strdup(env->var_name);
		env = env->next;
	}
	sort_vars(strs, i);
	i = 0;
	while (i <= len)
		print_line(strs[i++], send);
	return (0);
}
