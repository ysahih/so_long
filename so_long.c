#include "so_long.h"

bool map_valid(t_data *info)
{	
	info->row--;
	if (map_requesties(info->map) && components(info->map) && rectangular(info->map, info->row) && 
	walls_serounded(info->map, info->row) && bfs (info->p, info->map, info->row, info->col))
		return true;
	return (false);
}
void get_img(t_data *info)
{
	int i;
	info->player_img =  mlx_xpm_file_to_image(info->mlx_ptr, "./images/koala11.xpm", &i, &i);
	info->wall_img = mlx_xpm_file_to_image(info->mlx_ptr, "./images/wall_01.xpm", &i, &i);
	info->cll_img = mlx_xpm_file_to_image(info->mlx_ptr, "./images/stra00.xpm", &i, &i);
	info->exit_img = mlx_xpm_file_to_image(info->mlx_ptr, "./images/door_01.xpm", &i, &i);
	info->floor_img = mlx_xpm_file_to_image(info->mlx_ptr, "./images/FLOOR.xpm", &i, &i);
	if (!info->player_img || !info->wall_img || !info->cll_img || !info->exit_img || !info->floor_img)
	{
		write(1, "No Images Found\n", 16);
		free(info->map);
		exit(0);
	}
}
t_data*	collect_data(t_data *info, int row)
{
	info->col = ft_strlen(info->map[0]);
	info->p = find_player(info->map);
	if(info->p.y == row || info->p.x == info->col)
	{
		write(1, "Invalid Map\n", 12);
		free(info->map);
		exit(0);
	}
	info->row = row;
	if (!map_valid(info))
	{
		write(1, "Invalid Map\n", 12);
		free(info->map);
		exit(0);
	}
	info->collectibles = count_c(info->map);
	info->mlx_ptr = mlx_init();
	info->row++;
	info->mlx_wind = mlx_new_window(info->mlx_ptr, (info->col * SIZE), (info->row * SIZE), "so_long");
	get_img(info);
	return info;
}
int	cross_hook(t_data *info)
{
	if (info)
		exit(0);
	return (0);
}
int	main()
{
	int	row;

	t_data	*info = malloc(sizeof(t_data));
	if (!info)
		exit(0);
	info->map = read_map(&row);
	info = collect_data(info, row);
	rendering(info);
	mlx_hook(info->mlx_wind, 2, 0, key_hook, info);
	mlx_hook(info->mlx_wind, 17, 0, cross_hook, info);
	mlx_loop(info->mlx_ptr);
}