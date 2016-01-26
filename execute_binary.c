/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 04:32:15 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/26 04:33:43 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		launch_process(char *path, char *name, char *cmd, char **env)
{
	char	*get_path;
	int		size;
	char	**argv;
	int		child_status;
	pid_t	child_pid;

	size = (ft_strlen(path + 1) + ft_strlen(name + 1) + 1);
	if (!(get_path = malloc(sizeof(char) * size)))
		return ;
	get_path = ft_strcat(get_path, path);
	get_path = ft_strcat(get_path, "/");
	get_path = ft_strcat(get_path, name);
	cmd = ft_strtrim(cmd);
	argv = ft_strsplit(cmd, ' ');
	child_pid = fork();
	if (child_pid == 0)
	{
		execve(get_path, argv, env);
		exit(0);
	}
	else
	{
		pid_t tpid = wait(&child_status);
		while (tpid != child_pid)
			;
	}
	// CHECK WHY WHEN I DO ls -fewfewfwefwefwefweffew i have -fewfewfewfewwefewfwPATH
	//fix segv and set argv[0] as file name
}

void		execute_binary(char *name, char *cmd_args, char **env, int res)
{
	char	**all_path;
	int		i;

	i = 0;
	all_path = ft_strsplit(get_env("PATH"), ':');
	while (all_path[i])
	{
		if (i == res)
			launch_process(all_path[i], name, cmd_args, env);
		i++;
	}
}
