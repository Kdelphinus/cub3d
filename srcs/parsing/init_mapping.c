#include "../../includes/cub3d.h"

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

static int	check_obj(char *line, t_obj *obj)
{
	int	i;

	i = -1;
	while (line[++i] != '\n')
	{
		if (line[i] == '\0')
			break ;
		if (line[i] == 'N' && obj->n_cnt == 0)
			++obj->n_cnt;
		else if (line[i] == 'E' && obj->e_cnt == 0)
			++obj->e_cnt;
		else if (line[i] == 'S' && obj->s_cnt == 0)
			++obj->s_cnt;
		else if (line[i] == 'W' && obj->w_cnt == 0)
			++obj->w_cnt;
		else if (line[i] == ' ' || line[i] == '0' || line[i] == '1')
			continue ;
		else
			print_err_exit();
	}
	++obj->h;
	return (i);
}

t_mapping	*new_mapping(char *line, t_obj *obj)
{
	t_mapping	*ret;

	ret = (t_mapping *)malloc(sizeof(t_mapping));
	ret->line = line;
	ret->line_len = check_obj(line, obj);
	if (obj->w < ret->line_len)
		obj->w = ret->line_len;
	ret->next = NULL;
	return (ret);
}
