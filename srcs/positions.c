/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:36:53 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/09 10:51:12 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_p(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->x_map = x;
				data->y_map = y;
				data->x = x * 72;
				data->y = y * 72;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	count_soul(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				data->nb_soul++;
			x++;
		}
		y++;
	}
	find_p(data);
}

bool	check_c_or_e(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_strdup_matrice(char **s)
{
	char	**result;
	size_t	i;
	size_t	j;

	i = 0;
	result = malloc(sizeof(char *) * (ft_strlen_matrice(s) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		j = 0;
		result[i] = malloc(sizeof(char) * (ft_strlen(s[i]) + 1));
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (NULL);
		}
		ft_strcpy(result[i], s[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}
