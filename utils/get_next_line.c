/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:06:55 by ayassir           #+#    #+#             */
/*   Updated: 2022/03/16 14:33:18 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*func_rest(char *save, int len, int i)
{
	int			j;
	char		*ptr;

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < len)
	{
		ptr[j] = save[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	if (ptr[0] == '\0')
	{
		free(ptr);
		free(save);
		return (NULL);
	}
	free(save);
	return (ptr);
}

static char	*get_rest(char *save)
{
	int			i;
	int			len;

	i = 0;
	len = (int) ft_strlen(save);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	else if (save[i] == '\n')
		i++;
	len = len - i + 1;
	return (func_rest(save, len, i));
}

static char	*get_line(char *save)
{
	int		i;
	char	*ptr;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < i)
	{
		ptr[j] = save[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

static char	*get_next(char *save, int fd)
{
	int				rd;
	char			*buf;

	rd = 1;
	while (rd > 0)
	{
		buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free (buf);
			return (NULL);
		}
		if (rd == 0)
		{
			free(buf);
			break ;
		}
		buf[rd] = '\0';
		save = ft_strjoin(save, buf);
		free(buf);
		if (ft_strchr(save) == 1)
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = get_next(save, fd);
	if (save == NULL)
		return (NULL);
	line = get_line(save);
	save = get_rest(save);
	return (line);
}
