#ifndef PARSER_H
# define PARSER_H

/*PARSER*/
int			check_file(char *str);

int			pars_file(t_minirt *data, char *str);

int			str_is_white_space(char *str);

t_color		*get_color(char *str);

size_t		arr_size(char **arr);

int			pars_line(t_minirt *data, char *str);

int			pars_ambient_light(t_minirt *data, char **arr);

t_point		*get_point(char *str);

#endif