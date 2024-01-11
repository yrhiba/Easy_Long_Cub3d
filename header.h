/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:03:35 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/11 22:48:43 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>
# include <math.h>
# include <sys/time.h>
# include <mlx.h>

# include "libft.h"
# include "libmystr.h"
# include "my_list.h"
# include "get_next_line.h"

/* WINDOW MACROS */
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
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

typedef struct s_player
{
	float	x;
	float	y;

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

}	t_data;

/* data-module */
void	init_data(t_data **data);
void	clear_data(t_data **data);
/* data-module */

/*frame-module*/
void	frame_pixel_put(t_frame *frame, int x, int y, int color);
int		frame_fill_with_color(t_frame *frame, int color);
int		frame_update(t_data *data);
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
/*parsing-module*/

/*utils*/
int		getcolor(int t, int r, int g, int b);
void	exit_failure(const char *errmsg);
bool	check_ext(char *file_name, char *ext);
/*utils*/

#endif
