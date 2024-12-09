/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:13:56 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/09 10:51:26 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_borders_up_down(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen_matrice(data->map) - 1;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (data->map[j][i])
	{
		if (data->map[j][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	check_borders_left_right(t_data *data)
{
	int	i;
	int	rows;
	int	cols;

	if (!data || !data->map || !data->map[0])
		return (false);
	rows = 0;
	while (data->map[rows])
		rows++;
	cols = ft_strlen(data->map[0]);
	i = 0;
	while (i < rows)
	{
		if (data->map[i][0] != '1' || data->map[i][cols - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

static void	flood_fill(char **map, int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x >= data->x_max || y >= data->y_max)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}

static bool	check_path(t_data *data)
{
	int		x;
	int		y;
	bool	result;
	char	**copy;

	copy = ft_strdup_matrice(data->map);
	count_soul(data);
	x = data->x_map;
	y = data->y_map;
	flood_fill(copy, x, y, data);
	result = check_c_or_e(copy);
	y = 0;
	while (copy[y])
	{
		free(copy[y]);
		y++;
	}
	free(copy);
	return (result);
}

bool	check_all(t_data *data)
{
	if (!check_len(data) || !check_letter(data)
		|| !check_right_number(data) || !check_borders_up_down(data)
		|| !check_borders_left_right(data) || !check_path(data))
		return (false);
	return (true);
}
