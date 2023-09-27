/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:55:05 by casomarr          #+#    #+#             */
/*   Updated: 2023/03/22 13:36:30 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Pastes in *walls whatever values are in the first/last /
lines and columns of **map and then checks that there /
only are '1's in *walls*/
int	ft_check_walls(t_data *data)
{
	t_wall	walls;

	walls.walls = malloc(sizeof(char) * 10000);
	if (walls.walls == NULL)
		close_win(data);
	walls.w = 0;
	walls.j = 0;
	ft_first_line(data, &walls);
	ft_columns(data, &walls);
	ft_last_line(data, &walls);
	walls.w = 0;
	while (walls.walls[walls.w] != '\0')
	{
		if (walls.walls[walls.w++] != '1')
		{
			ft_printf("Error\nMap walls\n");
			free(walls.walls);
			return (1);
		}
	}
	free(walls.walls);
	return (0);
}

/*Puts first and last column in *walls*/
void	ft_columns(t_data *data, t_wall *walls)
{
	while (data->map.map[walls->i + 1] != NULL)
	{
		walls->j = 0;
		while (data->map.map[walls->i][walls->j] != '\0')
		{
			if (walls->j == 0)
				walls->walls[walls->w++] = data->map.map[walls->i][walls->j];
			if (data->map.map[walls->i][walls->j + 1] == '\0')
				walls->walls[walls->w++] = data->map.map[walls->i][walls->j];
			walls->j++;
		}
		walls->i++;
	}
}

/*Puts first line in *walls*/
void	ft_first_line(t_data *data, t_wall *walls)
{
	while (data->map.map[0][walls->j] != '\0')
		walls->walls[walls->w++] = data->map.map[0][walls->j++];
	walls->i = 1;
}

/*Puts last line in *walls*/
void	ft_last_line(t_data *data, t_wall *walls)
{
	walls->j = 0;
	while (data->map.map[walls->i][walls->j] != '\0')
		walls->walls[walls->w++] = data->map.map[walls->i][walls->j++];
	walls->walls[walls->w++] = '\0';
}
