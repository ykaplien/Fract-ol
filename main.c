/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 13:11:34 by ykaplien          #+#    #+#             */
/*   Updated: 2018/09/25 17:31:02 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_fractol	*fr;
	t_fr 		j; 

	if (argc == 2)
	{
		fr = (t_fractol*)ft_memalloc(sizeof(t_fractol));
		if (!(ft_strcmp(argv[1], "mandelbrot")))
		{
			initiate(fr);
			fr->fractol = 1;
			mandelbrot2(fr);
			mandelbrot(fr);
		}
		else if (!(ft_strcmp(argv[1], "julia")))
		{
			initiate(fr);
			fr->fractol = 2;
			julia2(fr);
			julia(fr);
		}
		else if (!(ft_strcmp(argv[1], "tricorn")))
		{
			initiate(fr);
			fr->fractol = 3;
			tricorn2(fr);
			tricorn(fr);
		}
		else
			error(2);
	}
	else
		error(1);
	// mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
	mlx_hook(fr->win_ptr, 2, 5, event_handle, fr);
	mlx_loop(fr->mlx_ptr);
	return (0);
}

void	error(int a)
{
	if (a == 1)
	{
		ft_putendl("usage: ./fractol map_name");
		exit(0);
	}
	else
	{
		ft_putendl("Invalid map name\nChoose one from: mandelbrot / julia");
		exit(0);
	}
}

void	initiate(t_fractol *fractol)
{
	int			bpp;
	int			size_line;
	int			endian;

	bpp = 32;
	size_line = WIN_X;
	endian = 0;
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIN_X, WIN_Y, "YKAPLIEN'S FRACTOL'CHIK");
	fractol->img_ptr = mlx_new_image(fractol->mlx_ptr, WIN_X, WIN_Y);
	fractol->image = (int *)mlx_get_data_addr(fractol->img_ptr, &bpp, &size_line, &endian);
	mlx_hook(fractol->win_ptr, 6, 0, mouse_j, fractol);
	mlx_mouse_hook(fractol->win_ptr, zoom_mouse, fractol);
}

int		zoom_mouse(int key,  int x, int y, t_fractol *fr)
{
	if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y)
	{
		if (key == 4 && fr->j.zoom >= 0.000001)
			fr->j.zoom *= 1.25;
		else if (key == 5)
			fr->j.zoom /= 1.25;
	}
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	if (fr->fractol == 1)
		mandelbrot(fr);
	else if (fr->fractol == 2)
		julia(fr);
	else if (fr->fractol == 3)
		tricorn(fr);
	return (0);
}

int			mouse_j(int x, int y, t_fractol *fr)
{
	if (fr->fractol == 1)
	{
		fr->j.cRe = (x - 300) / 128.0;
		fr->j.cIm = (y - 300) / 128.0;
		mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
		julia(fr);
	}
	return (0);
}

int		event_handle(int key, t_fractol *fr)
{
	printf("KEY = %d\n", key);
	if (key == 78 && fr->j.zoom >= 0.000001)
		fr->j.zoom /= 1.25;
	else if (key == 69)
		fr->j.zoom *= 1.25;
	else if (key == 125)
		fr->j.moveY += 0.1;
	else if (key == 126)
		fr->j.moveY -= 0.1;
	else if (key == 124)
		fr->j.moveX += 0.1;
	else if (key == 123)
		fr->j.moveX -= 0.1;
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	if (fr->fractol == 1)
		mandelbrot(fr);
	else if (fr->fractol == 2)
		julia(fr);
	else if (fr->fractol == 3)
		tricorn(fr);
	return (0);
}
