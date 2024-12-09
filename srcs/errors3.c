/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:36:11 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/09 15:27:34 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ber(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 1;
	i -= 4;
	if (argv[i] != '.' || argv[i + 1] != 'b'
		|| argv[i + 2] != 'e' || argv[i + 3] != 'r')
		return (false);
	return (true);
}
