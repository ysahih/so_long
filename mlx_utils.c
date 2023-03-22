#include"so_long.h"

void	put_image_to_window(t_data *info, int row, int col)
{
	if (info->map[row][col] == '1')
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_wind , info->wall_img,  (col * 64), (row * 64));
	else if (info->map[row][col] == 'C')
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_wind , info->cll_img,  (col * 64), (row * 64));
	else if (info->map[row][col] == 'P')
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_wind , info->player_img,  (col * 64), (row * 64));
	else if (info->map[row][col] == 'E')
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_wind , info->exit_img,  (col * 64), (row * 64));
}

void	rendering(t_data *info)
{
	int	i;
	int j;

	i = -1;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			mlx_put_image_to_window(info->mlx_ptr, info->mlx_wind , info->floor_img, (j * 64), (i * 64));
			put_image_to_window(info, i, j);
		}
	}
}