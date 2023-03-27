/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:13:42 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/27 17:13:59 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**get_visited(int row, int col)
{
	int		i;
	int		j;
	char	**visited;

	visited = (char **)malloc(sizeof(char *) * row);
	if (!visited)
		return (false);
	i = 0;
	while (i < row)
		visited[i++] = (char *)malloc(col * sizeof(char));
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
			visited[i][j++] = 0;
		i++;
	}
	return (visited);
}

char	**init_bfs_vars(t_point *p, int *count, t_queue **queue)
{
	char	**visited;

	*count = 0;
	*queue = NULL;
	enqueue(queue, *p);
	visited = get_visited(p->row, p->col);
	visited[p->y][p->x] = 1;
	return (visited);
}

void	free_visited(char **s, int row)
{
	int	i;

	i = 0;
	while (i < row)
		free(s[i++]);
	free(s);
}

bool	path_found(t_queue *q, char **v, int row)
{
	free(q);
	free_visited(v, row);
	return (true);
}

bool	no_path_found(char **visited, int row, t_queue *q)
{
	free_visited(visited, row);
	free(q);
	write(1, "Invalid Path Leads to : ", 25);
	return (false);
}
