/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:46:11 by djoao             #+#    #+#             */
/*   Updated: 2024/11/01 20:46:25 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	switch_element(t_game *game, int i, int j)
{
	if (game->map->map_grid[i][j] == '1')
		mlx_put_image_to_window(game->window->mlx,
			game->window->mlx_window, game->sprite->wall,
			j * game->window->cel, i * game->window->cel);
	else if (game->map->map_grid[i][j] == '0')
		mlx_put_image_to_window(game->window->mlx,
			game->window->mlx_window, game->sprite->floor,
			j * game->window->cel, i * game->window->cel);
	else if (game->map->map_grid[i][j] == 'P')
		mlx_put_image_to_window(game->window->mlx,
			game->window->mlx_window, game->sprite->player,
			j * game->window->cel, i * game->window->cel);
	else if (game->map->map_grid[i][j] == 'C')
		mlx_put_image_to_window(game->window->mlx,
			game->window->mlx_window, game->sprite->collectible,
			j * game->window->cel, i * game->window->cel);
	else if (game->map->map_grid[i][j] == 'E')
		mlx_put_image_to_window(game->window->mlx,
			game->window->mlx_window, game->sprite->exit,
			j * game->window->cel, i * game->window->cel);
}

void	print_matrix_as_image(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->row)
	{
		j = 0;
		while (j < game->map->column)
		{
			switch_element(game, i, j);
			j++;
		}
		i++;
	}
}

int	update_game(t_game *game)
{
	mlx_clear_window(game->window->mlx, game->window->mlx_window);
	if (game->map->coord_player)
		free(game->map->coord_player);
	game->map->coord_player = return_coords(game->map, 'P');
	print_matrix_as_image(game);
	ft_printf("\033[H\033[J");
	ft_printf("Moves: %d\n", game->map->moves);
	if (game->map->coord_player->x == game->map->coord_exit->x
		&& game->map->coord_player->y == game->map->coord_exit->y)
	{
		ft_printf("You win!\n");
		exit_game(game);
	}
	return (0);
}

int	key_close_window(t_game *game)
{
	exit_game(game);
	return (0);
}
