#include"get_next_line.h"

char	*get_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] != '\n')
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i] != '\n')
	{
		str[i] = line[i];
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
bool map_requesties(char **s)
{
	int i = 0;
	int j;
	int p = 0, e = 0, c = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'P')
				p++;
			if (s[i][j] == 'E')
				e++;
			if (s[i][j] == 'C')
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
bool map_valid(char **line, int a)
{	
	int i, j = 0;
	i = 0;
	while (i < a )
	{
		if (strlen(line[0]) != strlen(line[i + 1]))
			return (false);
		i++;
	}
	i = 0;
	while (i < strlen(line[0]))
	{
		if ((line[0][i] != '1') || line[a][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while  (i <= a)
	{
		if (line[i][0] != '1')
			return (false);
		i++;
	}
	i = 0;
    j = strlen(line[0]) - 1;
	while (i <= a)
	{
		if (line[i][j] != '1')
			return (false);
		i++;
	}
	if (j <= a)
		return (false);
	if (!map_requesties(line))
		return (false);
	return (true);
}

int calculate_size(char *file)
{
	int	i;
	int fd = open("maps/map.ber",O_RDONLY);

	i = 0;
	while((get_next_line(fd)) != NULL)
		i++;
	return (close(fd), i);
}

point find_player(char **map)
{
	int flag;
	point p;
	p.x = 0, p.y = 0;
	while (map[p.y])
	{
		p.x = 0;
		while(map[p.y][p.x])
		{
			if (map[p.y][p.x] == 'P'){
				flag = true;
				break;
			}
			p.x++;
		}
		if (flag)
			break;
		p.y++;
	}
	return p;
}

char** read_map(int *a)
{
	int i = 0;
	int fd = open("maps/map.ber",O_RDONLY);
	char **line = NULL;
	line = malloc(calculate_size("maps/map.ber") * sizeof(char *));
	if (!line)
		return 0;
	while((line[i] = get_next_line(fd)) != NULL)
		i++;
	*a = i - 1;
	return(line);
}

int	main()
{
	int i = 0;
	int c, r;
	bool flag = false;
	int g, h;
	// fd = open("maps/map.ber",O_RDONLY);
	// int i = 0;
	char **line = read_map(&i);

    // for (int i = 0; line[i]; i++)
    //     printf("%s", line[i]);
	// printf("%d", i);

	r = i + 1;
	c = strlen(line[0]);
	
	point p = find_player(line);
	// p.x = b;
	// p.y = a;
	if (bfs (p,line, r))
		puts("OK");	

	// printf ( "%d " ,count_items(line));
	
	// count_items(line);

	
	// if (map_valid(line, i) == 0)
	// 	printf("YOOO!!");
	// else 
	// 	puts("OK");
	// free(line);
}