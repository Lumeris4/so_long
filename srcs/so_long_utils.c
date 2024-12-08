/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:33:39 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/08 15:12:00 by lelanglo         ###   ########.fr       */
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

static void	put_image_to_window(t_data *data, int i, int j, char tile)
{
	void	*img;

	if (tile == '0')
		img = data->floor;
	else if (tile == '1')
		img = data->wall;
	else if (tile == 'E')
		img = data->exit;
	else if (tile == 'P')
		img = data->ichigo;
	else if (tile == 'C')
		img = data->soul;
	else
		return ;
	mlx_put_image_to_window(data->mlx, data->window, img, j * 72, i * 72);
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
			put_image_to_window(data, i, j, data->map[i][j]);
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
