/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:03:13 by aikram            #+#    #+#             */
/*   Updated: 2022/10/19 04:21:17 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_printf.h"

char	*next_line(char *str)
{
	char	*tmp;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	if (!str)
		return (0);
	while (str[i[0]] && str[i[0]] != '\n')
		i[0]++;
	if (!str[i[0]] || (!str[i[0] + 1] && str[i[0]] == '\n'))
	{
		free(str);
		return (0);
	}
	tmp = malloc(ft_strlen(&str[i[0]++]));
	if (!tmp)
		return (0);
	while (str[i[0]])
		tmp[i[1]++] = str[i[0]++];
	tmp[i[1]] = '\0';
	free(str);
	return (tmp);
}

char	*gotta_catch_em_all(char *str)
{
	char	*tmp;
	int		i;

	i = 2;
	while (str[i - 2] && str[i - 2] != '\n')
		i++;
	if (str[0] == '\0')
		return (NULL);
	tmp = malloc(i);
	if (!tmp)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		tmp[i] = str[i];
	if (str[i] == '\n')
		tmp[i++] = '\n';
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_read(char *str, char *buf, int fd)
{
	int	i;

	i = 1;
	while (i != 0 && !ft_strnl(str))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		if (!str)
		{
			str = malloc(1);
			if (!str)
				return (NULL);
			*str = '\0';
		}
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*lne;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = ft_read(str, buf, fd);
	if (!str)
		return (NULL);
	lne = gotta_catch_em_all(str);
	str = next_line(str);
	return (lne);
}
