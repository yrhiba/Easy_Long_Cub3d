/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:03:35 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 08:32:48 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/* DEDUG ON/OFF */
# define DEBUG 1
/* DEDUG ON/OFF */

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>
# include <math.h>
# include <sys/time.h>
# include <fcntl.h>
# include <mlx.h>

# include "libft.h"
# include "libmystr.h"
# include "my_list.h"
# include "get_next_line.h"

/* WINDOW MACROS */
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define FOOTER_HEIGHT 0
# define WIN_TITLE "Easy-long-cub3d"
/* WINDOW MACROS */

/* EVENTS MACROS */
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17
/* EVENTS MACROS */

/* KEYS MACROS */
# define ESC_KEY 53
/* KEYS MACROS */

/* GAME MACROS */
# define FPS 30
# define FRAME_MS_TIME (1000.0f / FPS)

# define MIN_MAP_WIDTH 5
# define MIN_MAP_HEIGHT 5

# define TILE_WIDTH 50
# define TILE_HEIGTH 50

# define FOV (60 * (M_PI / 180))

/* GAME MACROS */

typedef struct	s_frame
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_frame;

typedef struct s_textures
{
	char		*no_file_path;
	char		*so_file_path;
	char		*we_file_path;
	char		*ea_file_path;

}				t_textures;

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;

}				t_color;

typedef struct s_vector
{
	int	x;
	int	y;

}	t_vector;

typedef struct s_player
{
	t_vector	pos;
	int			turn_direction; // -1 or 1 | left or right
	int			walk_direction; // -1 or 1 | backward or forward
	float		rotation_angle; // current angle
	int			walk_speed; // pixel per second
	float		turn_speed; // angle per second
 
} t_player;


typedef struct s_data
{
	void		*mlx;
	void		*win;

	t_frame			*frame;
	struct timeval	lastframetime;

	char		**map;
	char		**mini_map;
	int			map_width;
	int			map_height;

	t_player	*player;

	t_textures		textures;
	t_color			floor_color;
	t_color			ceiling_color;

	/*parsing-information*/
	t_my_list		*map_file_lines;
	t_my_list		*map_only_lines;
	bool			ceiling_color_given;
	bool			floor_color_given;
	int				player_count;
	int				zero_count;
	int				one_count;
	int				*dr;
	int				*dc;
	/*parsing-information*/

}	t_data;

/* data-module */
void	init_data(t_data **data);
void	clear_data(t_data **data);
/* data-module */

/*frame-module*/
void	frame_pixel_put(t_frame *frame, int x, int y, int color);
int		frame_fill_with_color(t_frame *frame, int color);
int		frame_update(t_data *data);
int		frame_render_rect(t_frame *frame, t_vector pos,
			int color, int width, int height);
int		frame_render_line(t_frame *frame, t_vector pos1,
			t_vector pos2, int color);
/*frame-module*/

/*mlx-module*/
void	init_mlx(t_data *data);
/*mlx-module*/

/*mlx-events*/
int		keypressdown(int keycode, t_data *data);
int		redcrosspressed(t_data *data);
/*mlx-events*/

/*parsing-module*/
void	do_parsing(t_data *data, int ac, char **av);
bool	read_file_content(t_data *data, char *file_path);
void	check_line(t_data *data, char *line, bool *map_found);
void	clear_parsing_data(t_data *data);
void	construct_map(t_data *data);
void	check_for_map(t_data *data);
void	set_player_data(t_data *data, int y, int x);
/*parsing-module*/

/*game-module*/
void	render_2dmap(t_data *data);
/*game-module*/


/*utils*/
int		getcolor(int t, int r, int g, int b);
void	exit_failure(const char *errmsg);
bool	check_ext(char *file_name, char *ext);
void	my_string_free(void **string);
bool	is_valid_color(t_color *color);
void	set_directions(t_data *data);
void	free_directions(t_data *data);
/*utils*/

/*dumy-math*/
int		ft_max(int a, int b);
/*dumy-math*/

#endif
