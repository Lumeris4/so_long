/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:33:39 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/07 14:30:51 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	for_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	read_map(t_data *data)
{
	int		fd;
	ssize_t	bytes_read;
	char	buffer[1024];

	fd = open(data->name_map, O_RDONLY);
	if (fd < 0)
		return ;
	bytes_read = read(fd, buffer, 1024);
	buffer[bytes_read] = '\0';
	data->map = ft_split(buffer, '\n');
	close(fd);
}

void	load_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->window, data->floor, j * 72, i * 72);
			else if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->wall, j * 72, i * 72);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->exit, j * 72, i * 72);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->window, data->ichigo, j * 72, i * 72);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->soul, j * 72, i * 72);
			j++;
		}
		i++;
	}
}

int	ft_strlen_matrice(char **matrice)
{
	int	i;

	i = 0;
	while (matrice[i])
		i++;
	return (i);
}
