/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utiles2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidboufk <oidboufk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:40:50 by iantar            #+#    #+#             */
/*   Updated: 2023/02/23 11:01:29 by oidboufk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] &&
	(((unsigned char *)s1)[i] != '\0' ||
	((unsigned char *)s2)[i] != '\0') && i < n)
	{
		i++;
	}
	if (i < n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}

char	*get_variable(char *str)
{
	char	*var;
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (str[len] && str[len] != '=')
		len++;
	var = malloc(len);
	while (str[i] && str[i] != '=')
	{
		var[i] = str[i];
		i++;
	}
	var[i] = '\0';
	return (var);
}

int	handle_cmd(char *str, t_env *env)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "env"))
	{
		while (env)
		{
			if (env->line)
				printf("%s=%s\n", env->var_name, env->line);
			env = env->next;
		}
	}
	else if (!ft_strcmp(str, "cd"))
		printf("cd");
	else if (!ft_strncmp(str, "export", 6))
		export(str, env);
	return (1);
}
