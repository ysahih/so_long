#include "../so_long.h"

size_t ft_strlen(char *s)
{
    size_t  i;

    i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*join(char *s, char c)
{
	char	*ret;
	int i;

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
		*s = c;
		s[1] = 0;
		return (s);
	}
	i= 0;
	while(s[i])
		i++;
	ret = malloc(i + 2);
	if(!ret)
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	if (c == '\n')
	{
		ret[i] = 0;
		free(s);
		return ret;
	}
	else { 
		ret[i++] = c;
		ret[i] = 0;
	}
	free(s);
	return ret;
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
