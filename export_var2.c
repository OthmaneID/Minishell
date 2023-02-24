/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidboufk <oidboufk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:12:40 by oidboufk          #+#    #+#             */
/*   Updated: 2023/02/24 12:40:26 by oidboufk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strndup(char *s1, unsigned int n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s1)
		return (0);
	ptr = (char *)malloc((n + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (s1[i] && i < n)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

t_data	*save_data(char	*str)
{
	static t_data	*data;
	t_data			*head;
	int				i;
	int				sym_count;
	char			sym;

	i = 0;
	sym_count = 2;
	head = data;
	sym = symbole(str);
	while (data)
		data = data->next;
	while (str[i])
	{
		if (str[i++] == sym)
			sym_count++;
		if (sym_count == 1)
			str += i;
		if (sym_count == 2)
		{
			sym_count = 0;
			sym = symbole((str + i));
			data = malloc(sizeof(t_data));
			data->str = ft_strndup(str, i);
			data->next = NULL;
			data = data->next;
		}
	}
	data = head;
	return (data);
}

char	*save_change_quoted_value(char **str)
{
	int		i;
	char	sym;
	int		sym_count;

	i = 0;
	sym_count = 2;
	save_data(*str);
	while ((*str)[i])
	{
		if (sym_count == 2)
		{
			sym_count = 0;
			sym = symbole((*str) + i);
		}
		if ((*str)[i++] == sym)
			sym_count++;
		if (sym_count > 0)
			(*str)[i - 1] = '*';
	}
	printf("%s\n", (*str));
	return (*str);
}

char	**get_key_value(char	**str)
{
	return (str);
}
