/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:01:58 by vrossi            #+#    #+#             */
/*   Updated: 2019/09/18 10:55:20 by vrossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define HEIGHT	600
# define WIDTH	800

typedef struct	s_pixel
{
	int			x;
	int			y;
}				t_pixel;



typedef struct	s_env
{	
	void		*mlx;
	void		*win;
	void		*pt_img;
	char		*my_img;
	int			color;

	int			x;
	int			y;
	int			i;
	double		cr;
	double		ci;
	double		pr;
	double		pi;
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	double		zoom;
	double		moveX;
	double		moveY;
	int			maxIterations;
	char		*arg;
	int			click;

}				t_env; 

void			ft_fill_pix(t_env *e, int x, int y);
void			init_var(t_env *e);
int				key_press(int k, t_env *e);
int				mouse_move(int x, int y, t_env *e);
int				mouse_release(int k, int x, int y, t_env *e);


void			julia(t_env *e);
void			mandelbrot(t_env *e);
void			celtic_mandelbrot(t_env *e);
void			burning_ship(t_env *e);

#endif
