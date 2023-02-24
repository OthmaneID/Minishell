/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidboufk <oidboufk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:31:06 by oidboufk          #+#    #+#             */
/*   Updated: 2023/02/24 11:04:04 by oidboufk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_last(t_env *env)
{
	if (!env)
		return (0);
	while (env->next)
		env = env->next;
	return (env);
}

void	env_add_back(t_env **env, t_env *new)
{
	t_env	*last;

	if (env)
	{
		if (!*env)
			*env = new;
		else
		{
			last = env_last(*env);
			last->next = new;
		}
	}
}

size_t	len_double_char(char **strs)
{
	size_t	i;

	if (!strs)
		return (0);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	add_to_env(char	**key_value, t_env *env)
{
	char	**var;
	t_env	*new;
	char	*line;

	line = ft_strdup(*key_value);
	var = get_key_value(key_value);
	if (!is_in_env(var[0], env))
	{
		new = new_line(line);
		env_add_back(&env, new);
		return (ft_free(var), 1);
	}
	else if (var[1])
	{
		new = env;
		while (env)
		{
			if (!ft_strcmp(var[0], env->var_name))
			{
				((env->line) && (free(env->line), 0));
				env->line = ft_strdup(var[1]);
				return (ft_free(var), 1);
			}
			env = env->next;
		}
	}
	return (ft_free(var), 1);
}

int	export(char *str, t_env *env)
{
	int		vars_len;
	int		i;

	if (!ft_strcmp(str, "export"))
		show_env_in_order(env);
	else
	{
		i = 0;
		vars_len = 0;
		str += 7;
		save_change_quoted_value(&str);
		while (1);
		while (str && str[0])
			add_to_env(&str, env);
	}
	return (1);
}
