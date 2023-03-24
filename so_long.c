
#include "so_long.h"

bool map_valid(t_data *info)
{	
	info->row--;

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
	info->collectibles = count_c(info->map);
	info->mlx_ptr = mlx_init();
	info->row++;
	info->mlx_wind = mlx_new_window(info->mlx_ptr, (info->col * 64), (info->row * 64), "so_long");
	int i;
	info->player_img =  mlx_xpm_file_to_image(info->mlx_ptr, "./images/koala11.xpm", &i, &i);
	info->wall_img = mlx_xpm_file_to_image(info->mlx_ptr, "./images/wall_01.xpm", &i, &i);
	info->cll_img = mlx_xpm_file_to_image(info->mlx_ptr, "./images/stra00.xpm", &i, &i);
	info->exit_img = mlx_xpm_file_to_image(info->mlx_ptr, "./images/door_01.xpm", &i, &i);
	info->floor_img = mlx_xpm_file_to_image(info->mlx_ptr, "./images/FLOOR.xpm", &i, &i);
	return info;
}
int cross_hook(t_data *info)
{
	mlx_destroy_window(info->mlx_ptr, info->mlx_wind);
	exit(0);
}
int	main()
{
	int row;

	t_data	*info = malloc(sizeof(t_data));
	if (!info)
		exit(0);
	info->map = read_map(&row);

	// for (int i  = 0; info->map[i]; i++){
	// 	for (int j = 0; info->map[i][j]; j++){
	// 		printf("|%c|",info->map[i][j]);
	// 	}
	// 	puts("");
	// }
	info = collect_data(info, row);

	rendering(info);
	// key_hook(info);
	mlx_hook(info->mlx_wind, 2, 0, key_hook, info);
	mlx_hook(info->mlx_wind, 17, 0, cross_hook, info);
	
	mlx_loop(info->mlx_ptr);
}