/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:48:24 by djoao             #+#    #+#             */
/*   Updated: 2024/11/01 20:48:27 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	handle_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		key_close_window(game);
	if (key == KEY_W || key == KEY_UP)
	{
		move_player_up(game);
		update_game(game);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		move_player_down(game);
		update_game(game);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		move_player_left(game);
		update_game(game);
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		move_player_right(game);
		update_game(game);
	}
	return (0);
}

void	move_player_up(t_game *game)
{
	t_coords	*p;

	p = return_coords(game->map, 'P');
	if (((game->map->map_grid[p->y - 1][p->x] != '1'
			&& (game->map->map_grid[p->y - 1][p->x] == 'E'
			&& count_char(game->map, 'C') == 0))
		|| game->map->map_grid[p->y - 1][p->x] == '0'
		|| game->map->map_grid[p->y - 1][p->x] == 'C'))
	{
		game->map->map_grid[p->y][p->x] = '0';
		game->map->map_grid[p->y - 1][p->x] = 'P';
		game->map->moves++;
	}
	if (p)
		free(p);
}

void	move_player_down(t_game *game)
{
	t_coords	*p;

	p = return_coords(game->map, 'P');
	if (((game->map->map_grid[p->y + 1][p->x] != '1'
			&& (game->map->map_grid[p->y + 1][p->x] == 'E'
			&& count_char(game->map, 'C') == 0))
		|| game->map->map_grid[p->y + 1][p->x] == 'C'
		|| game->map->map_grid[p->y + 1][p->x] == '0'))
	{
		game->map->map_grid[p->y][p->x] = '0';
		game->map->map_grid[p->y + 1][p->x] = 'P';
		game->map->moves++;
	}
	if (p)
		free(p);
}

void	move_player_left(t_game *game)
{
	t_coords	*p;

	p = return_coords(game->map, 'P');
	if (((game->map->map_grid[p->y][p->x - 1] != '1'
			&& (game->map->map_grid[p->y][p->x - 1] == 'E'
			&& count_char(game->map, 'C') == 0))
		|| game->map->map_grid[p->y][p->x - 1] == 'C'
		|| game->map->map_grid[p->y][p->x - 1] == '0'))
	{
		game->map->map_grid[p->y][p->x] = '0';
		game->map->map_grid[p->y][p->x - 1] = 'P';
		game->map->moves++;
	}
	if (p)
		free(p);
}

void	move_player_right(t_game *game)
{
	t_coords	*p;

	p = return_coords(game->map, 'P');
	if (((game->map->map_grid[p->y][p->x + 1] != '1'
			&& (game->map->map_grid[p->y][p->x + 1] == 'E'
			&& count_char(game->map, 'C') == 0))
		|| game->map->map_grid[p->y][p->x + 1] == 'C'
		|| game->map->map_grid[p->y][p->x + 1] == '0'))
	{
		game->map->map_grid[p->y][p->x] = '0';
		game->map->map_grid[p->y][p->x + 1] = 'P';
		game->map->moves++;
	}
	if (p)
		free(p);
}
