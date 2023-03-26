#include "../so_long.h"

int	calculate_size(char *file)
{
	int	i;
	int	fd;

	fd = open(file,O_RDONLY);
	if (fd == -1 )
		return (0);
	i = 0;
	while((gnl(fd)) != NULL)
		i++;
	close(fd);
	return (i);
}

t_point	find_player(char **map)
{
	t_point	p;
	p.y = 0;
	while (map[p.y])
	{
		p.x = 0;
		while(map[p.y][p.x])
		{
			if (map[p.y][p.x] == 'P'){
				return (p);
			}
			p.x++;
		}
		p.y++;
	}
	return(p);
}

char	**read_map(int *row)
{
	int	i;
	int	size;
	int	fd;

	i = 0;
	size = calculate_size("maps/map.ber");
	if (!size)
	{
		write(1, "Invalid Map\n", 12);
		exit(0);
	}
	char **map = malloc(size * sizeof(char *) + 1);
	if (!map)
		return (0);
	map[size] = NULL;
	fd = open("maps/map.ber",O_RDONLY);
	if (fd == -1 )
		return (0);
	while(true)
	{
		char* l = 0;
		l = gnl(fd);
		if (l == NULL)
			break;
		map[i] = l;
		i++;
	}
	*row = i;
	return(map);
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
			if  ((s[i][j] == 'E') || (s[i][j] == 'C'))
				count++;
			if (s[i][j] == '\n')
				return(0);
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