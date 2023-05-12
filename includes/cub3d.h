
#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../lib/libft.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

typedef enum e_direction {
	NO = 0,
	SO,
	WE,
	EA
}		t_dir;

typedef enum e_type {
	FAILE,
	SUCCESS
}	t_type;

typedef struct s_check
{
	int	no_count;
	int	so_count;
	int	we_count;
	int	ea_count;
	int	f_count;
	int	c_count;
}		t_check;

typedef struct s_map_data {
	char	**map;
	void	*no_image;
	void	*so_image;
	void	*we_image;
	void	*ea_image;
	int		f_rgb;
	int		c_rgb;
	int		image_w;
	int		image_h;
}				t_map_data;

typedef struct s_game_info
{
	void		*mlx;
	void		*win;
	int			f_color;
	int			c_color;
	t_map_data	*map_data;
	t_check		*check;
}		t_game_info;

void	parsing(t_game_info *info, char *map_file);
void	print_err_exit(void);

#endif