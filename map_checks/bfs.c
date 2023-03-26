#include "../so_long.h"

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

bool	bfs(t_point p, char **map , int row, int col)
{
	int		goal;
	int		count;
	char	**visited;
	t_queue	*queue;

	row++;
	count = 0;
	goal = count_items(map);
	if (!goal)
		return false;
	visited = get_visited(row, col);
	queue = NULL;
	enqueue(&queue, p);
	visited[p.y][p.x] = 1;
	while (!queueisempty(queue))
	{
		p.y = queue->y;
		p.x = queue->x;
		dequeue(&queue);
		if (found_elmnt(map[p.y][p.x]))
			count++;
		if (goal == count)
			return (true);
		if (map[p.y][p.x] == 'E')
			continue;
		if (p.y > 0 && map[p.y - 1][p.x] != '1' && visited[p.y - 1][p.x] == 0)
			push( p.y - 1, p.x, &queue, visited);
		if (p.y < row && map[p.y + 1][p.x] != '1'  && visited[p.y + 1][p.x] == 0)
			push(p.y + 1, p.x, &queue, visited);
		if (p.x > 0 && map[p.y][p.x - 1] != '1' && visited[p.y][p.x - 1] == 0)
			push(p.y, p.x - 1, &queue, visited);
		if (p.x < col && map[p.y][p.x + 1] != '1'  && visited[p.y][p.x + 1] == 0)
			push(p.y, p.x + 1, &queue, visited);
	}
	free(queue);
	write(1, "Invalid Path Leads to : ", 25);
	return (false);
 }