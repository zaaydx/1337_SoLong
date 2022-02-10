NAME 		= so_long

NAMEB		= so_long_bonus

CFLAGS 		= -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

INC 		= mandatory_part/so_long.h \
			mandatory_part/get_next_line/get_next_line.h \

BONUS_INC 	= bonus_part/so_long_bonus.h \
			bonus_part/get_next_line/get_next_line.h \

SRC_FILES 	= so_long.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			utiles/utiles1.c \
			utiles/utiles2.c \
			utiles/utiles3.c \
			utiles/utiles4.c \
			utiles/utiles5.c \
			extension.c \
			good_map.c \

B_SRC_FILES = so_long_bonus.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			utiles/utiles1.c \
			utiles/utiles2.c \
			utiles/utiles3.c \
			utiles/utiles4.c \
			utiles/utiles5.c \
			extension.c \
			good_map.c \

SRC 		= $(addprefix mandatory_part/, $(SRC_FILES))

BONUS_SRC 	= $(addprefix bonus_part/, $(B_SRC_FILES))

all : $(NAME)

$(NAME): $(SRC) $(INC)
	@gcc $(CFLAGS) $(SRC) -o $(NAME)

bonus: $(NAMEB)

$(NAMEB): $(B_SRC) $(BONUS_INC)
	@gcc $(CFLAGS) $(BONUS_SRC) -o $(NAMEB)

clean:
	@rm -rf $(NAME) $(NAMEB)

fclean: clean

re: fclean all

.PHONY: all clean fclean bonus re