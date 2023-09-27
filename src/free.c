/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:27:59 by casomarr          #+#    #+#             */
/*   Updated: 2023/03/22 13:29:56 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Frees both map.map and map.map_dup*/
void	ft_free_maps(t_data *data)
{
	int	x;

	x = 0;
	while (data->map.map[x] != NULL)
	{
		free(data->map.map[x]);
		free(data->map.map_dup[x]);
		x++;
	}
	free(data->map.map);
	free(data->map.map_dup);
}

/*Frees map.map*/
void	ft_free_map_map(t_data *data)
{
	int	x;

	x = 0;
	while (data->map.map[x] != NULL)
	{
		free(data->map.map[x]);
		x++;
	}
	free(data->map.map);
}

/*Destroys all images except the ones that are NULL*/
void	destroy_img(t_data *data, t_img_check img)
{
	if (img != PLAYER1 && data->img.player1)
		mlx_destroy_image(data->mlx_ptr, data->img.player1);
	if (img != PLAYER2 && data->img.player2)
		mlx_destroy_image(data->mlx_ptr, data->img.player2);
	if (img != COLLECTIBLE && data->img.collectible)
		mlx_destroy_image(data->mlx_ptr, data->img.collectible);
	if (img != WALLS1 && data->img.walls1)
		mlx_destroy_image(data->mlx_ptr, data->img.walls1);
	if (img != WALLS2 && data->img.walls2)
		mlx_destroy_image(data->mlx_ptr, data->img.walls2);
	if (img != EXIT1 && data->img.exit1)
		mlx_destroy_image(data->mlx_ptr, data->img.exit1);
	if (img != EXIT2 && data->img.exit2)
		mlx_destroy_image(data->mlx_ptr, data->img.exit2);
	if (img != PATH && data->img.path)
		mlx_destroy_image(data->mlx_ptr, data->img.path);
}

/*Checks if the images are NULL (= wrong path)*/
void	ft_check_images(t_data *data)
{
	t_img_check	img;

	img = 42;
	if (data->img.player1 == NULL)
		img = PLAYER1;
	if (data->img.player2 == NULL)
		img = PLAYER2;
	if (data->img.collectible == NULL)
		img = COLLECTIBLE;
	if (data->img.walls1 == NULL)
		img = WALLS1;
	if (data->img.walls2 == NULL)
		img = WALLS2;
	if (data->img.exit1 == NULL)
		img = EXIT1;
	if (data->img.exit2 == NULL)
		img = EXIT2;
	if (data->img.path == NULL)
		img = PATH;
	if (img != 42)
		close_img(data, img);
}

/*Destroys all the images*/
void	ft_free_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.player1);
	mlx_destroy_image(data->mlx_ptr, data->img.player2);
	mlx_destroy_image(data->mlx_ptr, data->img.collectible);
	mlx_destroy_image(data->mlx_ptr, data->img.walls1);
	mlx_destroy_image(data->mlx_ptr, data->img.walls2);
	mlx_destroy_image(data->mlx_ptr, data->img.exit1);
	mlx_destroy_image(data->mlx_ptr, data->img.exit2);
	mlx_destroy_image(data->mlx_ptr, data->img.path);
}
