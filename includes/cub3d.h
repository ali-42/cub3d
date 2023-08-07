/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:09:27 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 14:38:43 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "define.h"
# include "struct.h"

/* UTILS */

int		get_next_line(int fd, char **line);
void	free_char2(char **strs);
int		close_map(int fd, char **map);
void	free_textures_path(t_world *world);
void	destroy_textures(t_info *info);

/* PARSING */

int		stock_map(char *to_open, t_world *world);
int		stock_texture(char *line, t_world *world);
char	**get_map(char *file, int fd, int *size);
int		check_textures(char *file, t_world *world);
void	init_textures(t_world *world);
int		parsing(int ac, char **av, t_world *world);

/* ERROR */

int		format_error(char *str, char *line);
int		perror_int(char *str);
void	*perror_ptr(char *str);

/* MAIN */

void	init_game(t_world *world);

/* MOVES */

void	move(t_info *info);
void	get_plane(t_player *player, double dir_x, double dir_y);
void	rotate_left(t_player *player);
void	rotate_right(t_player *player);
int		key_press(int keycode, t_info *info);
int		key_release(int keycode, t_info *info);
int		close_game(t_info *info);

/* DISPLAY */

void	display_frame(t_info *info);
void	pixel_put_img(t_frame *frame, int x, int y, int color);
void	get_walls(t_player *player, char **map, t_wall *walls);
void	get_all_textures(t_info *info);
void	draw_wall(t_frame *frame, int *coor, t_wall wall, t_world *world);
void	get_precise_hit(t_player *player, t_wall *wall, t_ray *ray, int *side);

#endif
