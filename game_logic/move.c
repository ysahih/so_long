#include "../so_long.h"

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

void	move_player(t_data *info)
{
	info->map[info->p.y][info->p.x] = '0';
	info->map[info->new_pos.y][info->new_pos.x] = 'P';
	info->p.y = info->new_pos.y;
	info->p.x= info->new_pos.x;
	rendering(info);
}
