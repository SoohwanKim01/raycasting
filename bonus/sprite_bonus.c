/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:23:41 by marvin            #+#    #+#             */
/*   Updated: 2020/11/16 22:02:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			sprite_loop(t_map *map)
{
	int i;

	i = 0;
	update_sprite(map);
	sort_sprite(map);
	sprite_init(map);
	while (i <= map->sprite_nb &&\
		(map->sprite[i]->map_x || map->sprite[i]->map_y))
	{
		loop_sprites(map, i);
		i++;
	}
}
