#include "../../includes/cub3d.h"

void	add_texture_node(t_texture *list, t_texture *new_node)
{
	t_texture	*cur;

	cur = list;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_node;
	new_node->next = NULL;
}

t_texture	*new_texture(t_game_info *info, char *img_path)
{
	t_texture	*ret;

	ret = (t_texture *)malloc(sizeof(t_texture));
	ret->dir = 0;
	ret->img_w = 64;
	ret->img_h = 64;
	ret->img = mlx_xpm_file_to_image(info->mlx, \
			img_path, &ret->img_w, &ret->img_h);
	ret->cnt = 0;
	ret->next = NULL;
	return (ret);
}

void	info_init(t_game_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 1980, 1080, "./cub3d");
	info->map_data->map = 0;
	info->map_data->flr_color = 0;
	info->map_data->flr_count = 0;
	info->map_data->ceil_color = 0;
	info->map_data->ceil_count = 0;
	info->map_data->textures = 0;
}