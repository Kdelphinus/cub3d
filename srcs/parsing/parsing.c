#include "../../includes/cub3d.h"

static void	read_file(int fd, t_game_info *info, t_obj *obj)
{
	t_mapping	*m_head;
	char		*line;

	m_head = malloc(sizeof(t_mapping));
	m_head->next = NULL;
	while (info->stop_flag != TRUE)
	{
		line = get_next_line(fd);
		check_texture(line, info);
	}
	if (info->map_data->ceil_color == info->map_data->flr_color)
	{
		print_err_exit();
	}
	while (line != NULL)
	{
		add_mapping_node(m_head, new_mapping(line, obj));
		line = get_next_line(fd);
	}
}

void	parsing(t_game_info *info, char *file_name)
{
	int		fd;
	t_obj	*obj;

	check_extension(file_name);
	obj = (t_obj *)malloc(sizeof(t_obj));
	info_init(info, obj);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nThe file name or data is incorrect.\n");
		exit(fd);
	}
	read_file(fd, info, obj);
}
