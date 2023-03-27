#include "../so_long.h"

size_t ft_strlen(char *s)
{
    size_t  i;

    i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*get_ret(char *s, char c)
{
	int		i;
	char	*ret;
	int		j;

	i = 0;
	j = -1;
	while (s[i])
		i++;
	if (c == '\n')
	{
		ret = malloc(i + 1);
		while (s[++j])
			ret[j] = s[j];
		ret[j] = 0;
		free(s);
		return ret;
	}
	else 
	{
		ret = malloc (i + 2);
		while (s[++j])
			ret[j] = s[j];
		ret[i++] = c;
		ret[i] = 0;
	}
	free(s);
	return (ret);
}

char	*join(char *s, char c)
{
	if (!s)
	{
		s = malloc(2);
		if (!s)
			return (0);
		if (c == '\n')
		{
			write(1, "Invalid Map\n", 12);
			free(s);
			exit (0);
		}
		s[0] = c;
		s[1] = 0x0;
		return (s);
	}
	return (get_ret(s, c));
}

char	*gnl(int fd)
{
	char		r;
	int			ret;
	char		*buff;
	static char	previous;

	ret = 1;
	buff = 0;
	while (1)
	{
		ret = read(fd, &r, 1);
		if (ret == -1)
			return 0;
		else if (ret == 0)
		{
			if (previous == '\n')
			{
				write(1, "Invalid Map\n", 12);
				exit(0);
			}
		break;
		}
		buff = join(buff, r);
		previous = r;
		if (r == '\n')
			break;
	}
	if (!buff || *buff == '\0')
	{
		free(buff);
		return 0;
	}
	return buff;
}
