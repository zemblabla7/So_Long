/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:13:58 by casomarr          #+#    #+#             */
/*   Updated: 2023/03/22 13:19:40 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* To close window and free */
int	close_win(t_data *data)
{
	ft_free_images(data);
	ft_free_maps(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

/* To close window by pressing ESC */
int	close_esc(int key, t_data *data)
{
	if (key == XK_Escape)
		close_win(data);
	return (0);
}
