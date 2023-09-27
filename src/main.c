/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:05:23 by casomarr          #+#    #+#             */
/*   Updated: 2023/03/22 14:43:39 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Checks that the pointers mlx_ptr and win_ptr
have been initialized correctly*/
void	check_init(char param, t_data *data)
{
	if (param == 'm')
	{
		if (data->mlx_ptr == NULL)
		{
			ft_printf("Error\nMlx init\n");
			exit(1);
		}
	}
	if (param == 'w')
	{
		if (data->win_ptr == NULL)
		{
			ft_printf("Error\nWindow pointer\n");
			free(data->mlx_ptr);
			exit(1);
		}
	}
}

/*Gets window height and width by multiplying the height/width
 of the images by the number of images in the map*/
void	ft_window_size(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	data->window_height = 0;
	while (data->map.map[y] != NULL)
	{
		x = 0;
		data->window_width = 0;
		while (data->map.map[y][x] != '\0')
		{
			data->window_width += data->img.width;
			x++;
		}
		y++;
		data->window_height += data->img.height;
	}
	data->window_width += 1;
	data->window_height += 1;
}

/*Checks if the map file ends with .ber*/
bool	ft_check_map_format(t_data *data)
{
	char	*format;
	int		i;

	i = 0;
	format = ".ber";
	while (format[i] != '\0')
	{
		if (format[i] != data->map_path[ft_strlen(data->map_path) - 4 + i])
		{
			ft_printf("Error\nWrong map format\n");
			return (false);
		}
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		return (0);
	data.map_path = argv[1];
	if (ft_check_map_format(&data) == false)
		return (0);
	data.nb_movements = 0;
	data.collectibles_collected = 0;
	data.mlx_ptr = mlx_init();
	check_init('m', &data);
	ft_images(&data);
	ft_show_map(&data);
	ft_window_size(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.window_width, \
	data.window_height, "mlx window");
	check_init('w', &data);
	ft_map_pixels(&data);
	mlx_key_hook(data.win_ptr, ft_swap_tiles, &data);
	mlx_hook(data.win_ptr, 17, StructureNotifyMask, close_win, &data);
	mlx_hook(data.win_ptr, 02, KeyPressMask, close_esc, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
