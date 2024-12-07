/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:06:29 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/07 15:22:12 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include "libft/libft.h"
#include <stdbool.h>

typedef struct s_data {
    void    *mlx;
    void    *window;
    char    **map;
    char    *name_map;
    int     x;
    int     y;
    int     x_map;
    int     y_map;
    void    *floor;
    void    *wall;
    void    *soul;
    void    *ichigo;
    void    *exit;
    int     nb_soul;
    int     step;
} t_data;

int	    ft_strlen_matrice(char **matrice);
void	load_map(t_data *data);
void	read_map(t_data *data);
void	for_free(t_data *data);
bool	check_letter(t_data *data);
void	count_soul(t_data *data);
void	move_with_w(t_data *data);
void	move_with_s(t_data *data);
void	move_with_a(t_data *data);
void	move_with_d(t_data *data);
int     handle_close(t_data *data);

#endif