/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:29:51 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/15 12:30:41 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int map_checker(char **s)
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
		return (0);
	else if (c == 0)
		return (0);
	return (1);
}
int map_valid(char **line, int a)
{	
	int i = 0;
	int j;
	while (i < a)
	{
		if (strlen(line[0]) != strlen(line[i + 1]))
		{
			return (0);
			exit (0);
		}
		i++;
	}
	i = 0;
	while (i < strlen(line[0]))
	{
		if ((line[0][i] != '1') || line[a][i] != '1')
		{
			return (0);
			exit (0);
		}
		i++;
	}
	i = 0;
	while  (i < a)
	{
		if (line[i][0] != '1')
		{
			return (0);
			exit (0);
		}			
		i++;
	}
	i = strlen(line[0]) - 1;
	if (!(i > a)){
		return (0);
		exit(0);
	}
	j = 0;
	while (j < a)
	{
		if (line[j][i] != '1')
		{
			return (0);
			exit (0);
		}
		j++;
	}
	if (!map_checker(line)){
		return (0);
		exit (0);
	}
	return (1);
}

int	main()
{
	int	fd;
	fd = open("maps/map.ber",O_RDONLY);
	int i = 0;
	char **line = NULL;
	line = malloc(200);
	if (!line)
		return (0);
	while((line[i] = get_next_line(fd)) != NULL)
		i++;
	i--;
	if (map_valid(line, i) == 0)
		printf("YOOO!!");
	else 
		puts("OK");
	free(line);
}