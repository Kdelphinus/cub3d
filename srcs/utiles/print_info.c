#include "../../includes/cub3d.h"

void print_game_info(const t_game_info *info)
{
    printf("Game Info:\n");
    printf(" - mlx: %p\n", info->mlx);
    printf(" - win: %p\n", info->win);
    printf(" - map_data:\n");
    printf("   - map:\n");
    if (info->map_data->map != NULL) {
        for (int i = 0; info->map_data->map[i] != NULL; i++) {
            printf("     %s\n", info->map_data->map[i]);
        }
    } else {
        printf("     (empty)\n");
    }
    printf("   - flr_color: %d\n", info->map_data->flr_color);
    printf("   - ceil_color: %d\n", info->map_data->ceil_color);
    printf("   - flr_count: %d\n", info->map_data->flr_count);
    printf("   - ceil_count: %d\n", info->map_data->ceil_count);
    printf("   - textures:\n");
    t_texture *texture = info->map_data->textures;
    while (texture != NULL) {
        printf("     - dir: %d\n", texture->dir);
        printf("       img: %p\n", texture->img);
        printf("       img_w: %d\n", texture->img_w);
        printf("       img_h: %d\n", texture->img_h);
        printf("       cnt: %d\n", texture->cnt);
        texture = texture->next;
    }
}
