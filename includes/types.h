
#ifndef TYPES_H
# define TYPES_H

typedef struct s_map
{
	char	*line;
	char	*n_path;
	char	*s_path;
	char	*w_path;
	char	*e_path;
	char	*ccolor;
	char	*fcolor;
	int		fd;
}			t_map;

/*
typedef struct s_img
{

}				t_img;
*/

typedef struct s_data
{
	t_map	*map;
}				t_data;

#endif
