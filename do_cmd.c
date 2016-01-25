/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 22:50:27 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/24 22:51:21 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		do_cmd(char *cmd, char *cmd_args)
{
	if (!ft_strcmp(cmd, "cd"))
		chdir_command(cmd_args);
	if (!ft_strcmp(cmd, "whoami"))
		ft_putstr(get_env("USER"));
	if (!ft_strcmp(cmd, "pwd"))
		ft_putstr(get_env("PWD"));
	if (!ft_strcmp(cmd, "env"))
		print_all_env();
}
