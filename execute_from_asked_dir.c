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

char	*get_executable_name(char *cmd)
{
	int		i;
	int		i_2;
	char	*exe_name;

	i = 1;
	i_2 = 0;
	if (!(exe_name = (char*)malloc(sizeof(char) * ft_strlen(cmd + 1))))
		return (NULL);
	while (cmd[i] && cmd[i] != '/')
	{
		exe_name[i_2] = cmd[i];
		i_2++;
		i++;
	}
	return (exe_name);
}

void	execute_from_asked_dir(char *cmd, char **env, char *cmd_args)
{
	if (check_stat(cmd, 1))
		launch_process(cmd, get_executable_name(cmd), "\0", env);
}