/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:45:29 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/07 16:22:18 by lelanglo         ###   ########.fr       */
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
	int		i;

	i = 1;
	len = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (len != ft_strlen(data->map[i]))
			return (false);
		i++;
	}
	return (true);
}
