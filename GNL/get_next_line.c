/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iantar <iantar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:27:10 by iantar            #+#    #+#             */
/*   Updated: 2022/11/11 21:17:39 by iantar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char **s1, char **s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	i = -1;
	j = 0;
	len_s1 = ft_strlen(*s1);
	len_s2 = ft_strlen(*s2);
	ptr = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!ptr)
		return (free_it(s1, s2));
	while (++i < len_s1)
		*(ptr + i) = *(*s1 + i);
	while (j < len_s2)
		*(ptr + i++) = *(*s2 + j++);
	*(ptr + i) = '\0';
	return ((free_it(s1, 0)), ptr);
}

static char	*no_bak_n(char **save_buf, char **buf)
{
	char	*temp;
	size_t	i;

	temp = 0;
	i = 0;
	if (*save_buf && **save_buf)
	{
		temp = (char *)malloc((ft_strlen(*save_buf) + 1) * sizeof(char));
		if (!temp)
			return (free_it(save_buf, buf));
		while (*(*save_buf + i))
		{
			*(temp + i) = *(*save_buf + i);
			i++;
		}
		*(temp + i) = '\0';
		return ((free_it(save_buf, buf)), temp);
	}
	return (0);
}

static char	*rtn_buf(char **save_buf, char **buf, int check)
{
	size_t	index;

	index = 0;
	if (*buf && **buf)
		*save_buf = ft_strjoin(save_buf, buf);
	if (!check)
		free_it(buf, 0);
	if (*save_buf)
		index = find(*save_buf);
	if (!index && !*buf)
		return (no_bak_n(save_buf, buf));
	if (index)
		return (ft_substr(save_buf, index));
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*save_buf;
	char		*buf;
	int			check;
	char		*rtn;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_it(&save_buf, 0));
	buf = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free_it(0, &save_buf));
	check = 1;
	while (check)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
			return (free_it(&buf, &save_buf));
		buf[check] = '\0';
		rtn = rtn_buf(&save_buf, &buf, check);
		if (rtn)
			return (free(buf), rtn);
	}
	return ((free_it(&save_buf, 0)), rtn_buf(&save_buf, &buf, check));
}
