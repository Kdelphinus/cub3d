
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game_info	*game_info;

	if (ac != 2)
		return (0);
	game_info = (t_game_info *)malloc(sizeof(t_game_info));
	parsing(game_info, av[1]);
	mlx_loop(game_info->mlx);
	return (0);
}
