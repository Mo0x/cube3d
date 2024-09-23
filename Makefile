NAME = cub3d
CC = gcc
SRCS = ./srcs/main.c  \
		./srcs/parsing/parsing.c \
		./srcs/parsing/parse_utils.c \
		./srcs/parsing/parsing_get_color_and_texture.c \
		./srcs/parsing/texture_check.c \
		./srcs/parsing/rgb_road.c \
		./srcs/parsing/parse_map.c \
		./srcs/parsing/map_array.c \
		./srcs/parsing/validate_rows.c \
		./srcs/parsing/array_utils.c \
		./srcs/parsing/map_check.c \
		./srcs/parsing/map_enclosure_check.c \
		./srcs/error/error.c \
		./srcs/game/init.c \
		./srcs/game/render.c \
		./srcs/game/raycast.c \
		./srcs/game/draw_wall.c \
		./srcs/utils/mlx_utils.c \
		./srcs/player/player_move.c \
		./srcs/player/player_look.c \
		./srcs/minimap/minimap.c \
		./srcs/sprite/sprite.c \
		./srcs/texture/texture.c \
		./srcs/sprite/doors.c

OBJS = $(patsubst %.c, %.o, $(SRCS))
INCDIRS = ./includes
CFLAGS = -g -Wall -Wextra -Werror -I$(INCDIRS) -I$(MLX)/include -g3
MLX = ./MLX42

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft/
	mv ./libft/libft.a .
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L. -lft -L$(MLX)/build -lmlx42 -lglfw -lm

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	make clean -C ./libft/
	rm -rf $(MLX)/build
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) libft.a

re : fclean all

.PHONY : all bonus clean fclean re
