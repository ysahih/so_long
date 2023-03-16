/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:36:02 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/16 20:28:25 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (i[s])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	p = (char *)malloc (ft_strlen (s1) + ft_strlen (s2) + 1);
	if (!p)
		return (0);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc ((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*after_newline(char *line)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	i++;
	if (line[i] == '\0')
		return (NULL);
	buff = (char *) malloc (ft_strlen(line) - i + 1);
	while (line[i])
		buff[j++] = line[i++];
	buff[j] = '\0';
	return (buff);
}

int	check_newline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		return (1);
	return (0);
}

node	*ft_lstlast(node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(node **lst, node *new)
{
	node	*tmp;
	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

void enqueue(node **lst, point p)
{
	node *list = malloc(sizeof(node));
	if(!list)
		return ; 
	list->x = p.x;
	list->y = p.y;
	list->next  = 0x0;
	ft_lstadd_back(lst,list);
}
void dequeue(node *lst)
{
	node *tmp = lst;
	if (lst == NULL)
		return ;
	else 
		lst = lst->next;
	free(tmp);
}
bool queueisempty(node *lst)
{
	if (lst == NULL)
		return (true);
	return (false);
			
}

int count_items(char **s)
{
	int i = 0;
	int j;
	int a = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if  ((s[i][j] == 'P') || (s[i][j] == 'E') || (s[i][j] == 'C'))
				a++;
			j++;
		}
		i++;
	}
	// printf ( "%d " ,a);
	return (a);
}
bool found_elmnt(char c)
{
	if (c == 'C' || c == 'E' || c == 'P')
		return (true);
	return (false);
}

bool bfs(point p, char **map , int i)
 {
	int goal = count_items(map);
	int visited[5][5] = {0};
	int a;
	node *queue = NULL;
	enqueue(&queue, p);
	visited[p.x][p.y] = 1;
	while (!queueisempty(queue))
	{
		dequeue(queue);
		if (p.x > 0 && map[p.x - 1][p.y] != 1 && visited[p.x - 1][p.y] == 0)
		{
			point p1;
			p1.x = p.x - 1;
			p1.y = p.y;
			enqueue(&queue, p1);
			visited[p.x - 1][p.y] = 1;
			if (found_elmnt(map[p.x - 1][p.y]))
				a++;
		}
		if (p.x < i && map[p.x + 1][p.y] != 1 && visited[p.x + 1][p.y] == 0)
		{
			point p1;
			p1.x = p.x + 1;
			p1.y = p.y;
			enqueue(&queue, p1);
			visited[p.x + 1][p.y] = 1;
			if (found_elmnt(map[p.x + 1][p.y]))
				a++;
		}	
		if (p.y > 0 && map[p.x][p.y - 1] != 1 && visited[p.x][p.y - 1] == 0)
		{
			point p1;
			p1.x = p.x;
			p1.y = p.y - 1;
			enqueue(&queue, p1);
			visited[p.x][p.y - 1] = 1;
			if (found_elmnt(map[p.x][p.y - 1]))
				a++;
		}
		if (p.y < strlen(map[0]) && map[p.x][p.y + 1] != 1 && visited[p.x][p.y + 1] == 0)
		{
			point p1;
			p1.x = p.x;
			p1.y = p.y + 1;
			enqueue(&queue, p1);
			visited[p.x][p.y + 1] = 1;
			if (found_elmnt(map[p.x][p.y + 1]))
				a++;
		}
		if (goal == a)
			return (true);
	}
	return (false);
 }