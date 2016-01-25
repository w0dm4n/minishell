/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 22:49:11 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/24 22:50:17 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		check_cmd(char *cmd)
{
	if (!ft_strcmp(cmd, "cd") ||
		!ft_strcmp(cmd, "setenv") ||
		!ft_strcmp(cmd, "env") ||
		!ft_strcmp(cmd, "exit") ||
		!ft_strcmp(cmd, "clear") ||
		!ft_strcmp(cmd, "whoami") ||
		!ft_strcmp(cmd, "pwd"))
		return (1);
	else
	{
		ft_putstr("minishell: command not found: ");
		ft_putstr(cmd);
		return (0);
	}
}
