#include "../../includes/cub3d.h"

void	add_mapping_node(t_mapping *list, t_mapping *new_node)
{
	t_mapping	*cur;

	cur = list;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new_node;
	new_node->next = NULL;
}

static int	check_obj(char *line, t_obj *obj)
{
	int	i;

	i = -1;
	if (line[0] == '\0')
		return (-1);// 일단 eof면 -1;
	while (line[++i] != '\n')
	{
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
	ret->next = NULL;
	return (ret);
}
