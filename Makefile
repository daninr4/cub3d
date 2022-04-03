# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 22:12:25 by jcarrete          #+#    #+#              #
#    Updated: 2021/04/25 13:34:12 by jcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -g

UNAME = $(shell uname -s)
AR = ar rcs
RM = rm -rf

#################### Directories ####################

LDIR = lib
LMLXDIR = libmlx
LIBMLX_A = libmlx.a
LIBFT = libft
LIBFT_A = libft.a
HDIR = include
SDIR = src
ODIR = obj

HBDIR = include_bonus -I$(HOME)/.brew/Cellar/sdl2/2.0.12_1/include -I./ssdl2/include -I/usr/include/SDL2
SBDIR = src_bonus
OBDIR = obj_bonus

ifeq ($(UNAME), Linux)
	LIBS = -lXext -lX11 -lm
	MLXDIR = minilibx-linux
endif
ifeq ($(UNAME), Darwin)
	LIBS = -lz -framework OpenGL -framework AppKit -lm
	MLXDIR = minilibx-darwin
	DLIBMLX = libmlx.dylib
endif

#################### Files for cub3D ####################

FILES = main/exit \
	main/i_main \
	main/ii_init_structs \
	main/iii_init_window \
	game_loop/i_game_loop \
	game_loop/ii_key_use \
	game_loop/iii_process_input \
	game_loop/iv_render_textures \
	game_loop/v_render_sprites \
	game_loop/vi_draw_sprite \
	game_loop/digital_diferential_analysis \
	scene_description/i_read_file \
	scene_description/ii_set_description \
	scene_description/iii_generate_map \
	scene_description/iv_check_map \
	scene_description/v_load_player \
	scene_description/vi_floodfill_check \
	scene_description/utils_check \
	scene_description/utils_description \
	scene_description/utils_map \
	scene_description/utils_floodfill \
	scene_description/utils_floodfill_sides \
	utils/check_str \
	utils/maths \
	utils/mlx_colors \
	utils/mlx_draw_geometry \
	utils/mlx_draw_line \
	utils/mlx_image_to_bmp \
	utils/mlx_pixel \
	utils/points \

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

FILES_B = src_bonus/main/exit \
	src_bonus/main/i_main \
	src_bonus/main/ii_init_structs \
	src_bonus/main/iii_init_window \
	src_bonus/game_loop/i_game_loop \
	src_bonus/game_loop/ii_key_use \
	src_bonus/game_loop/iii_process_input \
	src_bonus/game_loop/iv_render_textures \
	src_bonus/game_loop/iv_render_textures_ii \
	src_bonus/game_loop/v_render_sprites \
	src_bonus/game_loop/vi_draw_sprite \
	src_bonus/game_loop/digital_diferential_analysis \
	src_bonus/scene_description/i_read_file \
	src_bonus/scene_description/ii_set_description \
	src_bonus/scene_description/iii_generate_map \
	src_bonus/scene_description/iv_check_map \
	src_bonus/scene_description/v_load_player \
	src_bonus/scene_description/vi_floodfill_check \
	src_bonus/scene_description/vi_floodfill_check_ii \
	src_bonus/scene_description/utils_check \
	src_bonus/scene_description/utils_description \
	src_bonus/scene_description/utils_map \
	src_bonus/scene_description/utils_floodfill \
	src_bonus/scene_description/utils_floodfill_sides \
	src_bonus/utils/check_str \
	src_bonus/utils/maths \
	src_bonus/utils/mlx_colors \
	src_bonus/utils/mlx_draw_geometry \
	src_bonus/utils/mlx_draw_line \
	src_bonus/utils/mlx_image_to_bmp \
	src_bonus/utils/mlx_pixel \
	src_bonus/utils/points \
	src_bonus/bonus/utils_render_map \
	src_bonus/bonus/bonus_mouse \
	src_bonus/bonus/utils_render_vision \
	src_bonus/bonus/load_textures_bonus \
	src_bonus/bonus/doors_bonus

SRCS_B = $(addsuffix .c, $(FILES_B))

OBJS_B = $(addprefix $(OBDIR)/,$(SRCS_B:.c=.o))

########################## Colors ##########################

R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

########################## Rules ##########################

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(GR)[Compiling $(B)'$(NAME)'$(GR). Please, wait a few seconds...]${END}\n"
	make -C $(LDIR)/$(LIBFT)
	cp $(LDIR)/$(LIBFT)/$(LIBFT_A) ./$(LIBFT_A)
	@echo "\n$(GR)[Compiling $(B)'minilibx'$(GR). Please, wait a few seconds...]${END}\n"
	make -sC $(LDIR)/$(LMLXDIR)/$(MLXDIR)
ifeq ($(UNAME), Linux)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/$(LIBMLX_A) ./$(LIBMLX_A)
	@echo "\n$(G)[Compiled $(B)'minilibx' $(G)successfully]${END}\n"
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) ./$(LIBFT_A) ./$(LIBMLX_A) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A) ./$(LIBMLX_A)
endif
ifeq ($(UNAME), Darwin)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/$(DLIBMLX) ./
	@echo "\n$(G)[Compiled $(B)'minilibx' $(G)successfully]${END}\n"
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) ./$(LIBFT_A) ./$(DLIBMLX) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A)
endif
	@echo "\n$(G)[Compiled $(B)'$(NAME)' $(G)successfully]${END}\n"

$(ODIR)/%.o: $(SDIR)/%.c $(HDIR)/cub3d.h | $(ODIR)
	$(CC) $(CFLAGS) -I $(HDIR) -o $@ -c $<

$(ODIR):
	mkdir -p $(ODIR)
	mkdir -p $(ODIR)/main
	mkdir -p $(ODIR)/game_loop
	mkdir -p $(ODIR)/scene_description
	mkdir -p $(ODIR)/utils

$(OBDIR)/%.o: $(SDIR)/%.c $(HDIR)/cub3d_bonus.h | $(OBDIR)
	$(CC) $(CFLAGS) -I $(HDIR) -o $@ -c $<

$(OBDIR):
	mkdir -p $(OBDIR)
	mkdir -p $(OBDIR)/main
	mkdir -p $(OBDIR)/game_loop
	mkdir -p $(OBDIR)/scene_description
	mkdir -p $(OBDIR)/utils
	mkdir -p $(OBDIR)/bonus

bonus: $(OBJS_B)
	@echo "\n$(GR)[Compiling $(B)'$(LNAME) BONUS'$(GR). Please, wait a few seconds...]${END}\n"
	make -C $(LDIR)/$(LIBFT)
	cp $(LDIR)/$(LIBFT)/libft.a ./$(LNAME)
	make -C $(LDIR)/$(LMLXDIR)/$(MLXDIR)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/libmlx.a ./$(LNAME)
	$(AR) $(LNAME) $(OBJS_B)
	@echo "\n$(G)[Compiled $(B)'$(LNAME) BONUS' $(G)successfully]${END}\n"
	$(OBDIR)/%.o: $(SBDIR)/%.c $(HBDIR)/$(NAME).h
	mkdir -p $(OBDIR)
	$(CC) $(CFLAGS) -I $(HBDIR) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(ODIR) $(OBDIR)
	make fclean -C $(LDIR)/$(LIBFT)
	make clean -C $(LDIR)/$(LMLXDIR)/$(MLXDIR)
	@echo "\n$(R)[Cleaned $(B) $(NAME) objects $(R)successfully]$(END)\n"

fclean: clean
	@echo "\n$(R)[Cleaned $(B) $(NAME) objects $(R)successfully]$(END)\n"
	$(RM) $(NAME)
ifeq ($(UNAME),Darwin)
	$(RM) $(DLIBMLX)
endif
	@echo "$(R)[Removed $(B)'$(NAME)' $(R)successfully]$(END)\n"

re: fclean all

re_bonus: fclean bonus

Norme:
	norminette -R CheckForbiddenSourceHeader $(LIB)/ $(SDIR)/ $(HDIR)
	@echo "\n$(Y)[Checked norminette in $(B)'$(NAME)' $(Y)successfully]$(END)\n"
	norminette -R CheckForbiddenSourceHeader $(SBDIR)/ $(HBDIR)
	@echo "\n$(Y)[Checked norminette in $(B)'$(NAME) BONUS' $(Y)successfully]$(END)\n"

Debug: CFLAGS += -O0 -g3 -fsanitize=address
Debug: fclean $(OBJS)
	@echo "\n$(GR)[Compiling $(B)'$(NAME)'$(GR). Please, wait a few seconds...]${END}\n"
	make Debug -C $(LDIR)/$(LIBFT)
	cp $(LDIR)/$(LIBFT)/$(LIBFT_A) ./$(LIBFT_A)
		@echo "\n$(GR)[Compiling $(B)'minilibx'$(GR). Please, wait a few seconds...]${END}\n"
	make -sC $(LDIR)/$(LMLXDIR)/$(MLXDIR)
ifeq ($(UNAME), Linux)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/$(LIBMLX_A) ./$(LIBMLX_A)
	@echo "\n$(G)[Compiled $(B)'minilibx' $(G)successfully]${END}\n"
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) ./$(LIBFT_A) ./$(LIBMLX_A) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A) ./$(LIBMLX_A)
endif
ifeq ($(UNAME), Darwin)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/$(DLIBMLX) ./$(DLIBMLX)
	@echo "\n$(G)[Compiled $(B)'minilibx' $(G)successfully]${END}\n"
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) ./$(LIBFT_A) ./$(DLIBMLX) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A)
endif
	@echo "\n$(G)[Compiled $(B)'$(NAME)' $(G)successfully]${END}\n"
	@echo "\n$(Y)[Mode debug activated for $(B)'$(NAME)']$(END)\n"

.PHONY: all clean fclean re bonus Norme Debug

$(V).SILENT:
