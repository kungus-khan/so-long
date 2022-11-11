/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:03:16 by aikram            #+#    #+#             */
/*   Updated: 2022/10/19 04:21:21 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strnl(char *s)
{
	if (!s)
		return (0);
	while (*s != '\n' && *s)
		s++;
	return (*s);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*str;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (0);
	while (i < (count * size))
		((char *)str)[i++] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s;
	int		i[2];

	i[0] = 0;
	i[1] = -1;
	if (!s1 || !s2)
		return (0);
	s = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(*s));
	if (!s)
		return (0);
	while (s1[++i[1]])
		s[i[1]] = s1[i[1]];
	free(s1);
	while (s2[i[0]])
		s[i[1]++] = s2[i[0]++];
	return (s);
}
