/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 22:29:03 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/24 22:33:24 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char	*get_args(char *buffer, int i)
{
	int		size;
	char	*get_args;
	int		i_2;

	i_2 = 0;
	size = (ft_strlen(buffer + 1) - i);
	if (size)
	{
		if (!(get_args = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		while (buffer[i])
		{
			if (buffer[i] == ' ')
			{
				while (buffer[i] == ' ')
					i++;
				i--;
			}
			get_args[i_2] = buffer[i];
			i_2++;
			i++;
		}
		get_args[i_2] = '\0';
		return (get_args);
	}
	return (NULL);
}

void	handle_cmd(char *buffer)
{
	char	*get_cmd;
	int		pos;
	int		i;

	i = 0;
	buffer = ft_strtrim(buffer);
	pos = ft_strposition(buffer, " ");
	if (pos)
	{
		if (!(get_cmd = (char*)malloc(sizeof(char) * pos)))
			return ;
		while (i < pos)
		{
			if (buffer[i] != '\n')
				get_cmd[i] =* ft_strdup(&buffer[i]);
			i++;
		}
		get_cmd[i] = '\0';
		if (check_cmd(get_cmd))
			do_cmd(get_cmd, get_args(buffer, i));
		ft_putstr("\n");
	}
}
