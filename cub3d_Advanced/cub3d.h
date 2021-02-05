/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:46:42 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/05 10:48:42 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# include "./libft/libft.h"

# define BUFFER_SIZE 1

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_var
{
	int				rx;
	int				ry;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				f[3];
	char			*fpat;
	int				c[3];
	char			*cpat;
}					t_var;

typedef struct		s_spawn
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	double			wallx;
	double			texpos;
	double			step;
	double			texx;
	double			texy;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				lr;
	int				fb;
	int				jump;
	int				appo;
	int				swjp;
	int				sprint;
	int				hit_sprite;
	double			movspeed;
	double			rotspeed;
}					t_spawn;

typedef struct		s_tex
{
	int				width;
	int				height;
	char			*buff;
}					t_tex;

typedef struct		s_hook
{
	t_spawn			*sp;
	t_var			var;
	char			**map;
	t_data			img;
	t_vars			vars;
	t_tex			*tex[5];
}					t_hook;

void				var_parsing(int fd, t_var *var);
char				**map_parsing(int fd);
void				insert_value(char *temp, t_var *var);
void				parse_value(char *line, char *reg, t_var *var);
void				parse_template_no(char *line, char *reg, t_var *var);
void				parse_template_so(char *line, char *reg, t_var *var);
void				parse_template_we(char *line, char *reg, t_var *var);
void				parse_template_ea(char *line, char *reg, t_var *var);
void				parse_template_s(char *line, char *reg, t_var *var);
void				parse_rgb_f(char *line, char *reg, t_var *var);
void				parse_rgb_c(char *line, char *reg, t_var *var);
int					is_digit_space(char *line, int i);
int					is_space(char *line, int i);
int					get_next_line(const int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
int					is_line(char *str);
size_t				ft_strlen(const char *s);
void				check_map(char **map);
int					valid_char_no_one(char c);
int					valid_char(char c);
int					is_char(char c);
int					manage_map(char **map);
void				format_rule_err(char *line, char *reg);
void				miss_rule_err(char *reg);
void				exist_rule_err(char *line, char *reg);
void				forb_rule_err(char *line, char *reg);
void				exist_file_err(void);
void				name_file_err(char *str);
void				invalid_map_err(char **map);
void				rendering(char **map, t_var var);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					create_trgb(int t, int r, int g, int b);
t_hook				hook_init(char **map, t_var var, t_spawn spawn,
								t_vars vars);
int					set_key(int keycode, t_hook *h);
void				init_spawn(char **map, t_spawn *sp);
int					raycasting(t_hook *h);
int					key_hook(int keycode);
void				print_background(t_var var, t_data img);

#endif
