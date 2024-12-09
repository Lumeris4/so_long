/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:13:56 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/09 16:23:18 by lelanglo         ###   ########.fr       */
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

static void	flood_fill(char **map, int x, int y, int *valid)
{
	if (y < 0 || !map || !map[y] || x < 0 || x >= (int)ft_strlen(map[y]))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		(*valid)--;
		return ;
	}
	if (map[y][x] == 'C')
		(*valid)--;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, valid);
	flood_fill(map, x - 1, y, valid);
	flood_fill(map, x, y + 1, valid);
	flood_fill(map, x, y - 1, valid);
}

static bool	check_path(t_data *data)
{
	int		x;
	int		y;
	char	**copy;
	int		valid;

	copy = ft_strdup_matrice(data->map);
	count_soul(data);
	x = data->x_map;
	y = data->y_map;
	valid = data->nb_soul + 1;
	flood_fill(copy, x, y, &valid);
	y = 0;
	while (copy[y])
	{
		free(copy[y]);
		y++;
	}
	free(copy);
	if (valid <= 0)
		return (true);
	return (false);
}

bool	check_all(t_data *data, char *argv)
{
	if (!ber(argv)
		|| !check_len(data) || !len_screen(data)
		|| !check_letter(data) || !check_right_number(data)
		|| !check_borders_up_down(data) || !check_borders_left_right(data)
		|| !check_path(data))
	{
		ft_putstr_fd("Error\n", 2);
		if (!ber(argv))
			ft_putstr_fd("Map must be a .ber\n", 2);
		else if (!check_len(data) || !len_screen(data))
			ft_putstr_fd("Wrong map len\n", 2);
		else if (!check_letter(data) || !check_right_number(data))
			ft_putstr_fd("Map haven't right elements\n", 2);
		else if (!check_borders_up_down(data)
			|| !check_borders_left_right(data))
			ft_putstr_fd("Map must be surrounded by wall\n", 2);
		else if (!check_path(data))
			ft_putstr_fd("Map not playable\n", 2);
		return (false);
	}
	return (true);
}
