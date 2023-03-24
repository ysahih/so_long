#include "../so_long.h"

int calculate_size(char *file)
{
	int	i;
	int fd = open(file,O_RDONLY);
	if (fd == -1 )
		return (0);
	i = 0;
	while((gnl(fd)) != NULL)
		i++;
	close(fd);
	return (i);
}

t_point find_player(char **map)
{
	t_point   p;
	// int flag = 0;
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
		// if (flag)
		// 	break;
		p.y++;
	}
	return(p);
}

char** read_map(int *a)
{
	int i = 0;
	int size = calculate_size("maps/map.ber");
	char **map = malloc(size * sizeof(char *) + 1);
	if (!map){
		return 0;
	}
	map[size] = NULL;
	int fd = open("maps/map.ber",O_RDONLY);
	if (fd == -1)
		return 0;
	while(true)
	{
		char* l = 0;
		l = gnl(fd);
		if (l == NULL)
			break;
		// printf("%d  %c\n", l[0], l[0]);
		// if (l[0] == '\n' || l[0] == 0)
			// return (NULL);
		map[i] = l;
		i++;
	}
	*a = i;
	return(map);
}
int count_items(char **s)
{
	int i = 0;
	int j;
	int count = 0;
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

bool found_elmnt(char c)
{
	if (c == 'C' || c == 'E')
		return (true);
	return (false);
}