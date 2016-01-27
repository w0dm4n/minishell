/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 22:12:23 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/26 22:13:48 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	free_argv(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (argv[i])
			free(argv[i]);
		i++;
	}
	free(argv);
}

char	**set_argv(char **argv, char *name)
{
	if (!argv)
	{
		if (!(argv = malloc(sizeof(char*) * 1)))
			return (NULL);
		argv[0] = get_name(name);
	}
	return (argv);
}
