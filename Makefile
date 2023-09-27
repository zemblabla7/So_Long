NAME = so_long

PATH_MLX = "minilibx-linux"
MLX = $(PATH_MLX)/libmlx.a

PATH_LIBFT = "libft"
LIBFT = $(PATH_LIBFT)/libft.a

PATH_FT_PRINTF = "ft_printf"
FT_PRINTF = $(PATH_FT_PRINTF)/libftprintf.a

PATH_SRC = src

PATH_GNL = get_next_line

SRC = $(PATH_SRC)/main.c \
	$(PATH_SRC)/map.c \
	$(PATH_SRC)/movement.c \
	$(PATH_SRC)/images.c \
	$(PATH_SRC)/close.c \
	$(PATH_SRC)/close2.c \
	$(PATH_SRC)/free.c \
	$(PATH_SRC)/map_checks.c \
	$(PATH_SRC)/map_checks2.c \
	$(PATH_SRC)/map_check_backtracking.c \
	$ get_next_line/get_next_line.c \
	$ get_next_line/get_next_line_utils.c \

OBJS = $(SRC:.c=.o)

CC = cc

LINKER_FLAGS = -lXext -lX11 -lm

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3

all: $(MLX) $(LIBFT) $(FT_PRINTF) $(NAME)
	 @toilet COMPILED -F border -f wideterm

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKER_FLAGS) $(MLX) $(LIBFT) $(FT_PRINTF)
	clear

$(MLX):
	@toilet MLX -F border -f wideterm
	@$(MAKE) --no-print-directory -C $(PATH_MLX)
	clear

$(LIBFT):
	@toilet LIBFT -F border -f wideterm
	@$(MAKE) --no-print-directory -C $(PATH_LIBFT)
	clear

$(FT_PRINTF):
	@toilet FT_PRINTF -F border -f wideterm
	@$(MAKE) --no-print-directory -C $(PATH_FT_PRINTF)
	clear

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(PATH_MLX) -I $(PATH_LIBFT) -I $(PATH_FT_PRINTF) -I $(PATH_SRC) -I $(PATH_GNL)

clean:
	@toilet CLEAN -F border -f wideterm
	$(RM) $(OBJS)
	make -C ${PATH_LIBFT} clean
	make -C ${PATH_MLX} clean
	make -C ${PATH_FT_PRINTF} clean
	clear

fclean: clean
	@toilet FCLEAN -F border -f wideterm
	$(RM) $(NAME)
	make -C ${PATH_LIBFT} fclean
	make -C ${PATH_FT_PRINTF} fclean
	clear

re: fclean all

.PHONY: all clean fclean re