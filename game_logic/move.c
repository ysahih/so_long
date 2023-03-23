#include "../so_long.h"

bool    possible_tomove(t_data *info)
{
    if (info->map[info->new_pos.y][info->new_pos.x] == '1')
        return (false);
    else if (info->map[info->new_pos.y][info->new_pos.x] == 'C')
    {
        info->collectibles--;
        return (true);
    }
    else if (info->map[info->new_pos.y][info->new_pos.x] == 'E')
    {
        if (!info->collectibles)
            exit(0);
        return false;
    }
    return (true);
}

bool	move_up(t_data *info)
{
	info->new_pos.y--;
    if (possible_tomove(info))
        return (true);
	return (false);
}

bool	move_down(t_data *info)
{
	info->new_pos.y++;
    if (possible_tomove(info))
        return (true);
	return (false);
}

bool	move_right(t_data *info)
{
	info->new_pos.x++;
    if (possible_tomove(info))
        return (true);
	return (false);
}

bool	move_left(t_data *info)
{
	info->new_pos.x--;
    if (possible_tomove(info))
        return (true);
	return (false);
}
void move_player(t_data *info)
{
    info->map[info->p.y][info->p.x] = '0';
	info->map[info->new_pos.y][info->new_pos.x] = 'P';
	info->p.y = info->new_pos.y;
	info->p.x= info->new_pos.x;
	rendering(info);
}

int	key_hook(int keycode, t_data *info)
{   
    info->new_pos.y = info->p.y;
    info->new_pos.x = info->p.x;



	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx_ptr, info->mlx_wind);
		// free(info->map);
		exit(0);
	}
    bool flag = true;
	if (keycode == 13)
        flag *= move_up(info);
	else if (keycode == 1)
        flag *= move_down(info);
	else if (keycode == 0)
       flag *= move_left(info);
	else if (keycode == 2)
        flag *= move_right(info);
    
    if (!flag)
        return 0;
    move_player(info);
    return 0;
}