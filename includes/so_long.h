/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 01:33:26 by djoao             #+#    #+#             */
/*   Updated: 2024/11/02 01:33:29 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_A 97
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# include "../libs/ft_printf/ft_printf.h"
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_window;
	int		width;
	int		height;
	int		cel;
}	t_window;

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*player;
	void	*exit;
}	t_sprites;

typedef struct s_map
{
	t_coords	*coord_player;
	t_coords	*coord_exit;
	char		**map_grid;
	char		**cpy_map_grid;
	int			row;
	int			column;
	int			moves;
}	t_map;

typedef struct s_game
{
	t_window	*window;
	t_sprites	*sprite;
	t_map		*map;
}	t_game;

t_map		*initialize_map(void);
t_window	*initialize_window(void);
t_sprites	*initialize_sprites(void);
t_game		*init_game(const char *file_path);
t_coords	*return_coords(t_map *map, char target);
char		**fill_map_grid(int fd, int row, char *o_line);
char		**copy_map_grid(char **map_grid, int row, int column);
void		validate_map(const char *file_path, t_game *game);
void		read_map(t_map *map, const char *file_path, int fd);
void		check_required_chars(t_game *game);
void		allowed_elements(t_game *game);
void		ft_flood_fill(t_map *map, int x, int y);
void		ft_flood_fill_two(t_map *map, int x, int y);
void		init_map(const char *file_path, t_game *game);
void		init_window(t_game *game);
void		init_sprites(t_game *game);
void		init_hook(t_game *game);
void		check_valid_path(t_game *game);
void		print_matrix_as_image(t_game *game);
void		move_player_up(t_game *game);
void		move_player_down(t_game *game);
void		move_player_left(t_game *game);
void		move_player_right(t_game *game);
void		switch_element(t_game *game, int i, int j);
void		print_matrix_as_image(t_game *game);
void		free_game(t_game *game);
void		free_map_grid(char **map_grid, int row);
void		free_window(t_game *game);
void		free_map(t_game *game);
void		free_sprites(t_game *game);
int			verify_file(const char *file_path);
int			count_column(char *str);
int			count_row(int fd);
int			check_borders(char **map_grid, int row, int column);
int			check_rectangularity(char **map_grid, int row, int column);
int			handle_key(int key, t_game *game);
int			count_char(t_map *map, char target);
int			count_char_two(t_map *map, char target);
int			update_game(t_game *game);
int			key_close_window(t_game *game);
int			exit_game(t_game *game);
int			all_collectibles_collected(t_map *map);
int			update_game(t_game *game);

#endif
