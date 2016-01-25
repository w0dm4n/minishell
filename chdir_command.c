/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 00:50:58 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/25 00:54:32 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		change_folder(char *path)
{
	char	*old_pwd;

	old_pwd = get_env("PWD");
	chdir(path);
	//set_env("PWD", path);
	//set_env("OLD_PWD", old_pwd)
}

int			get_args_nbr(char *args)
{
	int i;
	int	nbr_args;

	i = 0;
	nbr_args = 0;
	while (args[i])
	{
		if (args[i] == ' ')
			nbr_args++;
		i++;
	}
	return (nbr_args);
}

void		chdir_command(char *args)
{
	int		args_nbr;

	if (!args)
		change_folder(get_env("HOME"));
	else
	{
		args_nbr = get_args_nbr(args);
		if (args_nbr == 1)
		{
			// just go on the folder
		}
		else if (args_nbr == 2)
		{
			// add at the start of the path the second args and go in
		}
		else
			ft_putstr("cd: too many arguments");
	}
}
