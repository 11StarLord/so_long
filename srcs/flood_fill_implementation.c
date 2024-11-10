/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_implementation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:47:01 by djoao             #+#    #+#             */
/*   Updated: 2024/11/01 20:47:05 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <so_long.h>

void	ft_flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->column || y < 0 || y >= map->row)
		return ;
	if (map->cpy_map_grid[y][x] == 'X')
		return ;
	if (map->cpy_map_grid[y][x] == '1' || map->cpy_map_grid[y][x] == 'E')
		return ;
	map->cpy_map_grid[y][x] = 'X';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

void	ft_flood_fill_two(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->column || y < 0 || y >= map->row)
		return ;
	if (map->cpy_map_grid[y][x] == 'X')
		return ;
	if (map->cpy_map_grid[y][x] == '1')
		return ;
	map->cpy_map_grid[y][x] = 'X';
	ft_flood_fill_two(map, x + 1, y);
	ft_flood_fill_two(map, x - 1, y);
	ft_flood_fill_two(map, x, y + 1);
	ft_flood_fill_two(map, x, y - 1);
}

int	count_char_two(t_map *map, char target)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->column)
		{
			if (map->cpy_map_grid[i][j] == target)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_valid_path(t_game *game)
{
	ft_flood_fill(game->map, game->map->coord_player->x,
		game->map->coord_player->y);
	if (count_char_two(game->map, 'C') > 0)
	{
		ft_printf("Error\nCan't reach C\n");
		exit_game(game);
	}
	else
	{
		free_map_grid(game->map->cpy_map_grid, game->map->row);
		game->map->cpy_map_grid = copy_map_grid(game->map->map_grid,
				game->map->row, game->map->column);
		ft_flood_fill_two(game->map, game->map->coord_player->x,
			game->map->coord_player->y);
		if (count_char_two(game->map, 'E') > 0)
		{
			ft_printf("Error\nCan't reach E\n");
			exit_game(game);
		}
	}
}
