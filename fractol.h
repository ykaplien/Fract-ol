/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <ykaplien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 13:14:11 by ykaplien          #+#    #+#             */
/*   Updated: 2018/09/19 14:08:31 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_X 900
# define WIN_Y 900

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>

typedef struct 	s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*window;
	void		*img_ptr;
	int			*image;
	int			bpp;
	int			size_line;
	int			endian;
}				t_fractol;

void	error(int a);

#endif
