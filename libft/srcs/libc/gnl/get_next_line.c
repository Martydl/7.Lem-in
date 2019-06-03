/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <mde-laga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:11:12 by mde-laga          #+#    #+#             */
/*   Updated: 2019/06/03 11:35:11 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_line(char **str, char *line, char *tmp, int fd)
{
	size_t	i;

	i = 0;
	if (ft_strchr(str[fd], '\n'))
	{
		while (str[fd][i] != '\n')
			i++;
		if (!(line = ft_strndup(str[fd], i)))
			return (NULL);
		tmp = str[fd];
		if (!(str[fd] = ft_strsub(tmp, i + 1, ft_strlen(tmp) - i)))
			return (NULL);
		free(tmp);
		return (line);
	}
	if (!(line = ft_strdup(str[fd])))
		return (NULL);
	ft_strdel(&str[fd]);
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[10240];
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || !line || fd > 10240 || BUFF_SIZE < 1
		|| (!str[fd] && (!(str[fd] = ft_strnew(1)))))
		return (-1);
	ret = 0;
	while (!ft_strchr(str[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str[fd];
		if (!(str[fd] = ft_strjoin(tmp, buf)))
			return (-1);
		free(tmp);
	}
	if (ret == -1 || (!(*line = ft_line(str, *line, tmp, fd))))
		return (-1);
	return ((ft_strlen(*line) == 0 && !str[fd]) ? 0 : 1);
}
