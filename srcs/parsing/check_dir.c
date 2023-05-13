#include "../../includes/cub3d.h"

int check_no(char *img_path, t_game_info *info)
{
    t_texture *cur;
    t_texture *new;

    cur = info->map_data->textures;
    new = 0;
    while (cur != NULL)
    {
        if (cur->dir == NO && cur->cnt != 0)
            print_err_exit();
        
        if (cur->dir == NO)
            print_err_exit(); // 이미 NO에 대한 값이 있는 경우 처리를 중단
        
        if (cur->next == NULL)
        {
            new = new_texture(info, img_path);
            new->dir = NO;
            add_texture_node(info->map_data->textures, new);
            return (0); // 새로운 노드를 추가한 후 처리를 중단
        }
        cur = cur->next;
    }
    return (0);
}

int check_so(char *img_path, t_game_info *info)
{
    t_texture *cur;
    t_texture *new;

    cur = info->map_data->textures;
    new = 0;
    while (cur != NULL)
    {
        if (cur->dir == SO && cur->cnt != 0)
            print_err_exit();
        
        if (cur->dir == SO)
            print_err_exit();
        
        if (cur->next == NULL)
        {
            new = new_texture(info, img_path);
            new->dir = SO;
            add_texture_node(info->map_data->textures, new);
            return (0);
        }
        cur = cur->next;
    }
    return (0);
}

int check_we(char *img_path, t_game_info *info)
{
    t_texture *cur;
    t_texture *new;

    cur = info->map_data->textures;
    new = 0;
    while (cur != NULL)
    {
        if (cur->dir == WE && cur->cnt != 0)
            print_err_exit();
        
        if (cur->dir == WE)
            print_err_exit();
        
        if (cur->next == NULL)
        {
            new = new_texture(info, img_path);
            new->dir = WE;
            add_texture_node(info->map_data->textures, new);
            return (0);
        }
        cur = cur->next;
    }
    return (0);
}

int check_ea(char *img_path, t_game_info *info)
{
    t_texture *cur;
    t_texture *new;

    cur = info->map_data->textures;
    new = 0;
    while (cur != NULL)
    {
        if (cur->dir == EA && cur->cnt != 0)
            print_err_exit();
        
        if (cur->dir == EA)
            print_err_exit();
        
        if (cur->next == NULL)
        {
            new = new_texture(info, img_path);
            new->dir = EA;
            add_texture_node(info->map_data->textures, new);
            return (0);
        }
        cur = cur->next;
    }
    return (0);
}