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

void	execute_from_asked_dir(char *cmd, char **env, char *cmd_args)
{
	env = NULL;
	cmd_args = NULL;
	if (check_stat(cmd, 1))
		launch_process(cmd, cmd, "\0", env);
}