# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 00:12:42 by yrhiba            #+#    #+#              #
#    Updated: 2024/01/12 00:46:17 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	main.c \
		0-data-module/init_data.c \
		0-data-module/clear_data.c \
		1-frame-module/frame_pixel_put.c \
		1-frame-module/frame_fill_with_color.c \
		1-frame-module/frame_update.c \
		2-mlx-module/init_mlx.c \
		2-mlx-module/events/keypressdown.c \
		2-mlx-module/events/redcrosspressed.c \
		3-parsing-module/do_parsing.c \
		3-parsing-module/read_file_content.c \
		3-parsing-module/clear_parsing_data.c \
		A-utils/getcolor.c \
		A-utils/exit_failure.c \
		A-utils/check_ext.c \
		A-utils/my_string_free.c

INC =	header.h

LIBS =	B-libs/libft/libft.a \
		B-libs/libgetnextline/libgetnextline.a \
		B-libs/libmylist/libmylist.a \
		B-libs/libmystr/libmystr.a

OBJS_INCS = -I. \
			-I B-libs/libft \
			-I B-libs/libgetnextline \
			-I B-libs/libmylist \
			-I B-libs/libmystr

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra

MLX_DEPENDS = -lm -lmlx -framework OpenGL -framework AppKit

all :
	make make_libs
	make $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(MLX_DEPENDS) $(OBJS) $(LIBS) -o $(NAME)

%.o : %.c $(INC)
	$(CC) $(FLAGS) $(OBJS_INCS) -c $< -o $@

clean : clean_libs
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

make_libs:
	make -C B-libs/libft
	make -C B-libs/libgetnextline
	make -C B-libs/libmylist
	make -C B-libs/libmystr

clean_libs:
	make fclean -C B-libs/libft
	make fclean -C B-libs/libgetnextline
	make fclean -C B-libs/libmylist
	make fclean -C B-libs/libmystr

.PHONY : all clean fclean re make_libs clean_libs
