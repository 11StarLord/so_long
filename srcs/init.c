/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:47:25 by djoao             #+#    #+#             */
/*   Updated: 2024/11/01 20:47:29 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_game	*init_game(const char *file_path)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->map = NULL;
	game->sprite = NULL;
	game->window = NULL;
	init_map(file_path, game);
	init_window(game);
	init_hook(game);
	init_sprites(game);
	print_matrix_as_image(game);
	return (game);
}

void	init_map(const char *file_path, t_game *game)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	validate_map(file_path, game);
	game->map = initialize_map();
	read_map(game->map, file_path, fd);
	if (!check_borders(game->map->map_grid, game->map->row, game->map->column))
	{
		ft_printf("Error\nThe map must be surrounded by walls!\n");
		exit_game(game);
	}
	if (!check_rectangularity(game->map->map_grid,
			game->map->row, game->map->column))
	{
		ft_printf("Error\nThe map is not rectangular!\n");
		exit_game(game);
	}
	check_required_chars(game);
	allowed_elements(game);
	game->map->coord_player = return_coords(game->map, 'P');
	game->map->coord_exit = return_coords(game->map, 'E');
	check_valid_path(game);
}

void	init_window(t_game *game)
{
	game->window = initialize_window();
	game->window->width = game->map->column * game->window->cel;
	game->window->height = game->map->row * game->window->cel;
	game->window->mlx = mlx_init();
	game->window->mlx_window = mlx_new_window(game->window->mlx,
			game->window->width, game->window->height, "so_long");
}

void	init_sprites(t_game *game)
{
	game->sprite = initialize_sprites();
	game->sprite->wall = mlx_xpm_file_to_image(game->window->mlx,
			"images/wall.xpm", &game->window->cel, &game->window->cel);
	game->sprite->player = mlx_xpm_file_to_image(game->window->mlx,
			"images/player.xpm", &game->window->cel, &game->window->cel);
	game->sprite->collectible = mlx_xpm_file_to_image(game->window->mlx,
			"images/collectible.xpm", &game->window->cel, &game->window->cel);
	game->sprite->floor = mlx_xpm_file_to_image(game->window->mlx,
			"images/floor.xpm", &game->window->cel, &game->window->cel);
	game->sprite->exit = mlx_xpm_file_to_image(game->window->mlx,
			"images/exit.xpm", &game->window->cel, &game->window->cel);
}

void	init_hook(t_game *game)
{
	mlx_hook(game->window->mlx_window, 2, 1L << 0, handle_key, game);
	mlx_hook(game->window->mlx_window, 17, 0, key_close_window, game);
}
