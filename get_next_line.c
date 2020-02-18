/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 12:04:00 by ninieddu     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 12:40:50 by ninieddu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buffer;
	int			rret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0
		|| (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while (ft_lenline(save) == -1 && (rret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rret] = '\0';
		if (!(save = ft_strjoin(save, buffer)))
			return (-1);
	}
	buffer = ft_free(buffer);
	if (ft_lenline(save) >= 0)
		return (next_gnl(&save, line, &buffer));
	*line = ft_substr(save, 0, ft_strlen(save));
	save = ft_free(save);
	return (0);
}

int		next_gnl(char **save, char **line, char **buffer)
{
	char	*buff_tmp;

	*line = ft_substr(*save, 0, ft_lenline(*save));
	buff_tmp = ft_substr(*save, 0, ft_strlen(*save));
	*buffer = *save;
	*save = ft_substr(buff_tmp, (ft_lenline(*save) + 1), ft_strlen(*save));
	*buffer = ft_free(*buffer);
	buff_tmp = ft_free(buff_tmp);
	return (1);
}
