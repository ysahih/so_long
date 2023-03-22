#include"../so_long.h"

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
