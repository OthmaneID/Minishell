/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidboufk <oidboufk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:12:08 by oidboufk          #+#    #+#             */
/*   Updated: 2023/02/21 11:26:04 by oidboufk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd(char *path)
{
	if (chdir(path))
		return (perror("cd error :"), 0);
	return (1);
}

int	pwd(void)
{
	char	buf[1024];
	if (!getcwd(buf, sizeof(buf)))
		return (perror("pwd error: "), 0);
	return (1);
}