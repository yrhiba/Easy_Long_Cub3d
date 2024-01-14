/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:03:35 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/14 04:04:08 by yrhiba           ###   ########.fr       */
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
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define UP_KEY 126
# define DOWN_KEY 125
/* KEYS MACROS */

/* GAME MACROS */
# define FPS 24
# define FRAME_MS_TIME (1000.0f / FPS)

# define MIN_MAP_WIDTH 5
# define MIN_MAP_HEIGHT 5

# define TILE_WIDTH 50
# define TILE_HEIGTH 50

# define FOV (60 * (M_PI / 180))

# define MINMAP_HEIGHT 14
# define MINMAP_WIDTH 24
# define MINMAP_FACTOR 0.3
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
	t_vector	minmap_pos;
	int			turn_direction; // -1 or 1 | left or right
	int			walk_direction; // -1 or 1 | backward or forward
	float		rotation_angle; // current angle
	int			walk_speed; // pixel per second
	float		turn_speed; // angle per second
 
} t_player;


typedef struct s_ray
{
	float		ray_angle;
	t_vector	wall_hit;
	float		distance;
	bool		was_hit_vertical;
	float		distance_wallv;
	bool		was_hit_horizantal;
	float		distance_wallh;
	bool		is_facing_up;
	bool		is_facing_down;
	bool		is_facing_left;
	bool		is_facing_right;

	/*cast-ray-vars-utils*/
	float		xintercept;
	float		yintercept;
	float		xstep;
	float		ystep;
	float		next_horz_touch_x;
	float		next_horz_touch_y;
	float		horz_wall_hit_x;
	float		horz_wall_hit_y;
	float		next_vert_touch_x;
	float		next_vert_touch_y;
	float		vert_wall_hit_x;
	float		vert_wall_hit_y;
	float		x_to_check;
	float		y_to_check;
	/*cast-ray-vars-utils*/

	/*project-wall-utils*/
	float		correct_wall_dis;
	float		wall_height;
	float		start_row;
	float		end_row;
	/*project-wall-utils*/

}	t_ray;

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

	/*rays-engine-information*/
	t_ray			rays[WIN_WIDTH];
	/*rays-engine-information*/

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

	/*engine-info*/
	int		frame_count;
	struct	timeval	stime;
	int		fps_counted;
	char	*fs;
	/*engine-info*/

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
			int color, t_vector width_height);
int		frame_render_line(t_frame *frame, t_vector pos1,
			t_vector pos2, int color);
/*frame-module*/

/*mlx-module*/
void	init_mlx(t_data *data);
/*mlx-module*/

/*mlx-events*/
int		keypressdown(int keycode, t_data *data);
int		keypressdup(int keycode, t_data *data);
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
void	update_player(t_data *data, float deltatime);
void	render_2dmap(t_data *data);
void	render_player_in2dmap(t_data *data);
void	render_2dallrays(t_data *data);
void	render_3d_projections(t_data *data);
void	reneder_minmap(t_data *data);
void	render_floor_cilling(t_data *data);
void	render_footer(t_data *data);
/*game-module*/

/*raycasting-module*/
void	cast_all_rays(t_data *data);
void	cast_ray(t_data *data, int	ray_id);
/*raycasting-module*/

/*utils*/
int		getcolor(int t, int r, int g, int b);
void	exit_failure(const char *errmsg);
bool	check_ext(char *file_name, char *ext);
void	my_string_free(void **string);
bool	is_valid_color(t_color *color);
void	set_directions(t_data *data);
void	free_directions(t_data *data);
bool	isplauyercolliedwithwall(t_data *data, t_vector player_pos);
float	normalize_angle(float angle);
bool	is_valid_map_pos(t_data *data, float x, float y);
float	distance_between_2points(float x1, float y1, float x2, float y2);
void	update_minmap(t_data *data);
/*utils*/

/*dumy-math*/
int		ft_max(int a, int b);
/*dumy-math*/

#endif
