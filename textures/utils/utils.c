/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:46:50 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/27 18:11:57 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	cross_hook(t_data *info)
{
	if (info)
		exit(0);
	return (0);
}

void	check_map_name(char *s)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(s);
	if (s[size - 4] != '.' || s[size - 3] != 'b'
		|| s[size - 2] != 'e' || s[size - 1] != 'r')
	{
		write (1, "Invalid Map Name\n", 17);
		exit (0);
	}
}

int	calculate_size(char *file)
{
	int		i;
	int		fd;
	char	*s;

	fd = open (file, O_RDONLY);
	if (fd == -1)
	{
		perror ("Error");
		exit (1);
	}
	i = 0;
	while (true)
	{
		s = NULL;
		s = gnl (fd);
		if (s == NULL)
			break ;
		free (s);
		i++;
	}
	close (fd);
	return (i);
}
