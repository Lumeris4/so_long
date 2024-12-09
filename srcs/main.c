/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:01:47 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/09 15:23:34 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->floor);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->ichigo);
	mlx_destroy_image(data->mlx, data->soul);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	for_free(data);
	exit(0);
	return (0);
}

static int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		handle_close(data);
	}
	else if (keycode == 'd' && data->map[data->y_map][data->x_map + 1] != '1')
		move_with_d(data);
	else if (keycode == 'a' && data->map[data->y_map][data->x_map - 1] != '1')
		move_with_a(data);
	else if (keycode == 'w' && data->map[data->y_map - 1][data->x_map] != '1')
		move_with_w(data);
	else if (keycode == 's' && data->map[data->y_map + 1][data->x_map] != '1')
		move_with_s(data);
	return (0);
}

static void	init_image(t_data *data)
{
	int	size;
	int	x;
	int	y;

	x = ft_strlen(data->map[0]);
	y = ft_strlen_matrice(data->map);
	data->window = mlx_new_window(data->mlx, x * 72, y * 72, "so_long");
	data->floor = mlx_xpm_file_to_image(data->mlx,
			"img/floor.xpm", &size, &size);
	data->ichigo = mlx_xpm_file_to_image(data->mlx,
			"img/ichigo.xpm", &size, &size);
	data->wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm", &size, &size);
	data->exit = mlx_xpm_file_to_image(data->mlx, "img/door.xpm", &size, &size);
	data->soul = mlx_xpm_file_to_image(data->mlx, "img/soul.xpm", &size, &size);
	data->nb_soul = 0;
	data->step = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\nCorrect synthax: ./so_long [path_map]\n");
		return (1);
	}
	data.name_map = argv[1];
	if (!read_map(&data))
		return (write(2, "Error\nMap can't be open", 24));
	if (!check_all(&data, argv[1]))
	{
		ft_putstr_fd("Error\nMap Error\n", 2);
		for_free(&data);
		return (1);
	}
	data.mlx = mlx_init();
	init_image(&data);
	load_map(&data);
	count_soul(&data);
	mlx_key_hook(data.window, handle_key, &data);
	mlx_hook(data.window, 17, 0, handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
