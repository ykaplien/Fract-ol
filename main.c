/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 13:11:34 by ykaplien          #+#    #+#             */
/*   Updated: 2018/09/19 14:08:40 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_fractol	*fr;
	if (argc == 2)
	{
		if (!(ft_strcmp(argv[1], "mandelbrot")))
			printf("mandelbrot\n");
		else if (!(ft_strcmp(argv[1], "julia")))
			printf("julia\n");
		else
			error(2);
	}
	else
		error(1);
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

void	initiate(t_fractol *fr)
{
	fr = (t_fractol*)ft_memalloc(sizeof(t_fractol));
	fr->mlx_ptr = mlx_init();
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, WIN_X, WIN_Y, "YKAPLIEN'S FRACTOL'CHIK");
	fr->img_ptr = mlx_new_image(fr->mlx_ptr, WIN_X, WIN_Y);
	fr->image = (int *)mlx_get_data_addr (fr->img_ptr, &fr->bpp, &fr->size_line, &fr->endian);
	mlx_hook(fr->win_ptr, 2, 5, event_handle, fr);
	mlx_loop(fr->mlx_ptr);
}

void	event_handle(int key)
{

}

int		position(t_fractol *fr, int x, int y)
{
	int 	position;

	position = x + (y * fr->size_line);
	return(position);
}

// void	mandelbrot()
// {

// }

// void	julia()
// {

// }

// void	event_handle(t_fractol *fr)
// {

// }