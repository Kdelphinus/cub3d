#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "../gnl/get_next_line.h"
# include "../lib/libft.h"
# include "../mlx/mlx.h"

# define FAILE 0
# define SUCCESS 1

# define FALSE 0
# define TRUE 1

typedef enum e_dir {
	NO,
	SO,
	WE,
	EA
}	t_dir;

typedef struct s_texture
{
	enum e_dir			dir;
	void				*img;
	int					img_w;
	int					img_h;
	int					cnt;
	struct s_texture	*next;
}	t_texture;

typedef struct s_map_data {
	char		**map;
	int			flr_color;
	int			ceil_color;
	int			flr_count;
	int			ceil_count;
	t_texture	*textures;
}	t_map_data;
//player 방향, 위치, 벡터
typedef struct s_game_info {
	void		*mlx;
	void		*win;
	t_map_data	*map_data;
}	t_game_info;

void		parsing(t_game_info *info, char *map_file);
void		print_err_exit(void);
void		add_texture_node(t_texture *list, t_texture *new_node);
void		check_texture(char *line, t_game_info *info);
void		info_init(t_game_info *info);
void		check_extension(char *file_name);
int			check_no(char *img_path, t_game_info *info);
int			check_so(char *img_path, t_game_info *info);
int			check_we(char *img_path, t_game_info *info);
int			check_ea(char *img_path, t_game_info *info);
t_texture	*new_texture(t_game_info *info, char *img_path);
void		print_game_info(const t_game_info *info);

#endif