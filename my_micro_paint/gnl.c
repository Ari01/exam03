/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:55:11 by dchheang          #+#    #+#             */
/*   Updated: 2021/11/03 16:24:07 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mp.h"

int	readfile(FILE *file, char **buff)
{
	char	tmp[BUFFER_SIZE];
	char	*freeptr;
	int		rd;

	rd = fread(tmp, sizeof(*tmp), BUFFER_SIZE - 1, file);
	while (rd > 0)
	{
		tmp[rd] = 0;
		if (!*buff)
			*buff = ft_strdup(tmp);
		else
		{
			freeptr = *buff;
			*buff = ft_strjoin(*buff, tmp);
			free(freeptr);
		}
		if (ft_strchr(tmp, '\n'))
			return (1);
		rd = fread(tmp, sizeof(*tmp), BUFFER_SIZE - 1, file);
	}
	if (rd < 0)
		return (-1);
	return (0);
}

int	readbuff(char **buff, char **line)
{
	char	*endline;
	char	*tmp;
	int		len;

	endline = ft_strchr(*buff, '\n');
	if (!endline)
	{
		*line = ft_strdup(*buff);
		free(*buff);
		return (0);
	}
	len = endline - *buff;
	printf("len = %d\n", len);
	*line = ft_substr(*buff, 0, len);
	tmp = ft_substr(*buff, len, ft_strlen(*buff) - len);
	free(*buff);
	*buff = tmp;
	return (1);
}

int	get_next_line(FILE *file, char **line)
{
	static char	*buff;
	int			file_ret;
	int			buff_ret;

	buff_ret = 1;
	if (!file || !line)
		return (-1);
	file_ret = readfile(file, &buff);
	if (file_ret < 0)
		return (-1);
	if (buff)
		buff_ret = readbuff(&buff, line);
	if (!file_ret && !buff_ret)
		return (0);
	return (1);
}
