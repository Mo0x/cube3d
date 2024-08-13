NAME = cub3d
CC = gcc
SRCS = ./srcs/main.c  \
		./srcs/parsing/parsing.c \
		./srcs/parsing/parse_utils.c \
		./srcs/parsing/parsing_get_color_and_texture.c \
		./srcs/parsing/texture_check.c \
		./srcs/parsing/rgb_road.c \
		./srcs/error/error.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCDIRS = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCDIRS) -I$(MLX)/include -g3
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
