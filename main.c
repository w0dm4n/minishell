/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 20:59:16 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/24 21:00:37 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		main(int argc, char **argv, char **env_p)
{
	g_env = env_p;
	if (argc != 1 || argv[1])
		ft_putstr("Minishell do not take any argument !\n");
	else
		read_entry();
}
