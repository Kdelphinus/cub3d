#include "cub3d.h"

int key_press(int keycode, t_game_info *game_info)
{
	double	old_dir;
	double	old_planeX;

	if (keycode == KEY_ESC)
		exit(0); // TODO exit만 해도 되나
	else if (keycode == KEY_UP)
	{
		printf("key up\n");
		if (game_info->map_data->map[(int)(game_info->ray->pos[Y] + game_info->ray->dir[Y] * game_info->ray->move_speed)][(int)(game_info->ray->pos[X])] != '1')
			game_info->ray->pos[Y] += game_info->ray->dir[Y] * game_info->ray->move_speed;
		if (game_info->map_data->map[(int)(game_info->ray->pos[Y])][(int)(game_info->ray->pos[X] + game_info->ray->dir[X] * game_info->ray->move_speed)] != '1')
			game_info->ray->pos[X] += game_info->ray->dir[X] * game_info->ray->move_speed;
	}
	else if (keycode == KEY_DOWN)
	{
		printf("key down\n");
		if (game_info->map_data->map[(int)(game_info->ray->pos[Y] - game_info->ray->dir[Y] * game_info->ray->move_speed)][(int)(game_info->ray->pos[X])] != '1')
			game_info->ray->pos[Y] -= game_info->ray->dir[Y] * game_info->ray->move_speed;
		if (game_info->map_data->map[(int)(game_info->ray->pos[Y])][(int)(game_info->ray->pos[X] - game_info->ray->dir[X] * game_info->ray->move_speed)] != '1')
			game_info->ray->pos[X] -= game_info->ray->dir[X] * game_info->ray->move_speed;
	}
	else if (keycode == KEY_LEFT)
	{
		printf("key left\n");
		old_dir = game_info->ray->dir[X];
		game_info->ray->dir[X] = game_info->ray->dir[X] * cos(-game_info->ray->rot_speed) - game_info->ray->dir[Y] * sin(-game_info->ray->rot_speed);
		game_info->ray->dir[Y] = old_dir * sin(-game_info->ray->rot_speed) + game_info->ray->dir[Y] * cos(-game_info->ray->rot_speed);
		old_planeX = game_info->ray->plane[X];
		game_info->ray->plane[X] = game_info->ray->plane[X] * cos(-game_info->ray->rot_speed) - game_info->ray->plane[Y] * sin(-game_info->ray->rot_speed);
		game_info->ray->plane[Y] = old_planeX * sin(-game_info->ray->rot_speed) + game_info->ray->plane[Y] * cos(-game_info->ray->rot_speed);
	}
	else if (keycode == KEY_RIGHT)
	{
		printf("key right\n");
		old_dir = game_info->ray->dir[X];
		game_info->ray->dir[X] = game_info->ray->dir[X] * cos(game_info->ray->rot_speed) - game_info->ray->dir[Y] * sin(game_info->ray->rot_speed);
		game_info->ray->dir[Y] = old_dir * sin(game_info->ray->rot_speed) + game_info->ray->dir[Y] * cos(game_info->ray->rot_speed);
		old_planeX = game_info->ray->plane[X];
		game_info->ray->plane[X] = game_info->ray->plane[X] * cos(game_info->ray->rot_speed) - game_info->ray->plane[Y] * sin(game_info->ray->rot_speed);
		game_info->ray->plane[Y] = old_planeX * sin(game_info->ray->rot_speed) + game_info->ray->plane[Y] * cos(game_info->ray->rot_speed);
	}
	return (0);
}

int	main_loop(t_game_info *game_info)
{
	ray_cast(game_info->ray, game_info);
	mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->img->img_ptr, 0, 0);
	return (0);
}

int	ft_close()
{
	exit(0); // TODO 바로 exit해도 되나
}

void	l()
{
	system("leaks cub3d");
}

int	main(int ac, char **av)
{
	t_game_info	*game_info;

	atexit(l);
	if (ac != 2)
		return (0);
	game_info = (t_game_info *)malloc(sizeof(t_game_info));
	parsing(game_info, av[1]);
	ray_cast(game_info->ray, game_info);
	mlx_hook(game_info->win, X_EVENT_KEY_PRESS, 0, &key_press, game_info);
	mlx_hook(game_info->win, X_EVENT_KEY_EXIT, 0, &ft_close, game_info);
	mlx_loop_hook(game_info->mlx, &main_loop, game_info);
	mlx_loop(game_info->mlx);
	return (0);
}
