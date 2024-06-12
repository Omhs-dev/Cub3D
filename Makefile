NAME:=	cub3D

BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
NC=\033[0m

INCLUDE:= -Iinclude -Ilibft/includes

SRC:= 	./src/main.c \
		./src/game/start_game.c \
		./src/parsing/parser.c \
		./src/parsing/parse_description.c \
		./src/parsing/validate_descr.c \
		./src/parsing/valid_utils.c \
		./src/parsing/parse_map.c \
		./src/parsing/valid_map.c \
		./src/utils/errors.c \
		./src/utils/free.c \
		./src/get_next_line/get_next_line.c \
		./src/get_next_line/get_next_line_utils.c \
		./src/game/movement_utils.c \
		./src/game/movement.c \
		./src/game/raycasting.c \
		./src/game/intersection.c \
		./src/game/render_utils.c \
		./src/game/rendering.c \

OBJ:=	$(SRC:.c=.o)

FLAGS:=	-Wall -Werror -Wextra
FLAGS+= -g3 -fsanitize=address

CC:= gcc

# Detect the operating system
UNAME_S := $(shell uname -s)

# Default values
LIBS := -ldl -lglfw -pthread -lm
MLX_DIR := lib/MLX42

# Adjust values based on the operating system
ifeq ($(UNAME_S), Linux)
    LIBS += -lX11 -lXext
endif
ifeq ($(UNAME_S), Darwin)  # macOS
    LIBS += -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
endif
all: libft mlx $(NAME)

libft:
	@echo "$(YELLOW)Compiling Libft$(NC)"
	@make re -C lib/libft
	@make clean -C lib/libft
	@echo "$(GREEN)Libft compiled$(NC)"

mlx:
	@if [ ! -d "lib/MLX42" ] || [ -z "$(ls -A lib/MLX42)" ]; then \
		rm -rf lib/MLX42; \
	fi
	@git clone https://github.com/codam-coding-college/MLX42.git lib/MLX42; 
	@cmake -B lib/MLX42/build lib/MLX42 
	@cmake --build lib/MLX42/build -j4
	@echo "Building MLX42..."

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MLX_DIR)/build/libmlx42.a lib/libft/libft.a $(LIBS) $(INCLUDE)
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f cub3d
re: fclean all