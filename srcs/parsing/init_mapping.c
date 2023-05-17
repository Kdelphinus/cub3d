#include "../../includes/cub3d.h"

static void set_ray(t_game_info *info, t_dir dir, int x, int y)
{
	const float ray_dir_x[4] = {0, 0, 1, -1};
	const float ray_dir_y[4] = {-1, 1, 0, 0};
	const float ray_plane_x[4] = {0.66, -0.66, 0, 0};
	const float ray_plane_y[4] = {0, 0, 0.66, -0.66};

	if (dir == NO)
	{
		info->ray->pos[X] = x + 0.5;
		info->ray->pos[Y] = y + 0.5;
		info->ray->dir[X] = ray_dir_x[NO];
		info->ray->dir[Y] = ray_dir_y[NO];
		info->ray->plane[X] = ray_plane_x[NO];
		info->ray->plane[Y] = ray_plane_y[NO];
	}
	else if (dir == SO)
	{
		info->ray->pos[X] = x + 0.5;
		info->ray->pos[Y] = y + 0.5;
		info->ray->dir[X] = ray_dir_x[SO];
		info->ray->dir[Y] = ray_dir_y[SO];
		info->ray->plane[X] = ray_plane_x[SO];
		info->ray->plane[Y] = ray_plane_y[SO];
	}
	else if (dir == WE)
	{
		info->ray->pos[X] = x + 0.5;
		info->ray->pos[Y] = y + 0.5;
		info->ray->dir[X] = ray_dir_x[WE];
		info->ray->dir[Y] = ray_dir_y[WE];
		info->ray->plane[X] = ray_plane_x[WE];
		info->ray->plane[Y] = ray_plane_y[WE];
	}
	else if (dir == EA)
	{
		info->ray->pos[X] = x + 0.5;
		info->ray->pos[Y] = y + 0.5;
		info->ray->dir[X] = ray_dir_x[EA];
		info->ray->dir[Y] = ray_dir_y[EA];
		info->ray->plane[X] = ray_plane_x[EA];
		info->ray->plane[Y] = ray_plane_y[EA];
	}
}

void	add_mapping_node(t_mapping **list, t_mapping *new_node)
{
	t_mapping	*cur;

	cur = *list;
	if (cur == NULL)
	{
		*list = new_node;
		return ;
	}
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_node;
	new_node->next = NULL;
}

static int	check_obj(char *line, t_obj *obj, t_game_info *info)
{
	int	i;

	i = -1;
	while (line[++i] != '\n')
	{
		if (line[i] == '\0')
			break ;
		if (line[i] == 'N' && obj->n_cnt == 0)
        {
			set_ray(info, NO, i, obj->h);
            ++obj->n_cnt;
        }
		else if (line[i] == 'E' && obj->e_cnt == 0)
		{
			set_ray(info, EA, i, obj->h);
			++obj->e_cnt;
		}
		else if (line[i] == 'S' && obj->s_cnt == 0)
		{
			set_ray(info, SO, i, obj->h);
			++obj->s_cnt;
		}
		else if (line[i] == 'W' && obj->w_cnt == 0)
		{
			set_ray(info, WE, i, obj->h);
			++obj->w_cnt;
		}
		else if (line[i] == ' ' || line[i] == '0' || line[i] == '1')
			continue ;
		else
			print_err_exit();
	}
	++obj->h;
	return (i);
}

t_mapping	*new_mapping(char *line, t_obj *obj, t_game_info *info)
{
	t_mapping	*ret;

	ret = (t_mapping *)malloc(sizeof(t_mapping));
	ret->line = line;
	ret->line_len = check_obj(line, obj, info);
	if (obj->w < ret->line_len)
		obj->w = ret->line_len;
	ret->next = NULL;
	return (ret);
}
