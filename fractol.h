/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 13:14:11 by ykaplien          #+#    #+#             */
/*   Updated: 2018/09/25 17:28:40 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_X 1000
# define WIN_Y 1000

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_fr
{
	double cRe;
	double cIm;
	double newRe;
	double newIm;
	double oldRe;
	double oldIm;
	double zoom;
	double moveX;
	double moveY;
	int maxIterations;
	int y;
	int x;
	int i;	
}				t_fr;

typedef struct 	s_fractol
{
	t_fr		j;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*window;
	void		*img_ptr;
	int			*image;
	int 		fractol;
	
}				t_fractol;

void		error(int a);
void		initiate(t_fractol *fr);
int			event_handle(int key, t_fractol *fr);
void		putpixel(t_fractol *fr, int x, int y, int color);
void		julia(t_fractol *fr);
void		mandelbrot(t_fractol *fr);
void		tricorn(t_fractol *fr);
void		julia2(t_fractol *fr);
void		mandelbrot2(t_fractol *fr);
void		tricorn2(t_fractol *fr);
int			zoom_mouse(int key,  int x, int y, t_fractol *fr);
int			mouse_j(int x, int y, t_fractol *fr);


#endif
