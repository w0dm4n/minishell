/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_from_asked_dir.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:57:16 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/08 10:57:17 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	launch_process_from_asked_dir(char *path, char *args, char **env)
{
	char	**argv;

	argv = NULL;
	if (args && args[0] && ft_strlen(args))
	{
		args = ft_strtrim(args);
		argv = ft_strsplit(args, ' ');
		argv = add_path(argv, path);
	}
	else
		argv = set_argv(argv, path);
	int i = 0;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	//launch_process_ext(path, argv, env);
}

void	execute_from_asked_dir(char *cmd, char **env, char *cmd_args)
{
	if (check_stat(cmd, 1))
		launch_process_from_asked_dir(cmd, cmd_args, env);
}