#include "../../includes/cub3d.h"

void	check_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name) - 1;
	if (len < 4 || file_name[len - 3] != '.' || file_name[len - 2] != 'c' \
		|| file_name[len - 1] != 'u' || file_name[len] != 'b' )
	{
		printf("Error\nThis is not a valid file name.\n");
		exit(FAILE);
	}
}

void	check_texture(char *line, t_game_info *info)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (tmp == NULL)
		print_err_exit();
	if (ft_strlen(tmp[0]) > 3 || tmp[1] == NULL || tmp[2] != NULL)
	{
		if (tmp[0][0] == '\n')
			return ;
		print_err_exit();
	}
	// tmp[1][ft_strlen(tmp[1]) - 1] = '\0';
	tmp[1] = ft_strtrim(tmp[1], "\n");
	if (!ft_strcmp("NO", tmp[0]) || !check_no(tmp[1], info))
		print_err_exit();
	else if (!ft_strcmp("SO", tmp[0]) || !check_so(tmp[1], info))
		print_err_exit();
	else if (!ft_strcmp("WE", tmp[0]) || !check_we(tmp[1], info))
		print_err_exit();
	else if (!ft_strcmp("EA", tmp[0]) || !check_ea(tmp[1], info))
		print_err_exit();
	else if (!ft_strcmp("F", tmp[0]))
	{
		printf("check F keyword in map file and pass\n");
		// if (info->check->f_count != 0)
		// {
		// 	print_err_exit();
		// }
		// rgb = ft_split(tmp[1], ',');
		// t = ft_atoi(rgb[0]);
		// info->map_data->f_rgb = t;
		// info->map_data->f_rgb << 4;
		// ++info->check->f_count;
	}
	else if (!ft_strcmp("C", tmp[0]))
	{
		printf("check C keyword in map file and pass\n");
		// if (info->check->c_count != 0)
		// {
		// 	print_err_exit();
		// }
		// ++info->check->c_count;
	}
	else
		print_err_exit();
}