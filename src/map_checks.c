/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:52:24 by casomarr          #+#    #+#             */
/*   Updated: 2023/03/22 13:33:35 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*To get map size*/
void	len(t_data *data)
{
	data->map.len_y = 0;
	while (data->map.map[data->map.len_y] != NULL)
	{
		data->map.len_x = 0;
		while (data->map.map[data->map.len_y][data->map.len_x] != '\0')
			data->map.len_x++;
		data->map.len_y++;
	}
}

/*Function that calls every check function*/
int	ft_check_map(t_data *data)
{
	if (ft_check_tiles('E', data) != 1 || ft_check_tiles('P', data) != 1 \
	|| ft_check_tiles('C', data) < 1)
	{
		ft_printf("Error\nItems\n");
		close_map_checks(data);
	}
	if (ft_check_map_shape(data) == 1)
	{
		ft_printf("Error\nMap shape\n");
		close_map_checks(data);
	}
	if (ft_check_walls(data) == 1)
		close_map_checks(data);
	if (ft_check_types(data) == false)
		close_map_checks(data);
	if (ft_backtracking(data) == false)
	{
		printf("Error\nCollectibles or exit not accessible\n");
		close_backtracking(data);
	}
	return (0);
}

/*Counts how many types of each tile are in the map*/
int	ft_check_tiles(char type, t_data *data)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = 0;
	while (data->map.map[i] != NULL)
	{
		j = 0;
		while (data->map.map[i][j] != '\0')
		{
			if (data->map.map[i][j] == type)
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

/*Compares the length of the first line to every /
other line (has to be a rectangle)*/
int	ft_check_map_shape(t_data *data)
{
	int	i;
	int	j;
	int	len_first_line;

	len_first_line = 0;
	i = 0;
	j = 0;
	while (data->map.map[i][j++] != '\0')
		len_first_line = j;
	while (data->map.map[i] != NULL)
	{
		j = 0;
		while (data->map.map[i][j] != '\0')
			j++;
		if (len_first_line != j)
			return (1);
		i++;
	}
	return (0);
}

/*Checks that there is no invalid tile type*/
bool	ft_check_types(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i] != NULL)
	{
		j = 0;
		while (data->map.map[i][j] != '\0')
		{
			if (data->map.map[i][j] != '0' \
			&& data->map.map[i][j] != '1' \
			&& data->map.map[i][j] != 'E' \
			&& data->map.map[i][j] != 'C' \
			&& data->map.map[i][j] != 'P')
			{
				ft_printf("Error\nItem type\n");
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
