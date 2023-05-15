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
	NO = 0,
	SO,
	WE,
	EA
}	t_dir;

typedef struct s_obj
{
	int	n_cnt;
	int	e_cnt;
	int	s_cnt;
	int	w_cnt;
	int	h;
}	t_obj;

typedef struct s_mapping
{
	char				*line;
	int					line_len;
	struct s_mapping	*next;
}	t_mapping;

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
	int			stop_flag;
	//int		p_dir;
	//struct	t_vector -> 실행에서 사용될 벡터 구조체
	t_map_data	*map_data;
}	t_game_info;

//initailize
void		parsing(t_game_info *info, char *map_file);
void		info_init(t_game_info *info, t_obj *obj);
void		texture_init(t_game_info *info);

//check
void		check_texture(char *line, t_game_info *info);
void		check_extension(char *file_name);
int			check_tmp_invalid(t_game_info *info, char **tmp);

//mapping allowcate
void		allocate_no(char **data, t_game_info *info);
void		allocate_so(char **data, t_game_info *info);
void		allocate_we(char **data, t_game_info *info);
void		allocate_ea(char **data, t_game_info *info);
void		allocate_flr(char **data, t_game_info *info);
void		allocate_ceil(char **data, t_game_info *info);

//struct linked list utils
t_texture	*new_texture(int i);
void		add_texture_node(t_texture *list, t_texture *new_node);
t_mapping	*new_mapping(char *line, t_obj *obj);
void		add_mapping_node(t_mapping *list, t_mapping *new_node);

//utils
void		print_game_info(const t_game_info *info);
void		print_err_exit(void);

#endif