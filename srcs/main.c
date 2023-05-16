#include "cub3d.h"

int key_press(int keycode, t_ray *ray, t_map_data *map)
{
	double	old_dir;
	double	old_planeX;

	if (keycode == KEY_UP)
	{
		printf("key up\n");
		if (map->map[(int)(ray->pos[Y] + ray->dir[Y] * ray->move_speed)][(int)(ray->pos[X])] == '0')
			ray->pos[Y] += ray->dir[Y] * ray->move_speed;
		if (map->map[(int)(ray->pos[Y])][(int)(ray->pos[X] + ray->dir[X] * ray->move_speed)] == '0')
			ray->pos[X] += ray->dir[X] * ray->move_speed;
	}
	if (keycode == KEY_DOWN)
	{
		printf("key down\n");
		if (map->map[(int)(ray->pos[Y] - ray->dir[Y] * ray->move_speed)][(int)(ray->pos[X])] == '0')
			ray->pos[Y] -= ray->dir[Y] * ray->move_speed;
		if (map->map[(int)(ray->pos[Y])][(int)(ray->pos[X] - ray->dir[X] * ray->move_speed)] == '0')
			ray->pos[X] -= ray->dir[X] * ray->move_speed;
	}
	if (keycode == KEY_LEFT)
	{
		printf("key left\n");
		old_dir = ray->dir[X];
		ray->dir[X] = ray->dir[X] * cos(-ray->rot_speed) - ray->dir[Y] * sin(-ray->rot_speed);
		ray->dir[Y] = old_dir * sin(-ray->rot_speed) + ray->dir[Y] * cos(-ray->rot_speed);
		old_planeX = ray->plane[X];
		ray->plane[X] = ray->plane[X] * cos(-ray->rot_speed) - ray->plane[Y] * sin(-ray->rot_speed);
		ray->plane[Y] = old_planeX * sin(-ray->rot_speed) + ray->plane[Y] * cos(-ray->rot_speed);
	}
	if (keycode == KEY_RIGHT)
	{
		printf("key right\n");
		old_dir = ray->dir[X];
		ray->dir[X] = ray->dir[X] * cos(ray->rot_speed) - ray->dir[Y] * sin(ray->rot_speed);
		ray->dir[Y] = old_dir * sin(ray->rot_speed) + ray->dir[Y] * cos(ray->rot_speed);
		old_planeX = ray->plane[X];
		ray->plane[X] = ray->plane[X] * cos(ray->rot_speed) - ray->plane[Y] * sin(ray->rot_speed);
		ray->plane[Y] = old_planeX * sin(ray->rot_speed) + ray->plane[Y] * cos(ray->rot_speed);
	}
	return (0);
}

int	main_loop(t_game_info *game_info)
{
	ray_cast(game_info->ray, game_info);
	mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->img->img_ptr, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game_info	*game_info;

	if (ac != 2)
		return (0);
	game_info = (t_game_info *)malloc(sizeof(t_game_info));
	parsing(game_info, av[1]);
//	print_game_info(game_info);
//	mlx_loop(game_info->mlx);
	mlx_hook(game_info->win, X_EVENT_KEY_PRESS, 0, &key_press, game_info->ray);
    ray_cast(game_info->ray, game_info);
	mlx_loop_hook(game_info->mlx, &main_loop, game_info);
    mlx_loop(game_info->mlx);
	system("leaks cub3d");
	return (0);
}
