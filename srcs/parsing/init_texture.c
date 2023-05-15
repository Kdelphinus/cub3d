#include "../../includes/cub3d.h"

void	add_texture_node(t_texture *list, t_texture *new_node)
{
	t_texture	*cur;

	cur = list;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_node;
	new_node->next = NULL;
}

void	texture_init(t_game_info *info)
{
	int			i;
	t_texture	*head;

	i = 0;
	head = new_texture(i);
	info->map_data->textures = head;
	while (++i < 4)
		add_texture_node(info->map_data->textures, new_texture(i));
}

t_texture	*new_texture(int i)
{
	t_texture	*ret;

	ret = (t_texture *)malloc(sizeof(t_texture));
	ret->dir = i;
	ret->img_w = 64;
	ret->img_h = 64;
	ret->img = NULL;
	ret->cnt = 0;
	ret->next = NULL;
	return (ret);
}
