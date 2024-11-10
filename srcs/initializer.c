/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:47:49 by djoao             #+#    #+#             */
/*   Updated: 2024/11/01 20:47:52 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_map	*initialize_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map_grid = NULL;
	map->cpy_map_grid = NULL;
	map->row = 0;
	map->column = 0;
	map->moves = 0;
	map->coord_player = NULL;
	map->coord_exit = NULL;
	return (map);
}

t_window	*initialize_window(void)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->mlx = NULL;
	window->mlx_window = NULL;
	window->width = 0;
	window->height = 0;
	window->cel = 50;
	return (window);
}

t_sprites	*initialize_sprites(void)
{
	t_sprites	*sprite;

	sprite = (t_sprites *)malloc(sizeof(t_sprites));
	if (!sprite)
		return (NULL);
	sprite->wall = NULL;
	sprite->player = NULL;
	sprite->collectible = NULL;
	sprite->floor = NULL;
	sprite->exit = NULL;
	return (sprite);
}
