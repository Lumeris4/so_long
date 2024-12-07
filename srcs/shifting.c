/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:52:55 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/07 16:34:32 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_with_w(t_data *data)
{
	if (data->map[data->y_map - 1][data->x_map] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->floor, data->x, data->y);
		mlx_put_image_to_window(data->mlx, data->window,
			data->ichigo, data->x, data->y -= 72);
		data->y_map -= 1;
		data->step++;
		ft_printf("Step : %d\n", data->step);
	}
	if (data->map[data->y_map][data->x_map] == 'C')
	{
		data->map[data->y_map][data->x_map] = '0';
		data->nb_soul--;
	}
	else if (data->map[data->y_map - 1][data->x_map] == 'E'
			&& data->nb_soul <= 0)
	{
		data->step++;
		ft_printf("You Win with %d step !\n", data->step++);
		handle_close(data);
	}
}

void	move_with_s(t_data *data)
{
	if (data->map[data->y_map + 1][data->x_map] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->floor, data->x, data->y);
		mlx_put_image_to_window(data->mlx, data->window,
			data->ichigo, data->x, data->y += 72);
		data->y_map += 1;
		data->step++;
		ft_printf("Step : %d\n", data->step);
	}
	if (data->map[data->y_map][data->x_map] == 'C')
	{
		data->map[data->y_map][data->x_map] = '0';
		data->nb_soul--;
	}
	else if (data->map[data->y_map + 1][data->x_map] == 'E'
		&& data->nb_soul <= 0)
	{
		data->step++;
		ft_printf("You Win with %d step !\n", data->step++);
		handle_close(data);
	}
}

void	move_with_a(t_data *data)
{
	if (data->map[data->y_map][data->x_map - 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->floor, data->x, data->y);
		mlx_put_image_to_window(data->mlx, data->window,
			data->ichigo, data->x -= 72, data->y);
		data->x_map -= 1;
		data->step++;
		ft_printf("Step : %d\n", data->step);
	}
	if (data->map[data->y_map][data->x_map] == 'C')
	{
		data->map[data->y_map][data->x_map] = '0';
		data->nb_soul--;
	}
	else if (data->map[data->y_map][data->x_map - 1] == 'E'
		&& data->nb_soul <= 0)
	{
		data->step++;
		ft_printf("You Win with %d step !\n", data->step);
		handle_close(data);
	}
}

void	move_with_d(t_data *data)
{
	if (data->map[data->y_map][data->x_map + 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->floor, data->x, data->y);
		mlx_put_image_to_window(data->mlx, data->window,
			data->ichigo, data->x += 72, data->y);
		data->x_map += 1;
		data->step++;
		ft_printf("Step : %d\n", data->step);
	}
	if (data->map[data->y_map][data->x_map] == 'C')
	{
		data->map[data->y_map][data->x_map] = '0';
		data->nb_soul--;
	}
	else if (data->map[data->y_map][data->x_map + 1] == 'E'
		&& data->nb_soul <= 0)
	{
		data->step++;
		ft_printf("You Win with %d step !\n", data->step++);
		handle_close(data);
	}
}
