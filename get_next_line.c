/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 12:04:00 by ninieddu     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 19:52:17 by ninieddu    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	while (s1[i])
		i += 1;
	if (!(dup = calloc(sizeof(char), i + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		dup[i] = s1[i];
	return (dup);
}

static char		*ft_strjoin(char const *s1, char const *dup)
{
	char	*s2;
	char	*s2_tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s1[i])
		i++;
	while (dup[j])
		j++;
	if (!s1 || !dup || !(s2 = calloc(sizeof(char), i + j + 1)))
		return (NULL);
	s2_tmp = s2;
	while (*s1 != '\0')
		*s2_tmp++ = *s1++;
	while (*dup != '\0')
		*s2_tmp++ = *dup++;
	return (s2);
}

static int	line_verif(char **stack, char **line)
{
	char	*tmp_stack;
	char	*strchr_stack;
	int		i;

	i = 0;
	strchr_stack = *stack;
	while (strchr_stack[i] != '\n')
		if (!strchr_stack[i++])
			return (0);
	tmp_stack = &strchr_stack[i];
	*tmp_stack = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp_stack + 1);
	return (1);
}

static int	read_file(int fd, char *heap, char **stack, char **line)
{
	int		ret;
	char	*tmp_stack;

	while ((ret = read(fd, heap, BUFFER_SIZE)) > 0)
	{
		heap[ret] = '\0';
		if (*stack)
		{
			tmp_stack = *stack;
			*stack = ft_strjoin(tmp_stack, heap);
			free(tmp_stack);
			tmp_stack = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (line_verif(stack, line))
			break ;
	}
	return (ret > 0 ? 1 : ret);
}

int		get_next_line(int const fd, char **line)
{
	static char *stack[1025];
	char		*heap;
	int			ret;
	int			i;

	if (!line || (fd < 0 || fd >= 1025) || (read(fd, stack[fd], 0) < 0)
		|| !(heap = calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	if (stack[fd])
		if (line_verif(&stack[fd], line))
			return (1);
	i = 0;
	while (i < BUFFER_SIZE)
		heap[i++] = '\0';
	ret = read_file(fd, heap, &stack[fd], line);
	free(heap);
	if (ret != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
