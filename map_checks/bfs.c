#include "../so_long.h"

void	free_visited(char **s, int row)
{
	int	i;

	i = 0;
	while (i < row)
		free(s[i++]);
	free(s);
}

void	push(int y, int x, t_queue **queue, char **visited)
{
	t_point	p;

	p.y = y;
	p.x = x;
	enqueue(queue, p);
	visited[y][x] = 1;
}

char	**get_visited(int row, int col)
{
	int	i;
	int	j;
	char	**visited;

	visited = (char **)malloc(sizeof(char *) * row);
	if (!visited)
		return (false);
	i = 0;
	while(i < row)
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

void	push_neighbours(t_point p, char **map, char **visited, t_queue **queue)
{
	if (p.y > 0 && map[p.y - 1][p.x] != '1' && visited[p.y - 1][p.x] == 0)
		push( p.y - 1, p.x, queue, visited);
	if (p.y < p.row && map[p.y + 1][p.x] != '1'  && visited[p.y + 1][p.x] == 0)
		push(p.y + 1, p.x, queue, visited);
	if (p.x > 0 && map[p.y][p.x - 1] != '1' && visited[p.y][p.x - 1] == 0)
		push(p.y, p.x - 1, queue, visited);
	if (p.x < p.col && map[p.y][p.x + 1] != '1'  && visited[p.y][p.x + 1] == 0)
		push(p.y, p.x + 1, queue, visited);

}

bool	no_path_found(char **visited, int row, t_queue *q)
{
	free_visited(visited, row);
	free(q);
	write(1, "Invalid Path Leads to : ", 25);
	return (false);

}
char **init_bfs_vars(t_point *p, int *count, t_queue **queue)
{
	char	**visited;

	*count  = 0;	
	*queue = NULL;
	enqueue(queue, *p);
	visited  = get_visited(p->row, p->col);
	visited[p->y][p->x] = 1;
	return (visited);
}

bool	path_found(t_queue *q, char **v, int row)
{
	free(q);
	free_visited(v, row);
	return (true);
}

void	pop(t_point	*p, t_queue **queue)
{
	p->y = (*queue)->y;
	p->x = (*queue)->x;
	dequeue(queue);
}

bool	bfs(t_point p, char **map , int row, int col)
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
			continue;
		push_neighbours(p, map, visited, &queue);
	}
	return (no_path_found(visited, row, queue));
}