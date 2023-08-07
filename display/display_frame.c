/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:02:53 by ali               #+#    #+#             */
/*   Updated: 2022/03/07 16:24:33 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put_img(t_frame *frame, int x, int y, int color)
{
	char	*dest;

	dest = frame->addr + (y * frame->line_length
			+ x * (frame->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_stripe(t_wall wall, int x, t_frame *frame, t_world *world)
{
	int	i;
	int	*celling;
	int	*floor;
	int	coor[2];

	celling = world->color_c;
	floor = world->color_f;
	i = 0;
	while (i < HEIGHT)
	{
		if (i < wall.begin)
			pixel_put_img(frame, x, i, trgb(0, celling[0],
					celling[1], celling[2]));
		else if (i > wall.end)
			pixel_put_img(frame, x, i, trgb(0, floor[0],
					floor[1], floor[2]));
		else
		{
			coor[0] = x;
			coor[1] = i;
			draw_wall(frame, coor, wall, world);
		}
		i++;
	}
}

void	draw_frame(t_frame *frame, t_wall *walls, t_world *world)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		walls[i].height = (int)(HEIGHT / walls[i].dist);
		walls[i].begin = (HEIGHT - walls[i].height) / 2;
		if (walls[i].begin < 0)
			walls[i].begin = 0;
		walls[i].end = (HEIGHT + walls[i].height) / 2;
		if (walls[i].end > HEIGHT)
			walls[i].end = HEIGHT;
		draw_stripe(walls[i], i, frame, world);
		i++;
	}
}

void	display_frame(t_info *info)
{
	t_frame	frame;
	t_wall	walls[WIDTH];
	int		i;

	frame.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel,
			&frame.line_length, &frame.endian);
	i = 0;
	while (i < WIDTH)
	{
		walls[i].texture = 'N';
		i++;
	}
	get_walls(info->player, info->world->map, walls);
	draw_frame(&frame, walls, info->world);
	mlx_put_image_to_window(info->mlx, info->mlx_win, frame.img, 0, 0);
	mlx_destroy_image(info->mlx, frame.img);
}
