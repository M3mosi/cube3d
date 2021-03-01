/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:00:16 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/01 12:00:19 by sgiovo           ###   ########.fr       */
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
	int				swf;
	int				swc;
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
	int				sm;
	int				sw;
	int				jump;
	int				appo;
	int				swjp;
	int				shoot;
	int				sprint;
	int				displayminimap;
	int				hit_sprite;
	int				life;
	double			movspeed;
	double			rotspeed;
	double			*zbuff;
}					t_spawn;

typedef struct		s_spr
{
	double			spritex;
	double			spritey;
	double			invcam;
	double			transx;
	double			transy;
	int				screenx;
	int				sprheight;
	int				sprwidth;
	int				sprdrawstartx;
	int				sprdrawstarty;
	int				sprdrawendx;
	int				sprdrawendy;
	int				stripe;
	int				texx;
	int				texy;
}					t_spr;

typedef struct		s_tex
{
	int				width;
	int				height;
	char			*buff;
}					t_tex;

typedef	struct		s_sprite
{
	double			x;
	double			y;
	double			movex;
	double			movey;
	int				life;
	int				k;
}					t_sprite;

typedef	struct		s_floceal
{
	float			raydirxa;
	float			raydirya;
	float			raydirxb;
	float			raydiryb;
	int				p;
	float			posz;
	float			rowdistance;
	float			floorstepx;
	float			floorstepy;
	float			floorx;
	float			floory;
	unsigned int	color;
	int				cbpatt;
	int				floortex;
	int				ceiltex;
}					t_floceal;

typedef struct		s_hook
{
	t_spawn			*sp;
	t_spr			*spr;
	t_sprite		**sprite;
	t_var			var;
	char			**map;
	t_data			img;
	t_vars			vars;
	t_tex			*tex[15];
	char			**minimap;
	t_floceal		*floceal;
	int				level;
	int				nsprite;
	int				s_instampa;
}					t_hook;

int					ar_length(char **map);
void				printmap(t_hook *h);
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
void				floceal_err(char *reg);
void				invalid_map_err(char **map);
void				rendering(char **map, t_var var, int sw);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					create_trgb(int t, int r, int g, int b);
t_hook				hook_init(char **map, t_var var, t_spawn spawn,
								t_vars vars);
int					set_key(int keycode, t_hook *h);
t_sprite			**init_spawn(char **map, t_spawn *sp, t_sprite **s);
int					raycasting(t_hook *h);
void				draw_dot(t_hook *h, int x, int y, int color);
int					getcolor(t_tex *tex, int x, int y, int fade);
int					key_hook(int keycode);
void				sprite_calc(t_hook *h);
void				pwd_calc(t_spawn *sp);
void				height_calc(t_spawn *sp, t_var var);
void				set_speed(t_spawn *sp);
void				print_wall(t_hook *h, int x);
void				ray_calc(t_spawn *sp, t_var var, int x);
void				var_dda(t_spawn *sp);
void				dda(t_spawn *sp, char **map);
void				tex_coord(t_spawn *sp, t_var var);
int					print_stripe(t_hook *h, int d, int y, int c);
void				print_sprite(t_hook *h);
void				set_dir(t_spawn *sp, char c);
void				movement_sprite(t_hook *h);
void				screenshot(t_data img, t_var var, t_hook *h);
void				print_floor(t_hook *h);
void				shoot(t_hook *h);
void				gunprinter(t_hook *h);
void				set_floceal(t_hook *h, int y);
void				set_floceal2(t_floceal *fl, int cellx, int celly);
void				guny(t_spawn *sp);
void				gunx(t_spawn *sp);
int					set_key_render(t_hook *h);
int					check_mov(char c);
int					unset_key(int keycode, t_hook *h);
int					set_key(int keycode, t_hook *h);
void				sprite_var(t_hook *h, int i, int *spr_ord);
void				manage_sprite(t_hook *h, int i, int *spr_ord);
void				random_gen(double *movex, double *movey);
void				set_move1(double *movex, double *movey);
void				set_move2(double *movex, double *movey);
void				set_move3(double *movex, double *movey);
void				set_move4(double *movex, double *movey);
void				next_level(t_hook *h);
int					count_sprite(char **map);
int					ar_length(char **map);
char				**minimap_init(char **minimap, char **map);
void				set_text(t_hook *h, t_var var, t_vars vars);
void				buff_free(unsigned int **buff, int y);
void				slitta_array(t_hook *h, int i);
void				elimina_morte(t_hook *h);
void				free_sprite(t_hook *h);
void				mirino(t_hook *h);
void				print_life(t_hook *h);
void				set_life_sprite(t_hook *h, int i);
int					resizer(t_hook *h, int mod);
int					print_gameover(t_hook *h);
void				print_level(t_hook *h);
void				parse_f(char *line, char *reg, t_var **var);
void				parse_c(char *line, char *reg, t_var **var);
unsigned int		**buff_alloc(int x, int y);
void				print_flrgb(t_hook *h);
void				insert_rgb_c(char *temp, t_var *var);
int					is_comma(char c, int i, char *line, char *reg);
void				insert_rgb_f(char *temp, t_var *var);
void				parse_rgb_c(char *line, char *reg, t_var *var);
void				extension_err(char *line, char *reg);
int					valid_char2(char c);
void				file_err(void);
void				free_all(t_hook *h);
void				free_tex(t_hook *h);
void				free_sc(t_hook *h);
int					close_win();

#endif
