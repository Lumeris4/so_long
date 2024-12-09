/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:06:29 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/09 14:46:33 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include "libft/libft.h"
# include <stdbool.h>

typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	**map;
	char	*name_map;
	int		x;
	int		y;
	int		x_map;
	int		y_map;
	int		x_max;
	int		y_max;
	void	*floor;
	void	*wall;
	void	*soul;
	void	*ichigo;
	void	*exit;
	int		nb_soul;
	int		step;
}	t_data;

int		ft_strlen_matrice(char **matrice);
void	load_map(t_data *data);
int		read_map(t_data *data);
void	for_free(t_data *data);
bool	check_letter(t_data *data);
void	count_soul(t_data *data);
void	move_with_w(t_data *data);
void	move_with_s(t_data *data);
void	move_with_a(t_data *data);
void	move_with_d(t_data *data);
int		handle_close(t_data *data);
bool	check_right_number(t_data *data);
bool	check_all(t_data *data, char *argv);
bool	check_len(t_data *data);
bool	check_c_or_e(char **map);
bool	ber(char *argv);
char	**ft_strdup_matrice(char **s);

#endif