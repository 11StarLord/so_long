/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:46:44 by djoao             #+#    #+#             */
/*   Updated: 2024/11/01 20:46:47 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_map_grid(char **map_grid, int row)
{
	int	i;

	i = 0;
	if (map_grid)
	{
		while (i < row)
		{
			free(map_grid[i]);
			i++;
		}
		free(map_grid);
	}
}

void	free_window(t_game *game)
{
	if (game->window)
	{
		if (game->window->mlx_window)
			mlx_destroy_window(game->window->mlx, game->window->mlx_window);
		if (game->window->mlx)
		{
			mlx_destroy_display(game->window->mlx);
			free(game->window->mlx);
		}
		free(game->window);
	}
}

void	free_map(t_game *game)
{
	if (game->map)
	{
		if (game->map->coord_player)
			free(game->map->coord_player);
		if (game->map->coord_exit)
			free(game->map->coord_exit);
		free(game->map);
	}
}

void	free_sprites(t_game *game)
{
	if (game->sprite)
	{
		if (game->sprite->wall)
			mlx_destroy_image(game->window->mlx, game->sprite->wall);
		if (game->sprite->player)
			mlx_destroy_image(game->window->mlx, game->sprite->player);
		if (game->sprite->collectible)
			mlx_destroy_image(game->window->mlx, game->sprite->collectible);
		if (game->sprite->floor)
			mlx_destroy_image(game->window->mlx, game->sprite->floor);
		if (game->sprite->exit)
			mlx_destroy_image(game->window->mlx, game->sprite->exit);
		free(game->sprite);
	}
}

int	exit_game(t_game *game)
{
	if (game)
	{
		if (game->map)
		{
			free_map_grid(game->map->map_grid, game->map->row);
			free_map_grid(game->map->cpy_map_grid, game->map->row);
		}
		free_sprites(game);
		free_window(game);
		free_map(game);
		free(game);
	}
	exit(0);
}
