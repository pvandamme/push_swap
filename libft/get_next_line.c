/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerien <rmerien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:25:23 by rmerien           #+#    #+#             */
/*   Updated: 2018/12/30 22:01:59 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_cleanup(char **cpy, char **line, int fd, int rd_ret)
{
	char		*tmp;
	size_t		len;

	len = ft_lentoc(cpy[fd], ENDL);
	if (cpy[fd][len] == ENDL)
	{
		*line = ft_strsub(cpy[fd], 0, len);
		tmp = ft_strdup(cpy[fd] + len + 1);
		free(cpy[fd]);
		cpy[fd] = tmp;
		if (!cpy[fd])
			ft_strdel(&cpy[fd]);
	}
	else if (!cpy[fd][len])
	{
		if (rd_ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(cpy[fd]);
		ft_strdel(&cpy[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*cpy[10000];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			rd_ret;

	if (fd < 0 || !line || !(cpy[fd] = !cpy[fd] ? ft_strnew(0) : cpy[fd]) ||
			(read(fd, buf, 0) < 0) || fd >= 10000)
		return (-1);
	while ((rd_ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd_ret] = 0;
		tmp = ft_strjoin(cpy[fd], buf);
		free(cpy[fd]);
		cpy[fd] = tmp;
		if (ft_strchr(buf, ENDL))
			break ;
	}
	if (rd_ret < 0)
		return (-1);
	else if (!rd_ret && (!cpy[fd] || !cpy[fd][0]))
	{
		free(cpy[fd]);
		return (0);
	}
	return (ft_cleanup(cpy, line, fd, rd_ret));
}
