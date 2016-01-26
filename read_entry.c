/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 21:23:36 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/24 21:25:29 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		read_entry(void)
{
	char	*buffer;

	if (!(buffer = (char*)malloc(sizeof(char) * READ_BUFFER)))
		return ;
	ft_putstr(COLOR_WHITE);
	ft_putstr("$> ");
	read(0, buffer, READ_BUFFER);
	if (buffer[0] == 'e' && buffer[1] == 'x' && buffer[2] == 'i'
		&& buffer[3] == 't')
		return ;
	handle_cmd(buffer);
	read_entry();
	free(buffer);
}
