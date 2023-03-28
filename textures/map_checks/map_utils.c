/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:30:55 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/27 22:24:48 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	count_c(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

bool	map_requesties(char **map)
{
	int		i;
	int		j;
	t_count	c;

	i = 0;
	c = init_c();
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				c.p++;
			if (map[i][j] == 'E')
				c.e++;
			if (map[i][j] == 'C')
				c.c++;
			j++;
		}
		i++;
	}
	return (check_and_return(c));
}

bool	components(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E' &&
			map[i][j] != 'P' && map[i][j] != 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	rectangular(char **map, int a)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map[0]);
	while (i < a)
	{
		if (j != ft_strlen(map[i + 1]))
			return (false);
		i++;
	}
	if (j - 1 == a)
		return (false);
	return (true);
}

bool	walls_serounded(char **map, int a)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_strlen(map[0]))
	{
		if ((map[0][i] != '1') || map[a][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	j = ft_strlen(map[0]) - 1;
	while (i <= a)
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			return (false);
		i++;
	}
	return (true);
}
