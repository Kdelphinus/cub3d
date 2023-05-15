#include "../../includes/cub3d.h"

void	check_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name) - 1;
	if (len < 4 || file_name[len - 3] != '.' || file_name[len - 2] != 'c' \
		|| file_name[len - 1] != 'u' || file_name[len] != 'b' )
	{
		printf("Error\nThis is not a valid file name.\n");
		print_err_exit();
	}
}

void	check_texture(char *line, t_game_info *info)
{
	char	**tmp;
	char	**rgb;

	tmp = ft_split(line, ' ');
	if (tmp == NULL)
		print_err_exit();
	if (ft_strlen(tmp[0]) > 3 || tmp[1] == NULL || tmp[2] != NULL)
	{
		if (tmp[0][0] == '\n')
			return ;
		info->stop_flag = TRUE;
		return ;
	}
	tmp[1][ft_strlen(tmp[1]) - 1] = '\0';
	if (!ft_strcmp(tmp[0], "NO"))
		allocate_no(tmp, info);
	else if (!ft_strcmp((tmp[0]), "SO"))
		allocate_so(tmp, info);
	else if (!ft_strcmp((tmp[0]), "WE"))
		allocate_we(tmp, info);
	else if (!ft_strcmp((tmp[0]), "EA"))
		allocate_ea(tmp, info);
	else if (!ft_strcmp("F", tmp[0]))
	{
		if (info->map_data->flr_count != 0)
			print_err_exit();
		++info->map_data->flr_count;
		rgb = ft_split(tmp[1], ',');
		info->map_data->flr_color = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
		//rgb free 해줘야 함
	}
	else if (!ft_strcmp("C", tmp[0]))
	{
		if (info->map_data->ceil_count != 0)
			print_err_exit();
		++info->map_data->ceil_count;
		rgb = ft_split(tmp[1], ',');
		info->map_data->ceil_color = ft_atoi(rgb[0]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]);
	}
	else
	{
		info->stop_flag = TRUE;
	}
}
