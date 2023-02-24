/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:38:45 by iantar            #+#    #+#             */
/*   Updated: 2023/01/04 13:36:51 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_it(char **s1, char **s2)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = 0;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = 0;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	find(char	*save_buf)
{
	size_t	i;

	i = 0;
	while (save_buf[i])
	{
		if (save_buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s1)
		return (0);
	ptr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char **save_buf, size_t index)
{
	size_t	i;
	char	*ptr;
	char	*temp;

	i = 0;
	temp = 0;
	ptr = (char *)malloc(index + 1);
	if (!ptr)
		return (free_it(save_buf, 0));
	while (i < index)
	{
		*(ptr + i) = *(*save_buf + i);
		i++;
	}
	*(ptr + i) = '\0';
	if (*(*save_buf + index))
		temp = ft_strdup(*save_buf + index);
	free_it(save_buf, 0);
	*save_buf = temp;
	return (ptr);
}
