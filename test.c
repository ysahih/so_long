#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    int **s = malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
        s[i] = malloc(5 * sizeof(int));


    s[4][3] = 100;
    puts("done");
}

void	collect_map_info(t_info *ptr)
{
	if (!check_map_validity(ptr->map))
	{
		printf("Error\nInvalid Map");
		ft_free(ptr->map);
		exit (0);
	}
	ptr->collectibles = count_collects(ptr->map);
	ptr->plr = find_player(ptr->map);
	ptr->weight = ft_strlen(ptr->map[0]);
	ptr->new_position.line = ptr->plr.line;
	ptr->new_position.colmun = ptr->plr.colmun;
	ptr->mlx_ptr = mlx_init();
	ptr->mlx_wndw = mlx_new_window(ptr->mlx_ptr, (ptr->weight * SIZE), \
									(ptr->height * SIZE), "so_long");
}