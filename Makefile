SRCS_PATH = ./srcs/
HEADERS = ./includes/
LIBFT_HEADERS = ./libft/includes/

SRCS_FILES = cub3d_start.c \
			 draw_sprite.c \
			 draw_texture.c \
			 error.c \
			 ft_tools.c \
			 key_events.c \
			 main.c \
			 map_check.c \
			 map_parse.c \
			 map_set.c \
			 move_rotation.c \
			 move.c \
			 pos_dir_init.c \
			 raycasting.c \
			 sky_floor.c \
			 space_check.c \
			 sprite.c \
			 texture_init.c
			 
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)
BMP = screenshot.bmp
LIB = libft/libft.a
MLX_MAC =  -lmlx -framework OpenGL -framework AppKit
NAME = cub3D
CC = gcc
FLAGS = -Werror -Wall -Wextra -I $(HEADERS) -I $(LIBFT_HEADERS)

BSRCS_FILES = cub3d_start_bonus.c \
			 draw_sprite_bonus.c \
			 draw_texture_bonus.c \
			 error_bonus.c \
			 ft_tools_bonus.c \
			 key_events_bonus.c \
			 main_bonus.c \
			 map_check_bonus.c \
			 map_parse_bonus.c \
			 map_set_bonus.c \
			 move_rotation_bonus.c \
			 move_bonus.c \
			 pos_dir_init_bonus.c \
			 raycasting_bonus.c \
			 sky_floor_bonus.c \
			 space_check_bonus.c \
			 sprite_bonus.c \
			 texture_init_bonus.c

BSRC_PATH = ./bonus
BSRC = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
BOBJS = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB) $(MLX)
		$(CC) $(FLAGS) $(OBJS) $(MLX_MAC)  -o $(NAME) $(LIB)

bonus	: $(BOBJS) $(LIB) $(MLX)
		$(CC) $(FLAGS) $(BOBJS) $(MLX_MAC)  -o $(NAME) $(LIB)

$(LIB):
	make -j4 -C ./libft

$(MLX):
	make -j4 -C ./minilibx

clean:
	make fclean -C ./libft
	rm -f $(OBJS) $(BMP)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
