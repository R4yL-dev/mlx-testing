/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-testing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:42:19 by lray              #+#    #+#             */
/*   Updated: 2023/11/17 19:29:44 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TESTING_H
#define MLX_TESTING_H

#include "mlx.h"
#include "structures.h"

#include <stdlib.h>
#include <stdio.h>

#define WIN_NAME	"TEST"
#define WIN_WIDTH	800
#define WIN_HEIGHT	640
#define IMG_HEIGTH	320
#define	IMG_WIDTH	320

t_image	*img_create(void *mlx, int width, int height);
void	put_pixel(t_image *img, int x, int y, int color);
int		get_pixel(t_image *img, int x, int y);
void	put_img_to_img(t_image *dst, t_image *src, int x, int y);

#endif
