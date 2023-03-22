
#include "so_long.h"

bool map_valid(t_data *info)
{	
	info->row--;
	bool flag = false;

	if (map_requesties(info->map) && components(info->map) && rectangular(info->map, info->row) && 
	walls_serounded(info->map, info->row) && bfs (info->p, info->map, info->row, info->col))
	{
		puts("map is valid");
		return true;
	}

	return (false);
}

t_data*	collect_data(t_data *info, int row)
{
	info->p = find_player(info->map);
	if(info->p.y == row){
		puts("no player found");
		exit(0);
	}
	info->row = row;
	info->col = ft_strlen(info->map[0]);
	if (!map_valid(info)){
		puts("maps not valid");
		exit(0);
	}
	return info;
}

 
int	main()
{
	int row;

	t_data	*info = malloc(sizeof(t_data));
	if (!info)
		exit(0);
	info->map = read_map(&row);
	
	info = collect_data(info, row);
}