/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:36:02 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/21 18:51:11 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (i[s])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	p = (char *)malloc (ft_strlen (s1) + ft_strlen (s2) + 1);
	if (!p)
		return (0);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc ((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*after_newline(char *line)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	i++;
	if (line[i] == '\0')
		return (NULL);
	buff = (char *) malloc (ft_strlen(line) - i + 1);
	while (line[i])
		buff[j++] = line[i++];
	buff[j] = '\0';
	return (buff);
}

int	check_newline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		return (1);
	return (0);
}
