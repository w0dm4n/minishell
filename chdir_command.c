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

char		*get_subdir(char *path)
{
	int		i;
	char	*new_path;
	int		i_2;

	i = ft_strlen(path);
	i_2 = 0;
	if (!(new_path = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (path[i] != '/')
		i--;
	i--;
	while (i_2 <= i)
	{
		new_path[i_2] = path[i_2];
		i_2++;
	}
	new_path[i_2] = '\0';
	free(path);
	return (new_path);
}

void		change_folder(char *path)
{
	char	*old_pwd;

	old_pwd = get_env("PWD");
	chdir(path);
	ft_putstr(path);
	set_env("PWD", path);
	set_env("OLDPWD", old_pwd);
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
		args = ft_strtrim(args);
		if (args_nbr == 1)
		{
			if (!ft_strcmp(args, "-"))
				change_folder(get_env("OLDPWD"));
			else
			{
				if (!ft_strcmp(args, "../"))
					change_folder(get_subdir(get_env("PWD")));														
			}
		}
		else if (args_nbr == 2)
		{
			// add at the start of the path the second args and go in
		}
		else
			ft_putstr("cd: too many arguments");
	}
}
