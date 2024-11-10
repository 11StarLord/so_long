/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:49:38 by djoao             #+#    #+#             */
/*   Updated: 2024/11/01 20:49:40 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	count_char(t_map *map, char target)
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
			if (map->map_grid[i][j] == target)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_required_chars(t_game *game)
{
	if (count_char(game->map, 'P') != 1)
	{
		ft_printf("Error\nThe map must contain exactly one player 'P'\n");
		exit_game(game);
	}
	if (count_char(game->map, 'E') != 1)
	{
		ft_printf("Error\nThe map must contain exactly one exit 'E'\n");
		exit_game(game);
	}
	if (count_char(game->map, 'C') == 0)
	{
		ft_printf("Error\nThe map must contain at least one collectible 'C'\n");
		exit_game(game);
	}
}

t_coords	*return_coords(t_map *map, char target)
{
	t_coords	*coords;
	int			i;
	int			j;

	i = 0;
	coords = NULL;
	coords = (t_coords *)malloc(sizeof(t_coords));
	while (i < map->row)
	{
		j = 0;
		while (j < map->column)
		{
			if (map->map_grid[i][j] == target)
			{
				coords->x = j;
				coords->y = i;
			}
			j++;
		}
		i++;
	}
	return (coords);
}
