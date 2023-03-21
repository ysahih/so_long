#include "../so_long.h"

bool map_requesties(char **map)
{
	int i;
	int j;

    i = 0;
	int p = 0, e = 0, c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (e != 1 || p != 1)
		return (false);
	else if (c == 0)
		return (false);
	return (true);
}

bool components(char **map)
{
	int i = 0, j = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool rectangular(char **map, int a)
{
	int	i;
	int	j;

	j = 0;
	while (i < a )
	{
		if (strlen(map[0]) != strlen(map[i + 1]))
			return (false);
		i++;
	}
    j = strlen(map[0]) - 1;
	if (j <= a)
		return (false);
	return (true);
}

bool walls_serounded(char **map, int a)
{
	int	i;
	int	j;

	i = 0;
	while (i < strlen(map[0]))
	{
		if ((map[0][i] != '1') || map[a][i] != '1')
			return (false);
		i++;
	}
	i = 0;
    j = strlen(map[0]) - 1;
	while  (i <= a)
	{
		if (map[i][0] != '1' && map[i][j] != '1')
			return (false);
		i++;
	}

	return (true);
}