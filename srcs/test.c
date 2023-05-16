#include "cub3d.h"

char worldMap[mapWidth][mapHeight]=
{
	{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
	{'1','0','N','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','1','1','1','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
};

void ray_cast(t_game *game)
{
	t_ray	*ray = malloc(sizeof(t_ray));
	int		hit;
	int		color;

	if (!ray)
		exit(1);
	ray->pos[X] = 10;
	ray->pos[Y] = 2;
	ray->dir[X] = 1;
	ray->dir[Y] = 0;
	ray->plane[X] = 0;
	ray->plane[Y] = 0.66;
	ray->camera_x = 0;
	ray->ray_dir[X] = 0;
	ray->ray_dir[Y] = 0;
	ray->side_dist[X] = 0;
	ray->side_dist[Y] = 0;
	ray->delta_dist[X] = 0;
	ray->delta_dist[Y] = 0;
	ray->perp_wall_dist = 0;
	ray->step[X] = 0;
	ray->step[Y] = 0;
	ray->side = 0;
	//ray->world_map = worldMap;
	ray->line_h = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->time = 0;
	ray->old_tim = 0;
	ray->frame_time = 0;
	ray->move_speed = 0;
	ray->rot_speed = 0;

	while (1)
	{
		int x = 0;
		while (x < screenWidth)
		{
			ray->camera_x = 2 * x / (double)screenWidth - 1;
      		ray->ray_dir[X] = ray->dir[X] + ray->plane[X] * ray->camera_x;
      		ray->ray_dir[Y] = ray->dir[Y] + ray->plane[Y] * ray->camera_x;
			ray->map[X] = (int)ray->pos[X];
			ray->map[Y] = (int)ray->pos[Y];
			if (ray->ray_dir[X] == 0)
				ray->delta_dist[X] = 1e30;
			else
				ray->delta_dist[X] = fabs(1 / ray->ray_dir[X]);
			if (ray->ray_dir[Y] == 0)
				ray->delta_dist[Y] = 1e30;
			else
				ray->delta_dist[Y] = fabs(1 / ray->ray_dir[Y]);
		
			hit = 0;
			if (ray->ray_dir[X] < 0)
			{
				ray->step[X] = -1;
				ray->side_dist[X] = (ray->pos[X] - ray->map[X]) * ray->delta_dist[X];
			}
			else
			{
				ray->step[X] = 1;
				ray->side_dist[X] = (ray->map[X] + 1.0 - ray->pos[X]) * ray->delta_dist[X];
			}
			if (ray->ray_dir[Y] < 0)
			{
				ray->step[Y] = -1;
				ray->side_dist[Y] = (ray->pos[Y] - ray->map[Y]) * ray->delta_dist[Y];
			}
			else
			{
				ray->step[Y] = 1;
				ray->side_dist[Y] = (ray->map[Y] + 1.0 - ray->pos[Y]) * ray->delta_dist[Y];
			}
			while (hit == 0)
			{
				if (ray->side_dist[X] <= ray->side_dist[Y])
				{
					ray->side_dist[X] += ray->delta_dist[X];
					ray->map[X] += ray->step[X];
					ray->side = 0;
				}
				else
				{
					ray->side_dist[Y] += ray->delta_dist[Y];
					ray->map[Y] += ray->step[Y];
					ray->side = 1;
				}
				if (worldMap[ray->map[X]][ray->map[Y]] == '1')
					hit = 1;
			}
			if (ray->side == 0)
				ray->perp_wall_dist = (ray->map[X] - ray->pos[X] + (1 - ray->step[X]) / 2) / ray->ray_dir[X];
			else
                ray->perp_wall_dist = (ray->map[Y] - ray->pos[Y] + (1 - ray->step[Y]) / 2) / ray->ray_dir[Y];

			ray->line_h = (int)(screenHeight / ray->perp_wall_dist);
			ray->draw_start = -ray->line_h / 2 + screenHeight / 2;
			if (ray->draw_start < 0)
				ray->draw_start = 0;
			ray->draw_end = ray->line_h / 2 + screenHeight / 2;
			if (ray->draw_end >= screenHeight)
				ray->draw_end = screenHeight - 1;
			if (worldMap[ray->map[X]][ray->map[Y]] == '1')
				color = 0xffffff;
			else
				color = 0x000000;
			if (ray->side == 1)
				color = color / 2;
			for (int j = ray->draw_start; j <= ray->draw_end; j++)
				mlx_pixel_put(game->mlx, game->win, x, j, color);
			++x;
		}
		break;
	}
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game) * 1);
	if (ac != 2)
		return (0);
	game->map.name = av[1];
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(1);
	game->win = mlx_new_window(game->mlx, screenWidth, screenHeight, "./cub3d");
	if (!game->win)
		exit(1);
	ray_cast(game);
	mlx_loop(game->mlx);
	return (0);
}