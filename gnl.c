#include"so_long.h"

char	*get_line(char *map)
{
	int		i;
	char	*str;

	i = 0;
	while (map[i] != '\n')
		i++;
	str = malloc(i + 2);
	i = 0;
	while (map[i] != '\n')
	{
		str[i] = map[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	get_main(char **buff, char **str)
{
	char	*s;

	if (check_newline(*buff))
	{
		*str = get_line(*buff);
		s = after_newline(*buff);
		free (*buff);
		*buff = s;
		return (1);
	}
	else
	{
		*str = *buff;
		*buff = NULL;
		return (0);
	}
}

int	ft_main(char **line, char **str, char **buff)
{
	char	*s1;
	char	*s2;

	if (check_newline(*line))
	{
		s1 = get_line(*line);
		if (*str == NULL)
			*str = s1;
		else
		{
			s2 = ft_strjoin(*str, s1);
			free(*str);
			free(s1);
			*str = s2;
		}
		*buff = after_newline(*line);
		free (*line);
		return (1);
	}
	s1 = ft_strjoin(*str, *line);
	free(*str);
	*str = s1;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*str;
	char		*line;
	int			i;

	str = NULL;
	if (BUFFER_SIZE <= 0)
		return (0);
	if (buff)
		if (get_main(&buff, &str))
			return (str);
	line = (char *)malloc (BUFFER_SIZE + 1);
	if (!line)
		return (0);
	*line = 0;
	i = read(fd, line, BUFFER_SIZE);
	while (i > 0)
	{
		line[i] = 0;
		if (ft_main(&line, &str, &buff))
			return (str);
		i = read(fd, line, BUFFER_SIZE);
	}
	free(line);
	return (str);
}

	// puts("ch9m");
// bool map_requesties(char **s)
// {
// 	int i = 0;
// 	int j;
// 	int p = 0, e = 0, c = 0;
// 	while (s[i])
// 	{
// 		j = 0;
// 		while (s[i][j])
// 		{
// 			if (s[i][j] == 'P')
// 				p++;
// 			if (s[i][j] == 'E')
// 				e++;
// 			if (s[i][j] == 'C')
// 				c++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (e != 1 || p != 1)
// 		return (false);
// 	else if (c == 0)
// 		return (false);
// 	return (true);
// }

// bool components(char **map)
// {
// 	int i = 0, j = 0;
// 	while(map[i])
// 	{
// 		j = 0;
// 		while(map[i][j])
// 		{
// 			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'C')
// 				return (false);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (true);
// }

// bool rectangular(char **map, int a)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (i < a )
// 	{
// 		if (strlen(map[0]) != strlen(map[i + 1]))
// 			return (false);
// 		i++;
// 	}
//     j = strlen(map[0]) - 1;
// 	if (j <= a)
// 		return (false);
// 	return (true);
// }

// bool walls_serounded(char **map, int a)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < strlen(map[0]))
// 	{
// 		if ((map[0][i] != '1') || map[a][i] != '1')
// 			return (false);
// 		i++;
// 	}
// 	i = 0;
//     j = strlen(map[0]) - 1;
// 	while  (i <= a)
// 	{
// 		if (map[i][0] != '1' && map[i][j] != '1')
// 			return (false);
// 		i++;
// 	}

// 	return (true);
// }

// bool map_valid(char **map, int a)
// {	
// 	a--;
// 	if (map_requesties(map) && components(map) && rectangular(map, a), walls_serounded(map, a))
// 		return (true);
// 	return (false);
// }

// int calculate_size(char *file)
// {
// 	int	i;
// 	int fd = open("maps/map.yber",O_RDONLY);
// 	if (fd == -1 )
// 		return (0);
// 	i = 0;
// 	while((get_next_line(fd)) != NULL)
// 		i++;
// 	close(fd);
// 	return (i);
// }

// point find_player(char **map)
// {
// 	// int flag = 0;
// 	point p;
// 	p.y = 0;
// 	p.y = 0;
// 	while (map[p.y])
// 	{
// 		p.y = 0;
// 		while(map[p.y][p.y])
// 		{
// 			if (map[p.y][p.y] == 'P'){
// 				// flag = 1;
// 				return p;
// 				// break;
// 			}
// 			p.y++;
// 		}
// 		// if (flag)
// 		// 	break;
// 		p.y++;
// 	}
// 	p.y = 0;
// 	p.y = 0;
// 	return(p);
// }

// char** read_map(int *a)
// {
// 	int i = 0;
// 	int size = calculate_size("maps/map.yber");
// 	char **map = malloc(size * sizeof(char *) + 1);
// 	if (!map){
// 		return 0;
// 	}
// 	map[size] = NULL;
// 	int fd = open("maps/map.yber",O_RDONLY);
// 	if (fd == -1)
// 		return 0;
// 	while(true)
// 	{
// 		char* l = 0;
// 		l = get_next_line(fd);

// 		if (l == NULL)
// 			break;
// 		map[i] = l;
// 		i++;
// 	}
// 	*a = i;
// 	return(map);
// }

// int	main()
// {
// 	int i = 0;
// 	int c = 0, r = 0;
// 	char **map = read_map(&i);
// 	point p = find_player(map);
// 	if(p.y == 0 && p.y == 0)
// 		puts("no player found");

// 	r = i;
// 	c = strlen(map[0]);

// 	if (map_valid(map, i) != 0)
// 		puts("maps valid check path");

// 	if (bfs (p,map, r, c))
// 		puts("path is valid");
// 	else 
// 		puts("no");
// }