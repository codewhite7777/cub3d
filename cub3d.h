/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:10:32 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 16:26:28 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define DEBUG 1
# define PI 3.14159265359
# include "parse/parse_data.h"
# include "mlx_utils/xpm_loader.h"
# include "ft_utils/ft_pos.h"

//윈도우 사이즈
typedef enum e_window
{
	WIN_WIDTH = 960,
	WIN_HEIGHT = 540,
}			t_window;

//맵 데이터 내용
typedef struct s_content_data
{
	char	**content_ptr;
	int		content_idx;
	int		content_len;
	int		content_line;
	int		player_cnt;
}				t_content_data;

//파싱 데이터
typedef struct s_parse_data
{
	char	*asset_file[ASSET_MAX];
	int		c_color;
	int		f_color;
}				t_parse_data;

//윈도우 이미지 버퍼
typedef struct s_img
{
	void	*img;
	int		*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img		img;
}				t_mlx;

//플레이어
typedef struct s_player_data
{
	t_pos	pos;
	t_pos	dir;
	t_pos	plane;
	double	radian;
	double	move_speed;
	double	rotate_speed;

	t_pos	ray_dir;
	t_pos	side_dist;
	t_pos	delta_dist;
}				t_player_data;

typedef struct s_cub3d
{
	//map file
	int				file_line;
	char			**file_ptr;

	//parse data
	unsigned char	parse_flag;
	t_content_data	content_data;
	t_parse_data	parse_data;

	//mlx
	t_mlx			mlx;

	//xpm data
	t_xpm			xpm_data[ASSET_MAX];

	//key event
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_esc;

	//player
	t_player_data	player;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				side;
}				t_cub3d;

void	init_cub3d(int argc, char *argv[], t_cub3d *p_data);
void	close_cub3d(t_cub3d *p_data);

#endif
