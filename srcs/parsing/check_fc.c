#include "../../includes/cub3d.h"

int	check_tmp_invalid(t_game_info *info, char **tmp)
{
	if (tmp == NULL)
		print_err_exit();
	if (ft_strlen(tmp[0]) > 3 || tmp[1] == NULL || tmp[2] != NULL)
	{
		if (tmp[0][0] == '\n')
			return (0);
		info->stop_flag = TRUE;
		return (0);
	}
	return (1);
}

void	allocate_flr(char **data, t_game_info *info)
{
	char	**rgb;

	if (info->map_data->flr_count != 0)
		print_err_exit();
	++info->map_data->flr_count;
	rgb = ft_split(data[1], ',');
	info->map_data->flr_color = ft_atoi(rgb[0]) << 16
		| ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	//rgb free 해줘야 함
}

void	allocate_ceil(char **data, t_game_info *info)
{
	char	**rgb;

	if (info->map_data->ceil_count != 0)
		print_err_exit();
	++info->map_data->ceil_count;
	rgb = ft_split(data[1], ',');
	info->map_data->ceil_color = ft_atoi(rgb[0]) << 16
		| ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
}
