/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:10:51 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/27 17:10:52 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	push(int y, int x, t_queue **queue, char **visited)
{
	t_point	p;

	p.y = y;
	p.x = x;
	enqueue(queue, p);
	visited[y][x] = 1;
}

void	push_neighbours(t_point p, char **map, char **visited, t_queue **queue)
{
	if (p.y > 0 && map[p.y - 1][p.x] != '1' && visited[p.y - 1][p.x] == 0)
		push(p.y - 1, p.x, queue, visited);
	if (p.y < p.row && map[p.y + 1][p.x] != '1' && visited[p.y + 1][p.x] == 0)
		push(p.y + 1, p.x, queue, visited);
	if (p.x > 0 && map[p.y][p.x - 1] != '1' && visited[p.y][p.x - 1] == 0)
		push(p.y, p.x - 1, queue, visited);
	if (p.x < p.col && map[p.y][p.x + 1] != '1' && visited[p.y][p.x + 1] == 0)
		push(p.y, p.x + 1, queue, visited);
}

void	pop(t_point	*p, t_queue **queue)
{
	p->y = (*queue)->y;
	p->x = (*queue)->x;
	dequeue(queue);
}

bool	bfs(t_point p, char **map, int row, int col)
{
	int		goal;
	int		count;
	char	**visited;
	t_queue	*queue;

	p.row = ++row;
	p.col = col;
	visited = init_bfs_vars(&p, &count, &queue);
	goal = count_items(map);
	while (!queueisempty(queue))
	{
		pop(&p, &queue);
		if (found_elmnt(map[p.y][p.x]))
			count++;
		if (goal == count)
			return (path_found(queue, visited, row));
		if (map[p.y][p.x] == 'E')
			continue ;
		push_neighbours(p, map, visited, &queue);
	}
	return (no_path_found(visited, row, queue));
}
