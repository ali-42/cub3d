/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:47:12 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 16:52:41 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put_tex_pix(t_frame *frame, int x, int y, unsigned char *src)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = src[0];
	g = src[1];
	b = src[2];
	frame->addr[y * frame->line_length + x * frame->bits_per_pixel / 8] = r;
	frame->addr[y * frame->line_length + x * frame->bits_per_pixel / 8 + 1] = g;
	frame->addr[y * frame->line_length + x * frame->bits_per_pixel / 8 + 2] = b;
}

void	copy_texture(t_frame *frame, int *coor, t_wall wall, t_texture *texture)
{
	int				t_x;
	int				t_y;
	unsigned char	*src;

	t_x = (int)(wall.hit_x * (double)texture->width);
	if (wall.neg_hit)
		t_x = texture->width - t_x;
	t_y = (coor[1] + (wall.height - HEIGHT) / 2)
		* texture->height / wall.height;
	src = (unsigned char *)&texture->addr[t_y * texture->line_length
		+ t_x * texture->bits_per_pixel / 8];
	pixel_put_tex_pix(frame, coor[0], coor[1], src);
}	

void	draw_wall(t_frame *frame, int *coor, t_wall wall, t_world *world)
{
	if (wall.texture == 'N')
		copy_texture(frame, coor, wall, world->no);
	else if (wall.texture == 'S')
		copy_texture(frame, coor, wall, world->so);
	else if (wall.texture == 'W')
		copy_texture(frame, coor, wall, world->we);
	else if (wall.texture == 'E')
		copy_texture(frame, coor, wall, world->ea);
}

int	get_texture(t_texture *texture, void *mlx)
{
	texture->img = mlx_xpm_file_to_image(mlx, texture->path,
			&texture->width, &texture->height);
	if (texture->img)
		texture->addr = mlx_get_data_addr(texture->img,
				&texture->bits_per_pixel, &texture->line_length,
				&texture->endian);
	else
	{
		ft_putendl_fd("Error\nBad texture file", 2);
		return (0);
	}
	return (1);
}

void	get_all_textures(t_info *info)
{
	if (!get_texture(info->world->no, info->mlx))
		close_game(info);
	if (!get_texture(info->world->so, info->mlx))
		close_game(info);
	if (!get_texture(info->world->ea, info->mlx))
		close_game(info);
	if (!get_texture(info->world->we, info->mlx))
		close_game(info);
}
