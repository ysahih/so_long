
#include "so_long.h"

bool map_valid(char **map, int a)
{	
	a--;
	if (map_requesties(map) && components(map) && rectangular(map, a), walls_serounded(map, a))
		return (true);
	return (false);
}

int	main()
{
	int i = 0;
	int c = 0, r = 0;

	t_data	info;
	info.map = read_map(&i);
	// printf("%p\n", info.map);
	info.p = find_player(info.map);
	
	// printf("%d, %d", info.p.y, info.p.x);

	if(info.p.y == 0 && info.p.y == 0)
		puts("no player found");

	info.row = i;
	info.col = strlen(info.map[0]);
	if (map_valid(info.map, i) != 0)
		puts("maps valid check path");

	if (bfs (info.p, info.map, info.row, info.col))
		puts("path is valid");
	// else 
	// 	puts("no");
}