/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:44:07 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/27 18:11:50 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*get_ret(char *s)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = -1;
	while (s[i])
		i++;
	ret = malloc(i + 1);
	while (s[++j])
		ret[j] = s[j];
	ret[j] = 0;
	free(s);
	return (ret);
}

char	*new_str(char *s, char c)
{
	int		i;
	char	*ret;
	int		j;

	i = 0;
	j = -1;
	while (s[i])
		i++;
	if (c == '\n')
		return (get_ret(s));
	else
	{
		ret = malloc (i + 2);
		while (s[++j])
			ret[j] = s[j];
		ret[i++] = c;
		ret[i] = 0;
	}
	free (s);
	return (ret);
}

char	*join(char *s, char c)
{
	if (!s)
	{
		s = malloc(2);
		if (!s)
			return (0);
		if (c == '\n')
		{
			write(1, "Invalid Map\n", 12);
			exit (0);
		}
		s[0] = c;
		s[1] = 0x0;
		return (s);
	}
	return (new_str(s, c));
}

char	init_vars(char **buff, char r)
{
	*buff = join(*buff, r);
	return (r);
}

char	*gnl(int fd)
{
	char		r;
	int			i;
	char		*buff;
	static char	previous;

	buff = 0;
	while (1)
	{
		i = read(fd, &r, 1);
		if (i == -1)
			return (0);
		else if (i == 0)
		{
			if (previous == '\n')
				ft_exit();
			break ;
		}
		previous = init_vars (&buff, r);
		if (r == '\n')
			break ;
	}
	if (!buff || *buff == '\0')
		return (0);
	return (buff);
}
