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

	tmp = ft_split(line, ' ');
	if (!check_tmp_invalid(info, tmp))
		return ;
	tmp[1][ft_strlen(tmp[1]) - 1] = '\0';
	if (!ft_strcmp(tmp[0], "NO"))
		allocate_no(tmp, info);
	else if (!ft_strcmp(tmp[0], "SO"))
		allocate_so(tmp, info);
	else if (!ft_strcmp(tmp[0], "WE"))
		allocate_we(tmp, info);
	else if (!ft_strcmp(tmp[0], "EA"))
		allocate_ea(tmp, info);
	else if (!ft_strcmp(tmp[0], "F"))
		allocate_flr(tmp, info);
	else if (!ft_strcmp(tmp[0], "C"))
		allocate_ceil(tmp, info);
	else
		info->stop_flag = TRUE;
}
