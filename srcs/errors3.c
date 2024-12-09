/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:36:11 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/09 16:20:29 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ber(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	i -= 4;
	if (argv[i] != '.' || argv[i + 1] != 'b'
		|| argv[i + 2] != 'e' || argv[i + 3] != 'r')
		return (false);
	return (true);
}

bool	len_screen(t_data *data)
{
	int	i;
	int	j;

	i = ft_strlen(data->map[0]);
	j = ft_strlen_matrice(data->map);
	if (i > 26 || j > 13)
		return (false);
	return (true);
}
