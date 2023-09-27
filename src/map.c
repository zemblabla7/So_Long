/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:12:40 by casomarr          #+#    #+#             */
/*   Updated: 2023/05/11 15:59:56 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Shows the images corresponding to the **map tiles*/
void	ft_map_pixels(t_data *data)
{
	t_img_display	coord;

	coord.i = 0;
	coord.y = 0;
	while (data->map.map[coord.i] != NULL)
	{
		coord.j = 0;
		coord.x = 0;
		while (data->map.map[coord.i][coord.j] != '\0')
		{
			ft_show_images(data, &coord);
			coord.x += data->img.width;
			coord.j++;
		}
		coord.i++;
		coord.y += data->img.height;
	}
	ft_tiles_position(data);
}

/*Puts in data the positions of E and P*/
void	ft_tiles_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i] != NULL)
	{
		j = 0;
		while (data->map.map[i][j] != '\0')
		{
			if (data->map.map[i][j] == 'E')
			{
				data->map.pos_e_x = j;
				data->map.pos_e_y = i;
			}
			if (data->map.map[i][j] == 'P')
			{
				data->map.pos_p_x = j;
				data->map.pos_p_y = i;
			}
			j++;
		}
		i++;
	}
}

/*Puts info of the .ber file into **map using GNL*/
void	ft_show_map(t_data *data)
{
	int		fd;
	char	*file;
	char	*line;
	char	*backup;

	file = data->map_path;
	fd = open(file, O_RDONLY);
	ft_check_file(data, fd, 'o');
	line = get_next_line(fd);
	backup = NULL;
	while (line != NULL)
	{
		backup = ft_joinstr(backup, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	data->map.map = ft_split(backup, '\n');
	ft_check_empty_map(data);
	free(backup);
	ft_check_file(data, fd, 'c');
	ft_tiles_position(data);
	ft_check_map(data);
}

/*Checks that the map isnn't empty*/
void	ft_check_empty_map(t_data *data)
{
	if (data->map.map == NULL)
	{
		ft_printf("Error\nEmpty map\n");
		close_map_name(data);
	}
}

/*Checks that the file was opened/closed correctly*/
void	ft_check_file(t_data *data, int fd, char type)
{
	if (type == 'o')
	{
		if (fd == -1)
		{
			ft_printf("Error\nFailed to open map file\n");
			close_map_name(data);
		}
	}
	if (type == 'c')
	{
		if (close(fd) == -1)
		{
			printf("Error\nFailed to close map file\n");
			close_map_name(data);
		}
	}
}
