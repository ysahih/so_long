/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:18:25 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/27 17:18:26 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_point	find_player(char **map)
{
	t_point	p;

	p.y = 0;
	while (map[p.y])
	{
		p.x = 0;
		while (map[p.y][p.x])
		{
			if (map[p.y][p.x] == 'P')
				return (p);
			p.x++;
		}
		p.y++;
	}
	return (p);
}

char	**get_map(char **map, int fd)
{
	int		i;
	char	*l;

	i = 0;
	while (true)
	{
		l = 0;
		l = gnl(fd);
		if (l == NULL)
			break ;
		map[i] = l;
		i++;
	}
	return (map);
}

char	**read_map(char *s, int *row)
{
	int		fd;
	int		size;
	char	**map;

	size = calculate_size(s);
	if (!size)
	{
		write (1, "Invalid Map\n", 12);
		exit (1);
	}
	map = malloc((size * sizeof(char *)) + 1);
	if (!map)
		return (0);
	map[size] = NULL;
	fd = open (s, O_RDONLY);
	if (fd == -1)
	{
		perror ("Error");
		exit (0);
	}
	*row = size;
	return (get_map (map, fd));
}

int	count_items(char **s)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if ((s[i][j] == 'E') || (s[i][j] == 'C'))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

bool	found_elmnt(char c)
{
	if (c == 'C' || c == 'E')
		return (true);
	return (false);
}
