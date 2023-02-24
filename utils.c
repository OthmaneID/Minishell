/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidboufk <oidboufk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:12:29 by iantar            #+#    #+#             */
/*   Updated: 2023/02/23 20:15:42 by oidboufk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free(char **str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	while (str[i])
		free(str[i++]);
	if (str)
		free(str);
	return (1);
}

char	*ft_strjoin(char *str, char *cmd)
{
	int		len1;
	int		len2;
	char	*path;
	int		i;
	int		j;

	if (!str || !cmd)
		return (0);
	i = -1;
	j = 0;
	len1 = ft_strlen(str);
	len2 = ft_strlen(cmd);
	path = malloc(sizeof(char) * (len1 + len2 + 2));
	if (!path)
		return (0);
	while (str[++i])
		path[i] = str[i];
	path[i++] = '/';
	while (cmd[j])
		path[i++] = cmd[j++];
	path[i] = '\0';
	return (path);
}
