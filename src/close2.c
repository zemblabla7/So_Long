/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:14:25 by casomarr          #+#    #+#             */
/*   Updated: 2023/03/22 13:26:33 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* To shut down the program if pb encountered in the images path*/
void	close_img(t_data *data, t_img_check img)
{
	ft_printf("Error\nImage path\n");
	destroy_img(data, img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

/* To shut down the program if pb encountered during map checks */
void	close_map_checks(t_data *data)
{
	ft_free_images(data);
	ft_free_map_map(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

/* To shut down the program if pb encountered in the map name */
void	close_map_name(t_data *data)
{
	ft_free_images(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

/* To shut down the program if pb encountered in backtracking */
int	close_backtracking(t_data *data)
{
	ft_free_images(data);
	ft_free_maps(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
