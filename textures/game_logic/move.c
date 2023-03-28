/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:03:51 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/27 18:11:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
	static int	i = 0;

	info->map[info->p.y][info->p.x] = '0';
	info->map[info->new_pos.y][info->new_pos.x] = 'P';
	info->p.y = info->new_pos.y;
	info->p.x = info->new_pos.x;
	i++;
	write(1, "number of movement : ", 21);
	ft_putnbr(i);
	write(1, "\n", 1);
	rendering(info);
}
