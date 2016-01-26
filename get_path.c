/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_folder_access.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 22:16:48 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/25 22:19:47 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char	*add_folder_on_path(char *path, char *folder)
{
	char	*new_path;
	int		new_size;

	new_size = (ft_strlen(path + 1) + (ft_strlen(folder + 1)));
	if (!(new_path = (char*)malloc(sizeof(char) * new_size)))
		return (NULL);
	new_path = ft_strcat(new_path, path);
	new_path = ft_strcat(new_path, "/");
	new_path = ft_strcat(new_path, folder);
	return (new_path);
}

char	*go_above(char *args, char *path, int i, int i_2)
{
	char	*folder;

	folder = ft_strnew(1024);
	while (args[i])
	{
		if (args[i] == '.' && args[i + 1] == '.'
			&& args[i + 2] == '/')
			path = get_subdir(path);
		else
		{
			while (args[i])
			{
				if (args[i] == '/' ||
					args[i] == '.')
					break ;
				folder[i_2] = args[i];
				i++;
				i_2++;
			}
			folder[i_2] = '\0';
			if (folder[0])
				path = add_folder_on_path(path, folder);
			i_2 = 0;
			ft_bzero(folder, 1024);
		}
		i++;
	}
	free(folder);
	return (path);
}

char	*go_inside(char *args, char *path, int i, int i_2)
{
	char	*folder;

	folder = ft_strnew(1024);
	while (args[i])
	{
		if (args[i] == '/' || args[i + 1] == '\0'
			|| args[i] == '\n')
		{
			if (folder[0])
				path = add_folder_on_path(path, folder);
			ft_bzero(folder, 1024);
			i_2 = 0;
		}
		else
		{
			folder[i_2] = args[i];
			if (args[i + 2] == '\0')
				folder[i_2 + 1] = args[i + 1];
			i_2++;
		}
		i++;
	}
	free(folder);
	return (path);
}

int		get_path(char *path, char *args)
{
	int		subdir;

	if (!args)
		if (!(args = ft_strnew(1)))
			return (-1);
	subdir = 0;
	if (args[0] == '.')
		path = go_above(args, path, 0, 0);
	else if (args[0] == '/')
		path = args;
	else
		path = go_inside(args, path, 0, 0);
	return ((check_access_folder(path, args) ? 1 : 0));
}
