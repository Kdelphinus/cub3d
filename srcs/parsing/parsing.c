#include "../../includes/cub3d.h"

static void	check_map_invalid(char **map, t_obj *obj)
{
	int	x;
	int	y;

	y = 0;
	if (obj->h < 3)
		print_err_exit(WRONGDATA);
	if (obj->e_cnt + obj->n_cnt + obj->s_cnt + obj->w_cnt != 1)
		print_err_exit(WRONGDATA);
	while (y < obj->h)
	{
		x = 0;
		while (x < obj->w)
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'E'
			|| map[y][x] == 'W' || map[y][x] == 'S')
			{
				if (y == 0 || y == obj->h - 1 || x == 0 || x == obj->w - 1)
					print_err_exit(NOWALL);
				if (map[y - 1][x] == ' ' || map[y + 1][x] == ' '
				|| map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
					print_err_exit(NOWALL);
			}
			if (map[y][x] == ' ')
			{
				if (y == 0 || y == obj->h - 1 || x == 0 || x == obj->w - 1)
				{
					++x;
					continue ;
				}
				if ((map[y - 1][x] != ' ' && map[y - 1][x] != '1')
					|| (map[y + 1][x] != ' ' && map[y + 1][x] != '1')
					|| (map[y][x - 1] != ' ' && map[y][x - 1] != '1')
					|| (map[y][x + 1] != ' ' && map[y][x + 1] != '1'))
					print_err_exit(WRONGDATA);
			}
			++x;
		}
		++y;
	}
}

static void	check_texture_data(t_game_info *info)
{
	int	i;
	int	j;

	i = 0;
	if (info->map_data->ceil_count != 1 || info->map_data->flr_count != 1)
		print_err_exit(WRONGDATA);
	while (i < 4)
	{
		if (info->map_data->textures[i].path == NULL)
			print_err_exit(WRONGDATA);
		++i;
	}
	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 4)
		{
			if (ft_strcmp(info->map_data->textures[i].path,
					info->map_data->textures[j].path) == 0)
				print_err_exit(WRONGDATA);
			++j;
		}
		++i;
	}
}

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
		if (line == NULL)
			print_err_exit(WRONGDATA);
		check_texture(line, info);
	}
	check_texture_data(info);
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
	check_map_invalid(info->map_data->map, obj);
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
		print_err_exit(NOFILE);
	read_file(fd, info, obj);
	free(obj);
}
