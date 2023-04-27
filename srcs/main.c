/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:15:34 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/27 14:03:32 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game) * 1);
	if (ac != 2)
		return (0);
	game->map.name = av[1];
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1980, 1080, "./cub3d");
	mlx_loop(game->mlx);
	return (0);
}
