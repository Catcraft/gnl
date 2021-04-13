/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:04:47 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/12 08:50:19 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		gnl_strlen(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_lenline(char *s);
char	*ft_substr_gnl(char *s, int start, int len);
char	*ft_free(char *s);
int		next_gnl(char **save, char **line, char **buffer);

#endif
