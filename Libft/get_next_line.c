/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 18:08:10 by ivelutin          #+#    #+#             */
/*   Updated: 2017/02/22 18:08:11 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_solsub(char **line, char **aqui)
{
	int sisa;

	sisa = 0;
	if (ft_strchr(*aqui, '\n'))
	{
		*line = ft_strsub(*aqui, 0, ft_strchr(*aqui, '\n') - *aqui + 1);
		line[0][ft_strlen(*line) - 1] = 0;
		*aqui = ft_strsub(*aqui, ft_strchr(*aqui, '\n') - *aqui + 1, \
			ft_strlen(ft_strchr(*aqui, '\n')));
		return (1);
	}
	sisa = ft_strlen(*aqui);
	if (sisa > 0)
	{
		*line = ft_strdup(*aqui);
		*aqui = "\0";
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char *aqui = NULL;
	int			ret;
	char		buffer[BUFF_SIZE + 1];

	if (aqui == NULL)
		aqui = ft_strnew(0);
	if (fd < 0 || !line || read(fd, buffer, 0) < 0)
		return (-1);
	while (!(ft_strchr(aqui, '\n')))
	{
		ret = read(fd, buffer, BUFF_SIZE);
		buffer[ret] = '\0';
		aqui = ft_strjoin(aqui, buffer);
		if (!ret)
			break ;
	}
	return (ft_solsub(line, &aqui));
}
