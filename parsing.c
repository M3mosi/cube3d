
#include "cube_3d.h"


void		ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

char		*ft_realloc(char *str, int size)
{
	char *tmp;
	int len;
	if (!(tmp = malloc(size * sizeof(char))))
		return (0);
	if (str)
	{
		tmp = ft_strcpy(tmp, str);
		len = ft_strlen_int(tmp);
		tmp[len] = '\n';
		tmp[len + 1] = 0;
		free(str);
	}
	else
		ft_bzero(tmp, size);
	return (tmp);
}

void		take_r(char *s, t_info *var)
{
	int i;
	int k;
	int j;
	char appoggio[15];

	i = 0;
	k = 0;
	while (s[i])
	{
		while (is_space(s[i]) && s[i])
			i++;
		j = 0;
		while ((s[i] >= '0' && s[i] <= '9') && s[i])
		{
			appoggio[j] = s[i];
			i++;
			j++;
		} 
		appoggio[j] = 0;
		if (k < 2 && appoggio[0])
		{
			var->R[k] = ft_atoi(appoggio);
			k++;
		}
		i++;
	}
}

void		take_rgb(char *s, t_info *var, char c)
{
	int i;
	int j;
	int k;
	char *appoggio;

	i = 1;
	k = 0;
	if (!(appoggio = malloc(4)))
		return ;
	while (is_space(s[i]))
		i++;
	while (ft_isdigit(s[i]))
	{
		j = 0;
		while (ft_isdigit(s[i]))
		{
			appoggio[j] = s[i];
			i++;
			j++;
		}
		appoggio[j] = 0;
		if (c == 'F') 
			var->F[k]= ft_atoi(appoggio);
		if (c == 'C') 
			var->C[k]= ft_atoi(appoggio);
		k++;
		if (s[i + 1])
			i++;
	}
}

char		*take_path(char *s, t_info *var)
{
	int i;
	int j;
	char *appoggio;

	i = 2;
	if (!(appoggio = malloc(ft_strlen(s))))
		return (0);
	while (is_space(s[i]))
		i++;
	j = 0;
	while (!is_space(s[i]) && s[i] > 32)
	{
		appoggio[j] = s[i];
		i++;
		j++;
	} 
	appoggio[j] = 0;
	appoggio = alloc(appoggio, 1);
	return (appoggio);
}

int		find_value(char *line, t_info *var)
{
	char	*out;
	int		r;

	r = 0;
	if ((out = ft_strnstr(line, "R", ft_strlen(line))) && out[0] == line[0])
	{
		if (var->R[0] == -1 && var->R[1] == -1)
			take_r(out, &(*var));
		else
			r = 1;
	}
	else if ((out = ft_strnstr(line, "NO", ft_strlen(line))) && out[0] == line[0])
	{
		if (!var->NO)
			var->NO = take_path(out, &(*var));
		else
			r = 1;
	}
	else if ((out = ft_strnstr(line, "SO", ft_strlen(line))) && out[0] == line[0])
	{
		if (!var->SO)
			var->SO = take_path(out, &(*var));
		else
			r = 1;
	}
	else if ((out = ft_strnstr(line, "WE", ft_strlen(line))) && out[0] == line[0])
	{
		if (!var->WE)
			var->WE = take_path(out, &(*var));
		else
			r = 1;
	}
	else if ((out = ft_strnstr(line, "EA", ft_strlen(line))) && out[0] == line[0])
	{
		if (!var->EA)
			var->EA = take_path(out, &(*var)); 
		else
			r = 1;
	}
	else if ((out = ft_strnstr(line, "S ", ft_strlen(line))) && out[0] == line[0])
	{
		if (!var->S)
			var->S = take_path(out, &(*var));
		else
			r = 1;
	}
	else if ((out = ft_strnstr(line, "F", ft_strlen(line))) && out[0] == line[0])
	{
		if (var->F[0] == -1 || var->F[1] == -1 || var->F[2] == -1)
			take_rgb(out, &(*var), 'F');
		else
			r = 1;
	}
	else if ((out = ft_strnstr(line, "C", ft_strlen(line))) && out[0] == line[0])
	{
		if (var->C[0] == -1 || var->C[1] == -1 || var->C[2] == -1)
			take_rgb(out, &(*var), 'C');
		else
			r = 1;
	}
	if (r)
		return (0);
	else
		return (1);
}

void		init_struct(t_info *var)
{
	var->R[0] = -1;
	var->R[1] = -1;
	var->C[0] = -1;
	var->C[1] = -1;
	var->C[2] = -1;
	var->F[0] = -1;
	var->F[1] = -1;
	var->F[2] = -1;
	var->NO = NULL;
	var->SO = NULL;
	var->WE = NULL;
	var->EA = NULL;
	var->S = NULL;
	if (!(var->error =(char **) malloc (20 * sizeof(char *))))
		return ;
	var->map = NULL;
	if (!(var->error = malloc(20 * sizeof(char *))))
		return;
	var->error[0] = ft_strdup("ERROR:\nNo map in .cub doc\n");
	var->error[1] = ft_strdup("ERROR:\ninvalid char for map\n");
	var->error[2] = ft_strdup("ERROR:\nmap is open or invalid\n");

}

int			check_if_map(t_info *var)
{
	if (var->R[0] > -1 && var->R[1] > -1 && var->NO
		&& var->SO && var->WE && var->EA && var->S && var->F[0] > -1 && var->C[0] > -1)
		return (1);
	return (0);
}

int			check_empty(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if (is_space(s[i]))
			i++;
		else if (s[i])
			return (1);
	}
	return (0);
}

int			check_valid_map(t_info *var)
{
	int i;
	int k;
	int arlen;

	i = 0;
	arlen = 0;
	while (var->map[arlen])
		arlen++;
	while (var->map[i])
	{
		k = 0;
		while (var->map[i][k])
		{
			if (var->map[i][k] == '0' || var->map[i][k] == '2' || var->map[i][k] == 'N' ||
				var->map[i][k] == 'W' || var->map[i][k] == 'E' || var->map[i][k] == 'S')
			{
				if (i != 0)
					if (is_space(var->map[i - 1][k]) || k > ft_strlen_int(var->map[i - 1]))
						return (0);
				if (is_space(var->map[i][k - 1]) || is_space(var->map[i][k + 1]))
					return (0);
				if ((k + 1) > (ft_strlen_int(var->map[i]) - 1) || k == 0)
					return (0);
				if (i != (arlen))
					if (is_space(var->map[i + 1][k]) || k > ft_strlen_int(var->map[i + 1]))
						return (0);
			}
			k++;
		}
		i++;
	}
	return (1);
}

int			check_line_content(char *line, t_info *var)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2' && !is_space(line[i]) &&
			line[i] != 'N' && line[i] != 'W' && line[i] != 'E' && line[i] != 'S')
		{
			ft_putstr(var->error[1]);
			return (0);
		}
		i++;
	}
	return (1);
}

void		read_map(int fd, t_info *var, char *line)
{
	int i;
	char *buf;

	i = 1;
	buf = 0;
	buf = ft_realloc(buf, ft_strlen_int(buf) + ft_strlen_int(line) + 1);
	if (!check_line_content(line, &(*var)))
		return ;
	ft_strlcat(buf, line, (ft_strlen_int(buf) + ft_strlen_int(line) + 1));
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		buf = ft_realloc(buf, ft_strlen_int(buf) + ft_strlen_int(line) + 1);
		if (!check_line_content(line, &(*var)))
		{
			free(buf);
			return ;
		}
		ft_strlcat(buf, line, (ft_strlen_int(buf) + ft_strlen_int(line) + 1));
	}
	var->map = ft_split(buf, '\n');
	if (buf)
		free(buf);
	if (!check_valid_map(&(*var)))
		ft_putstr(var->error[2]);
}

void		free_map(t_info *var)
{
	int i;

	i = 0;
	while (var->map[i])
	{
		if (var->map[i])
			free(var->map[i]);
		i++;
	}
	if (var->map)
		free(var->map);
}

void		free_error(t_info *var)
{
	int i;

	i = 0;
	while (i < 20)
	{
			if (var->error[i])
				free(var->error[i]);
		i++;
	}
	if (var->error)
		free(var->error);
}

void		free_struct(t_info *var)
{
	if (var->NO)
		free(var->NO);
	if (var->SO)
		free(var->SO);
	if (var->WE)
		free(var->WE);
	if (var->EA)
		free(var->EA);
	if (var->S)
		free(var->S);
	if (var->map)
		free_map(&(*var));
	if (var->error)
		free_error(&(*var));
}

int 		parsing(int fd, t_info *var)
{
	char *line;
	int i;
	int r;
	int sw;

	init_struct(&(*var));
	r = 1;
	sw = 0;
	while (r == 1)
	{
		r = get_next_line(fd, &line);
		if (!find_value(line, &(*var)) && sw == 0)
			if (check_empty(line))
				break;
		if (check_if_map(&(*var)) && check_empty(line) && sw == 1)
		{
			read_map(fd, &(*var), line);
			if (line)
				free(line);
			return (1);
		}
		if (check_if_map(&(*var)))
			sw = 1;
	}
	ft_putstr(var->error[0]);
	free_struct(&(*var));
	free(line);
	return (1);
}

int main()
{
	int fd;
	t_info var;
	char *line;

	fd = open("info.cub", O_RDONLY);
	parsing(fd, &var);
}