NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

INC_DIR = include
SRCS_DIR = srcs
OBJS_DIR = objs

PARSING = parsing copy_map checker texture rgb map flood_fill
RAYCASTING = so_long
UTILS = free error utils_parsing

SRCS = $(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING))) \
		$(addsuffix .c, $(addprefix srcs/raycasting/, $(RAYCASTING))) \
	  	$(addsuffix .c, $(addprefix srcs/utils/, $(UTILS)))

OBJS = $(addprefix ${OBJS_DIR}/, $(subst srcs/,,$(SRCS:.c=.o)))

LIBFT_PATH = libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}/include

MLX_PATH = MLX42/build
MLX_LIB = ${MLX_PATH}/libmlx42.a
# Change this path for your homebrew path
MLX_INC = -Iinclude -lglfw -L"/Users/${USER}/homebrew/opt/glfw/lib/"
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit

GREEN	= \033[32;1m
CYAN	= \033[36;1m
RED		= \033[0;31m
BOLD	= \033[1m
RESET	= \033[0m
MAGENTA	=\033[0;95m

all: ${MLX_LIB} ${LIBFT_LIB} ${NAME}

${MLX_LIB}:
	@cd MLX42 && cmake -B build
	@cmake --build ${MLX_PATH} -j4

${LIBFT_LIB}:
	@make -C ${LIBFT_PATH}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	@${CC} ${CFLAGS} -I ${INC_DIR} -I ${LIBFT_INC} -c $< -o $@
	@echo "$(GREEN)Compiling: $<$(RESET)$(MAGENTA)              [OK]$(RESET)"

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${MLX_FLAGS} ${MLX_INC} ${OBJS} ${LIBFT_LIB} ${MLX_LIB} -o ${NAME}
	@echo "$(GREEN)Compilation terminé avec succès !"

clean:
	@make clean -C ${LIBFT_PATH}
	@make clean -C ${MLX_PATH}
	@${RM} ${OBJS_DIR}
	@echo "$(RED)$(BOLD)Nettoyage effectué avec succès !"

fclean:	clean
	@make fclean -C ${LIBFT_PATH}
	@make clean -C ${MLX_PATH}
	@${RM} ${NAME}

re: fclean all
	@echo "$(CYAN)Recompilation Terminé !"

.PHONY: all clean fclean re

#############################################################################


# Program
NAME = cub3D
S_DIR = src
S_OBJ = bin

SUBDIRS = game \
parsing \
raycasting \
utils

SRCS = src/main.c src/parsing/ft_check_file.c src/parsing/save_data.c \
src/utils/Error.c src/utils/str_1.c src/utils/str_2.c src/game/game.c \
src/raycasting/raycasting.c src/game/control.c src/game/ft_creat_frams.c \
src/game/color.c src/game/utils.c src/parsing/img_color.c src/parsing/check_file_color.c \
src/parsing/save.c src/parsing/save_2.c src/parsing/get_map_heigth.c \
src/parsing/utils.c src/raycasting/utils.c src/utils/check.c

OBJS_DIRS = $(foreach dir, $(SUBDIRS), $(addprefix $(S_OBJ)/, $(dir)))

OBJS = $(subst $(S_DIR), $(S_OBJ), $(SRCS:.c=.o))

CC = gcc
CFLAGS =  -g -Wall -Wextra -Werror
RM = rm -fr

LIBFT = ./libs/libft/libft.a

# Define the path where MLX42 will be cloned and built
MLX42_DIR = libs/MLX42
MLX42_BUILD_DIR = $(MLX42_DIR)/build

# Define the URL for cloning the MLX42 repository
MLX42_REPO = https://github.com/codam-coding-college/MLX42.git


LIB_MLX = -framework Cocoa -framework OpenGL -framework IOKit $(MLX42_DIR)/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
# LIB_MLX  = -framework Cocoa -framework OpenGL -framework IOKit libs/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
# LIB_MLX  = -framework Cocoa -framework OpenGL -framework IOKit libs/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/opt/glfw/lib/"

$(S_OBJ)/%.o:$(S_DIR)/%.c
@mkdir -p $(S_OBJ) $(OBJS_DIRS)
@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
@$(MAKE) all -C ./libs/libft
@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LIB_MLX)
# @$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(S_OBJ):
@mkdir -p $(S_OBJ)

all: $(NAME)

clean:
@$(RM) $(OFIX) $(S_OBJ)

fclean: clean
@$(RM) $(NAME)
@$(MAKE) fclean -C ./libs/libft

re: fclean $(NAME)

mlx42:
@git clone $(MLX42_REPO) $(MLX42_DIR)
@cd $(MLX42_DIR) && cmake -B build
@cd $(MLX42_DIR) && cmake --build build -j4

.PHONY: all clean fclean re mlx42
