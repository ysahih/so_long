
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
	info->mlx_ptr = mlx_init();
	info->row++;
	info->mlx_wind = mlx_new_window(info->mlx_ptr, (info->col * 64), (info->row * 64), "so_long");
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
	int i;
	info->player_img =  mlx_xpm_file_to_image(info->mlx_ptr, "./images/koala11.xpm", &i, &i);
	info->wall_img = mlx_xpm_file_to_image(info->mlx_ptr, "./images/wall_01.xpm", &i, &i);
	info->cll_img = mlx_xpm_file_to_image(info->mlx_ptr, "./images/stra00.xpm", &i, &i);
	info->exit_img = mlx_xpm_file_to_image(info->mlx_ptr, "./images/door_01.xpm", &i, &i);
	info->floor_img = mlx_xpm_file_to_image(info->mlx_ptr, "./images/floor.xpm", &i, &i);

	rendering(info);
	mlx_loop(info->mlx_ptr);
}