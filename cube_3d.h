#ifndef FT_CUBE_3D_H
# define FT_CUBE_3D_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_info{
	int		R[2];
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	char	*S;
	int		F[3];
	int		C[3];
	char	**map;
	char	**error;
}				t_info;


void			ft_putstr(char *s);
char			*ft_realloc(char *str, int size);
void			take_r(char *s, t_info *var);
void			take_rgb(char *s, t_info *var, char c);
char			*take_path(char *s, t_info *var);
int				find_value(char *line, t_info *var);
void			init_struct(t_info *var);
int				check_if_map(t_info *var);
int				check_empty(char *s);
int				ft_strlen_b(const char *str);
int				check_valid_map(t_info *var);
int				check_line_content(char *line, t_info *var);
void			read_map(int fd, t_info *var, char *line);
int 			parsing(int fd, t_info *var);

#endif