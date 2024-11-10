/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:49:15 by djoao             #+#    #+#             */
/*   Updated: 2024/11/01 20:49:22 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	verify_file(const char *file_path)
{
	char	*ext;
	char	*result;

	ext = ".ber";
	result = ft_strrchr(file_path, '.');
	if (result != NULL && ft_strcmp(result, ext) == 0)
		return (1);
	return (0);
}

void	validate_map(const char *file_path, t_game *game)
{
	if ((open(file_path, O_RDONLY)) < 0)
	{
		ft_printf("Error\nFile doesn't exist!\n");
		exit_game(game);
	}
	if (!verify_file(file_path))
	{
		ft_printf("Error\nWrong format file!\n");
		exit_game(game);
	}
}

int	check_borders(char **map_grid, int row, int column)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if (map_grid[0][j] != '1' || map_grid[row - 1][j] != '1')
				return (0);
			j++;
		}
		if (map_grid[i][0] != '1' || map_grid[i][column - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_rectangularity(char **map_grid, int row, int column)
{
	int	i;

	i = 0;
	if (map_grid)
	{
		while (i < row)
		{
			if (map_grid[i])
			{
				if (ft_strlen(map_grid[i]) != (size_t)column)
					return (0);
			}
			i++;
		}
	}
	return (1);
}

void	allowed_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->row)
	{
		j = 0;
		while (j < game->map->column)
		{
			if (game->map->map_grid[i][j] != '1' &&
				game->map->map_grid[i][j] != '0' &&
				game->map->map_grid[i][j] != 'E' &&
				game->map->map_grid[i][j] != 'C' &&
				game->map->map_grid[i][j] != 'P')
			{
				ft_printf("Error\nUnknown element!\n");
				exit_game(game);
			}
			j++;
		}
		i++;
	}
}
