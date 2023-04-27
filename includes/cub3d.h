/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:16:09 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/27 14:07:21 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../lib/libft.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <math.h>

typedef struct s_map
{
	void	*map_ptr;
	char	*name;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_game;

#endif