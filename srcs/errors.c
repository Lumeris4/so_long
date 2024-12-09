/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:45:29 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/09 14:28:37 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_if(char c)
{
	if (c == 'P' || c == '0' || c == '1'
		|| c == 'E' || c == 'C')
		return (1);
	return (0);
}

bool	check_letter(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = data->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_if(map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_len(t_data *data)
{
	size_t	len;
	int		len_matrice;
	int		i;

	i = 1;
	len_matrice = ft_strlen_matrice(data->map);
	len = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (len != ft_strlen(data->map[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	check(int c, int p, int e)
{
	if (c < 1 || p != 1 || e != 1)
		return (false);
	return (true);
}

bool	check_right_number(t_data *data)
{
	int	count_c;
	int	count_p;
	int	count_e;
	int	x;
	int	y;

	count_c = 0;
	count_e = 0;
	count_p = 0;
	y = 0;
	while (data->map[y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'C')
				count_c++;
			else if (data->map[y][x] == 'P')
				count_p++;
			else if (data->map[y][x] == 'E')
				count_e++;
		}
		y++;
	}
	return (check(count_c, count_p, count_e));
}
