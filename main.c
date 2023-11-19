/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:16:10 by lray              #+#    #+#             */
/*   Updated: 2023/11/17 19:32:43 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/mlx-testing.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	t_image	*img;
	t_image	*img2;
	int		x = 0;
	int		y = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	img = img_create(mlx, WIN_WIDTH, WIN_HEIGHT);
	img2 = img_create(mlx, 32, 32);
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			put_pixel(img, x, y, 0x00FF00);
			++x;
		}
		++y;
	}
	x = 0;
	y = 0;
	while (y < img2->height)
	{
		x = 0;
		while (x < img2->width)
		{
			put_pixel(img2, x, y, 0xFF);
			++x;
		}
		++y;
	}
	put_img_to_img(img, img2, 0, 0);
	put_img_to_img(img, img2, img->width - img2->width, 0);
	put_img_to_img(img, img2, 0, img->height - img2->height);
	put_img_to_img(img, img2, img->width - img2->width, img->height - img2->height);

	put_img_to_img(img, img2, img->width / 2 - img2->width / 2, img->height / 2 - img2->height / 2);

	mlx_put_image_to_window(mlx, win, img->data, 0, 0);
	mlx_loop(mlx);
	return (0);
}
