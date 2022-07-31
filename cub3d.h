/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:48:06 by alee              #+#    #+#             */
/*   Updated: 2022/08/01 02:17:25 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#define DEBUG 0

# define PI				3.141592
# define ONE_TO_RAD		0.017453

# define WIN_WIDTH		960
# define WIN_HEIGHT		540
# define WIN_FOV		120
# define WIN_DISTANCE	2

# define MINIMAP_VER	2
# define MINIMAP_WIDTH	10
# define MINIMAP_HEIGHT	7
# define MINIMAP_XPOS	100
# define MINIMAP_YPOS	10
# define MINIMAP_TILESZ	30

# define PLAYER_SPEED	10

typedef enum e_asset
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	ASSET_MAX = 4,
}			t_asset;

typedef enum e_parse
{
	PARSE_MIN_LINE = 6,
	PARSE_ERROR = -1,
	PARSE_NONE = 0,
	PARSE_NORTH = 1,
	PARSE_SOUTH = 2,
	PARSE_WEST = 4,
	PARSE_EAST = 8,
	PARSE_FLOOR = 16,
	PARSE_CEIL = 32,
	PARSE_FINISH = 63,
}			t_parse;

typedef struct s_img
{
	void			*img;
	char			*addr;
	unsigned int	width;
	unsigned int	height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
}				t_mlx;

typedef struct s_xpm
{
	void	*img;
	int		width;
	int		height;
}				t_xpm;

typedef struct s_parse_data
{
	char	*asset_file[ASSET_MAX];
	int		c_color;
	int		f_color;
}				t_parse_data;

typedef struct s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct s_player_data
{
	t_pos	pos;
	double	radian;
}				t_player_data;

typedef struct s_content_data
{
	char	**content_ptr;
	int		content_idx;
	int		content_len;
	int		content_line;
	int		player_cnt;
}				t_content_data;

typedef struct s_minimap
{
	t_img			img;
	unsigned int	width;
	unsigned int	height;
	unsigned int	pos[2];
	unsigned int	tile_size;
}				t_minimap;

typedef struct s_cub3d
{
	t_mlx			mlx;
	t_parse_data	parse_data;
	unsigned char	parse_flag;
	int				file_line;
	char			**file_ptr;
	t_content_data	content_data;
	t_player_data	player;
	t_minimap		minimap;
	t_xpm			xpm_data[ASSET_MAX];
	char			key_pressed[256];
}				t_cub3d;

void	init_data(int argc, char* argv[], t_cub3d *p_data);
void	close_data(t_cub3d *p_data);

#endif
