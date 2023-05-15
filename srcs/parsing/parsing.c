#include "../../includes/cub3d.h"

static void	read_file(int fd, t_game_info *info)
{
	char	*line;

	while (TRUE)
	{
		line = get_next_line(fd);
		check_texture(line, info);
	}
}

void	parsing(t_game_info *info, char *file_name)
{
	int	fd;

	check_extension(file_name);
	info_init(info);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nThe file name or data is incorrect.\n");
		exit(fd);
	}
	read_file(fd, info);
}
