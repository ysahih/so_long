#include "../so_long.h"

void ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}	
}

bool	possible_tomove(t_data *info)
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
		{
			write(1, "WINNER WINNER CHICKEN DINNER!\n", 30);
			ft_free(info->map);
			free(info);
			exit(0);
		}
		return (false);
	}
	return (true);
}

int	key_hook(int keycode, t_data *info)
{
	bool	flag;

	info->new_pos.y = info->p.y;
	info->new_pos.x = info->p.x;
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx_ptr, info->mlx_wind);
		ft_free(info->map);
		free(info);
		exit(0);
	}
	flag = true;
	if (keycode == 13)
		flag *= move_up(info);
	else if (keycode == 1)
		flag *= move_down(info);
	else if (keycode == 0)
		flag *= move_left(info);
	else if (keycode == 2)
		flag *= move_right(info);
	if ((keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2) && flag)
		move_player(info);
	return (0);
}