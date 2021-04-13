/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:53:36 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/13 14:53:15 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *s)
{
	free(s);
	s = NULL;
	return (s);
}

char	*ft_substr_gnl(char *s, int start, int len)
{
	int		i;
	char	*new;

	i = 0;
	if (!s)
		s = NULL;
	if (gnl_strlen(s) < start)
		len = 0;
	new = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	while (i < len && s[start])
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_substr_gnl("", 0, 0);
	new = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (new == NULL)
	{
		s1 = ft_free(s1);
		return (NULL);
	}
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	s1 = ft_free(s1);
	return (new);
}

int	ft_lenline(char *s)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

int	gnl_strlen(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
