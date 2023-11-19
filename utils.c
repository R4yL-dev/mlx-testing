/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:18:41 by lray              #+#    #+#             */
/*   Updated: 2023/11/17 19:27:11 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/mlx-testing.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	get_pixel(t_image *img, int x, int y)
{
	char	*src;

	src = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int*)src);
}

void	put_img_to_img(t_image *dst, t_image *src, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < src->height && (i + y) < dst->height)
	{
		j = 0;
		while (j < src->width && (j + x) < dst->width)
		{
			color = get_pixel(src, j, i);
			put_pixel(dst, j + x, i + y, color);
			++j;
		}
		++i;
	}
}
