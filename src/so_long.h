/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:22:38 by casomarr          #+#    #+#             */
/*   Updated: 2023/03/22 17:48:11 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

# include <unistd.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

typedef enum e_img_check
{
	PLAYER1,
	PLAYER2,
	COLLECTIBLE,
	WALLS1,
	WALLS2,
	EXIT1,
	EXIT2,
	PATH,
}	t_img_check;

typedef struct s_img
{
	void	*player1;
	void	*player2;
	void	*collectible;
	void	*walls1;
	void	*walls2;
	void	*exit1;
	void	*exit2;
	void	*path;
	int		height;
	int		width;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		pos_p_x;
	int		pos_p_y;
	int		pos_e_x;
	int		pos_e_y;
	int		len_x;
	int		len_y;
	char	**map_dup;
	bool	exit_found;
}	t_map;

typedef struct s_wall
{
	char			*walls;
	unsigned int	i;
	unsigned int	j;
	unsigned int	w;
}	t_wall;

typedef struct s_img_display
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	x;
	unsigned int	y;
}	t_img_display;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*map_path;
	unsigned int	nb_movements;
	int				new_position;
	unsigned int	collectibles_count;
	unsigned int	collectibles_collected;
	unsigned int	c_count;
	unsigned int	window_width;
	unsigned int	window_height;
	t_img			img;
	t_map			map;
}	t_data;

/*close.c*/
int		close_win(t_data *data);
int		close_esc(int key, t_data *data);

/*close2.c*/
void	close_img(t_data *data, t_img_check img);
void	close_map_checks(t_data *data);
int		close_backtracking(t_data *data);
void	close_map_name(t_data *data);

/*free.c*/
void	ft_free_maps(t_data *data);
void	destroy_img(t_data *data, enum e_img_check img);
void	ft_check_images(t_data *data);
void	ft_free_images(t_data *data);
void	ft_free_map_map(t_data *data);

/*images.c*/
void	ft_images(t_data *data);
void	put_text(t_data *data);
void	ft_show_images(t_data *data, t_img_display *coord);
void	ft_show_images2(t_data *data, t_img_display *coord);

/*main.c*/
void	check_init(char param, t_data *data);
void	ft_window_size(t_data *data);
bool	ft_check_map_format(t_data *data);

/*map_check_backtracking.c*/
bool	safe_position(t_data *data, int x, int y);
void	init_solution_map(t_data *data);
bool	ft_backtracking(t_data *data);
bool	ft_backtracking_move(t_data *data, int x, int y);
bool	ft_backtracking_map_dup(t_data *data, int x, int y);

/*map_checks.c*/
void	len(t_data *data);
int		ft_check_map(t_data *data);
int		ft_check_tiles(char type, t_data *data);
int		ft_check_map_shape(t_data *data);
bool	ft_check_types(t_data *data);

/*map_checks2.c*/
int		ft_check_walls(t_data *data);
void	ft_columns(t_data *data, t_wall *walls);
void	ft_first_line(t_data *data, t_wall *walls);
void	ft_last_line(t_data *data, t_wall *walls);

/*map.c*/
void	ft_map_pixels(t_data *data);
void	ft_tiles_position(t_data *data);
void	ft_show_map(t_data *data);
void	ft_check_empty_map(t_data *data);
void	ft_check_file(t_data *data, int fd, char type);

/*movement.c*/
void	ft_move_player(t_data *data, int dx, int dy);
int		ft_swap_tiles(int keycode, t_data *data);

#endif
