#include "../../includes/cub3d.h"

void	info_init(t_game_info *info, t_obj *obj)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 1980, 1080, "./cub3d");
	info->stop_flag = FALSE;
    info->map_data = malloc(sizeof(info->map_data));
	info->map_data->map = 0;
	info->map_data->flr_color = 0;
	info->map_data->flr_count = 0;
	info->map_data->ceil_color = 0;
	info->map_data->ceil_count = 0;
	info->map_data->textures = 0;
    texture_init(info);
	obj->n_cnt = 0;
	obj->e_cnt = 0;
	obj->s_cnt = 0;
	obj->w_cnt = 0;
	obj->h = 0;
}