#include "../../includes/cub3d.h"

static void	read_file(int fd, t_game_info *info, t_obj *obj)
{
	t_mapping	*m_head;
	t_mapping	*tmp;
	char		*line;
	int			i;

	i = 0;
	m_head = NULL;
	while (info->stop_flag != TRUE)
	{
		line = get_next_line(fd);
		check_texture(line, info);
	}
	while (line != NULL)
	{
		add_mapping_node(&m_head, new_mapping(line, obj, info));
		line = get_next_line(fd);
	}
	tmp = m_head;
	info->map_data->map = malloc(sizeof(char *) * obj->h);
	while (i < obj->h)
	{
		info->map_data->map[i] = malloc(sizeof(char) * obj->w);
		ft_strlcpy(info->map_data->map[i], tmp->line, tmp->line_len + 1);
		while (obj->w > tmp->line_len)
		{
			info->map_data->map[i][tmp->line_len] = ' ';
			++tmp->line_len;
		}
		tmp = tmp->next;
		++i;
	}
	while (m_head != NULL)
	{
		free(m_head->line);
		tmp = m_head->next;
		free(m_head);
		m_head = tmp;
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
	free(obj);
}
