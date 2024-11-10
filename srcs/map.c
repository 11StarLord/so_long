/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:48:04 by djoao             #+#    #+#             */
/*   Updated: 2024/11/01 20:48:08 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	count_column(char *str)
{
	int	column;

	column = 0;
	if (!str)
		return (0);
	while (str[column] != '\n')
		column++;
	return (column);
}

int	count_row(int fd)
{
	int		rows;
	char	*line;

	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close (fd);
	return (rows);
}

char	**fill_map_grid(int fd, int row, char *o_line)
{
	int		i;
	int		j;
	char	*line;
	char	**map_grid;

	i = 0;
	line = o_line;
	map_grid = NULL;
	map_grid = (char **)malloc((row) * sizeof(char *));
	while (i < row)
	{
		map_grid[i] = (char *)malloc((ft_strlen(line)) * sizeof(char));
		map_grid[i][ft_strlen(line) - 1] = '\0';
		j = 0;
		while (j < (int)ft_strlen(line) - 1)
		{
			map_grid[i][j] = line[j];
			j++;
		}
		i++;
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	return (map_grid);
}

char	**copy_map_grid(char **map_grid, int row, int column)
{
	int		i;
	int		j;
	char	**cpy;

	i = 0;
	cpy = NULL;
	cpy = (char **)malloc(sizeof(char *) * row);
	while (i < row)
	{
		j = 0;
		cpy[i] = (char *)malloc(sizeof(char *) * (column + 1));
		while (j < column)
		{
			cpy[i][j] = map_grid[i][j];
			j++;
		}
		i++;
	}
	return (cpy);
}

void	read_map(t_map *map, const char *file_path, int fd)
{
	char	*line;

	map->row = count_row(fd);
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	map->column = count_column(line);
	map->map_grid = fill_map_grid(fd, map->row, line);
	map->cpy_map_grid = copy_map_grid(map->map_grid, map->row, map->column);
}
