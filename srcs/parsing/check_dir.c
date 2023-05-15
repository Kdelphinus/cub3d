#include "../../includes/cub3d.h"

void	allocate_no(char **data, t_game_info *info)
{
	t_texture	*cur;

	cur = info->map_data->textures;
	while (cur != NULL)
	{
		if (cur->dir == NO)
		{
			if (cur->cnt > 0)
				print_err_exit();// 이미 NO에 대한 값이 있는 경우 처리를 중단
			++cur->cnt;
			cur->img = mlx_xpm_file_to_image(info->mlx, data[1], \
			&cur->img_w, &cur->img_h);
			return ;
		}
		cur = cur->next;
	}
}

void	allocate_so(char **data, t_game_info *info)
{
	t_texture	*cur;

	cur = info->map_data->textures;
	while (cur != NULL)
	{
		if (cur->dir == SO)
		{
			if (cur->cnt > 0)
				print_err_exit();// 이미 NO에 대한 값이 있는 경우 처리를 중단
			++cur->cnt;
			cur->img = mlx_xpm_file_to_image(info->mlx, data[1], \
			&cur->img_w, &cur->img_h);
			return ;
		}
		cur = cur->next;
	}
}

void	allocate_we(char **data, t_game_info *info)
{
	t_texture	*cur;

	cur = info->map_data->textures;
	while (cur != NULL)
	{
		if (cur->dir == WE)
		{
			if (cur->cnt > 0)
				print_err_exit();// 이미 NO에 대한 값이 있는 경우 처리를 중단
			++cur->cnt;
			cur->img = mlx_xpm_file_to_image(info->mlx, data[1], \
			&cur->img_w, &cur->img_h);
			return ;
		}
		cur = cur->next;
	}
}

void	allocate_ea(char **data, t_game_info *info)
{
	t_texture	*cur;

	cur = info->map_data->textures;
	while (cur != NULL)
	{
		if (cur->dir == EA)
		{
			if (cur->cnt > 0)
				print_err_exit();// 이미 NO에 대한 값이 있는 경우 처리를 중단
			++cur->cnt;
			cur->img = mlx_xpm_file_to_image(info->mlx, data[1], \
			&cur->img_w, &cur->img_h);
			return ;
		}
		cur = cur->next;
	}
}
