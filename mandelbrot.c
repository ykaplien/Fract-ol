/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:19:51 by ykaplien          #+#    #+#             */
/*   Updated: 2018/09/25 17:02:15 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot2(t_fractol *fr)
{
	fr->j.zoom = 1;
	fr->j.moveX = -0.5;
	fr->j.moveY = 0;
	fr->j.maxIterations = 100;
	fr->j.y = 0;
}

void	mandelbrot3(t_fractol *fr)
{
	fr->j.oldRe = fr->j.newRe;
	fr->j.oldIm = fr->j.newIm;
	fr->j.newRe = fr->j.oldRe * fr->j.oldRe - fr->j.oldIm * fr->j.oldIm + fr->j.cRe;
	fr->j.newIm = 2 * fr->j.oldRe * fr->j.oldIm + fr->j.cIm;
}

void	mandelbrot(t_fractol *fr)
{
	fr->j.y = 0;
	while (fr->j.y < WIN_Y)
	{
		fr->j.x = 0;
		while (fr->j.x < WIN_X)
		{
			fr->j.cRe = 1.5 * (fr->j.x - WIN_X / 2) / (0.5 * fr->j.zoom * WIN_X) + fr->j.moveX;
			fr->j.cIm = (fr->j.y - WIN_Y / 2) / (0.5 * fr->j.zoom * WIN_Y) + fr->j.moveY;
			fr->j.newRe = fr->j.newIm = fr->j.oldRe = fr->j.oldIm = 0;
			fr->j.i = 0;
			while (fr->j.i < fr->j.maxIterations)
			{
				mandelbrot3(fr);
				if((fr->j.newRe * fr->j.newRe + fr->j.newIm * fr->j.newIm) > 4)
					break;
				fr->j.i++;
			}
		 
			fr->image[fr->j.x + (fr->j.y * WIN_X)] = fr->j.i * 42;
			fr->j.x++;
		}
		fr->j.y++;
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
}