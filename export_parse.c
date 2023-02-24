/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidboufk <oidboufk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:43:23 by oidboufk          #+#    #+#             */
/*   Updated: 2023/02/24 11:15:22 by oidboufk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	doubel_single_quotes(char	*str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == c)
			count++;
	return (count);
}

char	symbole(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '"' || str[i] == '\'')
			return (str[i]);
		i++;
	}
	return (0);
}

char	**parse_vars(char	*str)
{
	int		i;
	char	**strs;

	i = 0;
	if (!ft_strncmp(str, "export ", 7))
		str += 7;
	if (!doubel_single_quotes(str, '"')
		&& !doubel_single_quotes(str, '\''))
		return (ft_split(str, ' '));
	strs = ft_split(str, symbole(str));
	printf("%s\n", str);
	while (1);
	// while (str[i])
	// {
	// }
}
