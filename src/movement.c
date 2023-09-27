/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:47:49 by casomarr          #+#    #+#             */
/*   Updated: 2023/03/22 14:03:38 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Swaps tiles and checks if end of game */
void	ft_move_player(t_data *data, int dx, int dy)
{
	if (data->map.map[data->map.pos_p_y + dy][data->map.pos_p_x + dx] == '0' \
	|| data->map.map[data->map.pos_p_y + dy][data->map.pos_p_x + dx] == 'C')
	{
		if (data->map.map[data->map.pos_p_y + dy][data->map.pos_p_x + dx] \
		== 'C')
			data->collectibles_collected++;
		data->map.map[data->map.pos_p_y][data->map.pos_p_x] = '0';
		data->map.map[data->map.pos_p_y + dy][data->map.pos_p_x + dx] = 'P';
		data->nb_movements++;
		ft_printf("Number of movements : %u\n", data->nb_movements);
	}
	if (data->map.map[data->map.pos_p_y + dy][data->map.pos_p_x + dx] == 'E')
	{
		if (data->collectibles_count == data->collectibles_collected)
		{
			ft_printf("Congrats you won in %u movements!\n", \
			data->nb_movements + 1);
			close_win(data);
		}
	}
	ft_map_pixels(data);
}

/*Transforms the keycode into a direction*/
int	ft_swap_tiles(int keycode, t_data *data)
{
	if (keycode == 100 || keycode == 65363)
		ft_move_player(data, 1, 0);
	else if (keycode == 97 || keycode == 65361)
		ft_move_player(data, -1, 0);
	else if (keycode == 115 || keycode == 65364)
		ft_move_player(data, 0, 1);
	else if (keycode == 119 || keycode == 65362)
		ft_move_player(data, 0, -1);
	return (0);
}
