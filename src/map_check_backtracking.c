/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_backtracking.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:24:43 by casomarr          #+#    #+#             */
/*   Updated: 2023/03/22 13:32:20 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Checks that x and y are inside the map and that the position is not
a wall or the Exit so that it is safe for the player to move there*/
bool	safe_position(t_data *data, int x, int y)
{
	if (data->map.map[y][x] != '1' && data->map.map[y][x] != 'E')
		return (true);
	return (false);
}

/*initializes map_dup with zeros + initializes c_count and exit_found*/
void	init_solution_map(t_data *data)
{
	int	x;
	int	y;

	data->map.map_dup = malloc(data->map.len_y * sizeof(char *));
	if (data->map.map_dup == NULL)
		close_win(data);
	y = 0;
	while (y < data->map.len_y)
	{
		x = 0;
		data->map.map_dup[y] = malloc(data->map.len_x * sizeof(char) + 1);
		if (data->map.map_dup[y] == NULL)
			close_win(data);
		while (x < data->map.len_x)
		{
			data->map.map_dup[y][x] = '0';
			x++;
		}
		data->map.map_dup[y][x] = '\0';
		y++;
	}
	data->c_count = 0;
	data->map.exit_found = false;
}

/*Returns false if no path is possible to find the
Exit or the collectibles, otherwise returns true*/
bool	ft_backtracking(t_data *data)
{
	data->collectibles_count = ft_check_tiles('C', data);
	len(data);
	init_solution_map(data);
	if (ft_backtracking_map_dup(data, data->map.pos_p_x, \
	data->map.pos_p_y) == false)
		return (false);
	return (true);
}

bool	ft_backtracking_move(t_data *data, int x, int y)
{
	if (ft_backtracking_map_dup(data, x + 1, y) == true)
		return (true);
	if (ft_backtracking_map_dup(data, x, y + 1) == true)
		return (true);
	if (ft_backtracking_map_dup(data, x - 1, y) == true)
		return (true);
	if (ft_backtracking_map_dup(data, x, y - 1) == true)
		return (true);
	return (false);
}

/*Cheks if the exit and all collectibles are accessible by
writing one possible path in map_dup*/
bool	ft_backtracking_map_dup(t_data *data, int x, int y)
{
	if (x == data->map.pos_e_x && y == data->map.pos_e_y)
		data->map.exit_found = true;
	if (data->c_count == data->collectibles_count && \
	data->map.exit_found == true)
		return (true);
	if (safe_position(data, x, y) == true)
	{
		if (data->map.map_dup[y][x] == '1' || data->map.map_dup[y][x] == 'C')
			return (false);
		if (data->map.map[y][x] == 'C' && data->map.map_dup[y][x] != 'C')
		{
			data->c_count++;
			data->map.map_dup[y][x] = 'C';
		}
		if (data->map.map_dup[y][x] != 'C')
			data->map.map_dup[y][x] = '1';
		if (ft_backtracking_move(data, x, y) == true)
			return (true);
		return (false);
	}
	return (false);
}
