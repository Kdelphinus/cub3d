
#include "../../includes/cub3d.h"

void	check_extension(char *map_file)
{
	int	len;

	len = ft_strlen(map_file) - 1;
	if (len < 4)
	{
		printf("Error\nThis is not a valid file name.\n");
		exit(FAILE);
	}
	else if (map_file[len - 3] != '.' || map_file[len - 2] != 'c' \
		|| map_file[len - 1] != 'u' || map_file[len] != 'b' )
	{
		printf("Error\nThis is not a valid file name.\n");
		exit(FAILE);
	}
}

void	check_texture(char *line, t_game_info *info)
{
	char	**tmp;
	char	**rgb;
	int		t;

	tmp = ft_split(line, ' ');
	if (tmp == NULL)
	{
		print_err_exit();
	}
	if (ft_strlen(tmp[0]) > 3 || tmp[1] == NULL || tmp[2] != NULL)
	{
		if (tmp[0][0] == '\n')
			return ;
		print_err_exit();
	}
	tmp[1][ft_strlen(tmp[1]) - 1] = '\0';
	if (!ft_strcmp("NO", tmp[0]))
	{
		if (info->check->no_count != 0)
		{
			print_err_exit();
		}
		if (tmp[1] != NULL)
		{
			info->map_data->no_image = mlx_xpm_file_to_image(info->mlx, \
				tmp[1], &info->map_data->image_w, &info->map_data->image_h);
		}
		if (info->map_data->no_image == NULL)
		{
			
			print_err_exit();
		}
		++info->check->no_count;
	}
	else if (!ft_strcmp("SO", tmp[0]))
	{
		if (info->check->so_count != 0)
		{
				
			print_err_exit();
		}
		info->map_data->so_image = mlx_xpm_file_to_image(info->mlx, \
			tmp[1], &info->map_data->image_w, &info->map_data->image_h);
		if (info->map_data->so_image == NULL)
		{
		
			print_err_exit();
		}
		++info->check->so_count;
	}
	else if (!ft_strcmp("WE", tmp[0]))
	{
		if (info->check->we_count != 0)
		{
				
			print_err_exit();
		}
		info->map_data->we_image = mlx_xpm_file_to_image(info->mlx, \
			tmp[1], &info->map_data->image_w, &info->map_data->image_h);
		if (info->map_data->we_image == NULL)
		{
		
			print_err_exit();
		}
		++info->check->we_count;
	}
	else if (!ft_strcmp("EA", tmp[0]))
	{
		if (info->check->ea_count != 0)
		{
			
			print_err_exit();
		}
		info->map_data->ea_image = mlx_xpm_file_to_image(info->mlx, \
			tmp[1], &info->map_data->image_w, &info->map_data->image_h);
		if (info->map_data->no_image == NULL)
		{
		
			print_err_exit();
		}
		++info->check->ea_count;
	}
	else if (!ft_strcmp("F", tmp[0]))
	{
		if (info->check->f_count != 0)
		{
			print_err_exit();
		}
		rgb = ft_split(tmp[1], ',');
		t = ft_atoi(rgb[0]);
		info->map_data->f_rgb = t;
		info->map_data->f_rgb << 4;
		++info->check->f_count;
	}
	else if (!ft_strcmp("C", tmp[0]))
	{
		if (info->check->c_count != 0)
		{
			print_err_exit();
		}
		++info->check->c_count;
	}
	else
	{
		print_err_exit();
	}
}

static void	read_file(int fd, t_game_info *info)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		check_texture(line, info);
	}
}

void	info_init(t_game_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 1980, 1080, "./cub3d");
	info->map_data = malloc(sizeof(info->map_data));
	info->check = malloc(sizeof(info->check));
	info->map_data->image_w = 64;
	info->map_data->image_h = 64;
	info->check->we_count = 0;
	info->check->ea_count = 0;
	info->check->so_count = 0;
	info->check->no_count = 0;
	info->check->f_count = 0;
	info->check->c_count = 0;
}

void	parsing(t_game_info *info, char *map_file)
{
	int	fd;

	check_extension(map_file);
	info_init(info);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nThe file name or data is incorrect.\n");
		exit(fd);
	}
	read_file(fd, info);
}
