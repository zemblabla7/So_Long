/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:22:52 by casomarr          #+#    #+#             */
/*   Updated: 2023/03/22 14:48:33 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Indicates the path of each image*/
void	ft_images(t_data *data)
{
	data->img.player1 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/horse.xpm", &data->img.width, &data->img.height);
	data->img.player2 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/unicorn.xpm", &data->img.width, &data->img.height);
	data->img.collectible = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/candy.xpm", &data->img.width, &data->img.height);
	data->img.walls1 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/bush.xpm", &data->img.width, &data->img.height);
	data->img.walls2 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/bush_candy.xpm", &data->img.width, &data->img.height);
	data->img.exit1 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/fence.xpm", &data->img.width, &data->img.height);
	data->img.exit2 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/rainbow.xpm", &data->img.width, &data->img.height);
	data->img.path = mlx_xpm_file_to_image(data->mlx_ptr, \
	"images/black_square.xpm", &data->img.width, &data->img.height);
	ft_check_images(data);
}

/*Puts the number of movements on the window*/
void	put_text(t_data *data)
{
	char	*final_text;
	char	*nb_movements;

	nb_movements = ft_itoa(data->nb_movements);
	final_text = ft_strjoin("Nb of movements :", nb_movements);
	mlx_set_font(data->mlx_ptr, data->win_ptr, "10x20");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 30, 0xffffff, final_text);
	free(final_text);
	free(nb_movements);
}

/*Indicated which image to show and makes appear
 the number of movements on the screen*/
void	ft_show_images(t_data *data, t_img_display *coord)
{
	put_text(data);
	if (data->map.map[coord->i][coord->j] == '1' && \
	data->collectibles_collected != data->collectibles_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.walls1, coord->x, coord->y);
	if (data->map.map[coord->i][coord->j] == '1' && \
	data->collectibles_collected == data->collectibles_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.walls2, coord->x, coord->y);
	if (data->map.map[coord->i][coord->j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.path, coord->x, coord->y);
	if (data->map.map[coord->i][coord->j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.collectible, coord->x, coord->y);
	ft_show_images2(data, coord);
}

void	ft_show_images2(t_data *data, t_img_display *coord)
{
	if (data->map.map[coord->i][coord->j] == 'E' && \
	data->collectibles_collected != data->collectibles_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.exit1, coord->x, coord->y);
	if (data->map.map[coord->i][coord->j] == 'E' && \
	data->collectibles_collected == data->collectibles_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.exit2, coord->x, coord->y);
	if (data->map.map[coord->i][coord->j] == 'P' && \
	data->collectibles_collected != data->collectibles_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.player1, coord->x, coord->y);
	if (data->map.map[coord->i][coord->j] == 'P' && \
	data->collectibles_collected == data->collectibles_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.player2, coord->x, coord->y);
}
