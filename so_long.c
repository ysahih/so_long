/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:53:34 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/28 17:55:34 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_valid(t_data *info)
{
	info->row--;
	if (map_requesties(info->map) && components(info->map)
		&& rectangular(info->map, info->row)
		&& walls_serounded(info->map, info->row)
		&& bfs (info->p, info->map, info->row, info->col))
		return (true);
	return (false);
}

void	get_img(t_data *info)
{
	int	i;

	info->player_img = mlx_xpm_file_to_image(info->mlx_ptr,
			"./textures/images/koala11.xpm", &i, &i);
	info->wall_img = mlx_xpm_file_to_image(info->mlx_ptr,
			"./textures/images/wall_01.xpm", &i, &i);
	info->cll_img = mlx_xpm_file_to_image(info->mlx_ptr,
			"./textures/images/stra00.xpm", &i, &i);
	info->exit_img = mlx_xpm_file_to_image(info->mlx_ptr,
			"./textures/images/door_01.xpm", &i, &i);
	info->floor_img = mlx_xpm_file_to_image(info->mlx_ptr,
			"./textures/images/FLOOR.xpm", &i, &i);
	if (!info->player_img || !info->wall_img || !info->cll_img
		|| !info->exit_img || !info->floor_img)
	{
		write(1, "No Images Found\n", 16);
		exit(0);
	}
}

t_data	*collect_data(t_data *info, int row)
{
	info->col = ft_strlen(info->map[0]);
	info->p = find_player(info->map);
	if (info->p.y == row || info->p.x == info->col)
	{
		write(1, "Invalid Map\n", 12);
		exit(0);
	}
	info->row = row;
	if (!map_valid(info))
	{
		write(1, "Invalid Map\n", 12);
		exit(0);
	}
	info->collectibles = count_c(info->map);
	info->mlx_ptr = mlx_init();
	info->row++;
	info->mlx_wind = mlx_new_window(info->mlx_ptr,
			(info->col * SIZE), (info->row * SIZE), "so_long");
	get_img(info);
	return (info);
}

int	main(int ac, char **av)
{
	int		row;
	t_data	*info;

	if (ac != 2)
	{
		write(1, "Wrong Number Of Arguments\n", 26);
		exit (0);
	}
	check_map_name(av[1]);
	info = malloc(sizeof(t_data));
	if (!info)
		return (0);
	info->map = read_map(av[1], &row);
	info = collect_data(info, row);
	rendering(info);
	mlx_hook(info->mlx_wind, 2, 0, key_hook, info);
	mlx_hook(info->mlx_wind, 17, 0, cross_hook, info);
	mlx_loop(info->mlx_ptr);
}
