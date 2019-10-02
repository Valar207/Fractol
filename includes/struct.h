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
# define H	600
# define W	1000

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*pt_img;
	char		*my_img;
	int			color;
	int			chgcol;
	int			x;
	int			y;
	int			i;
	double		cr;
	double		ci;
	double		pr;
	double		pi;
	double		nr;
	double		ni;
	double		or;
	double		oi;
	double		zoom;
	double		mx;
	double		my;
	int			maxit;
	char		*arg;
	int			click;
	int			sw;

}				t_env;

void			ft_fill_pix(t_env *e, int x, int y);
void			init_var(t_env *e);
void			mlx_cmd(t_env *e);
int				key_press(int k, t_env *e);
int				mouse_move(int x, int y, t_env *e);
int				mouse_release(int k, int x, int y, t_env *e);
int				mouse_press(int k, int x, int y, t_env *e);
void			zoom_mouse(t_coord *c, t_env *e);
void			move_zoom_iteration(int k, t_env *e);
void			change_fract(int k, t_env *e);
void			change_fract_bis(int k, t_env *e);
void			color(t_env *e);
void			user_interface_texts(t_env *e);
void			julia(t_env *e);
void			mandelbrot(t_env *e);
void			celtic_mandelbrot(t_env *e);
void			burning_ship(t_env *e);
void			mandelbar(t_env *e);
void			mandelbar_bis(t_env *e);

#endif
