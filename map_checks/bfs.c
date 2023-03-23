#include "../so_long.h"

void	push(int y, int x, t_queue **queue, char **visited)
{
	t_point	p;

	p.y = y;
	p.x = x;
	enqueue(queue, p);
	visited[y][x] = 1;
}

char **get_visited(int row, int col)
{
	
	char **visited = malloc(sizeof(char *) * row);
	if (!visited)
		return false;
	for (int i = 0; i < row; i++){
		visited[i] = (char *)malloc(col * sizeof(char));
	}
	for (int i = 0 ;i < row;++i) {
		for (int j = 0;j < col;++j) {
			visited[i][j] = 0;
		}
	}
	return (visited);
}

bool bfs(t_point p, char **map , int row, int col)
{
	int goal = count_items(map);
	int count = 0;
	char **visited = get_visited(row, col);
	t_queue *queue = NULL;
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
	puts("no path found");
	return (false);
 }