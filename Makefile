NAME = fdf

SRC =	src/main.c \
		src/parsing.c\
		src/error.c\
		src/conv_tab.c\
		src/render.c\
        src/init.c\

INC = -I ./include/

LIB = libft/libft.a
LIB_PATH = libft/

OBJ = $(SRC:.c=.o)

MFLAG = $(shell sdl2-config --cflags) $(shell sdl2-config --libs) # -lmlx -framework OpenGL -framework AppKit
FLAG = #-Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIB) $(INC) $(MFLAG)
	@echo "fdf created"

%.o: %.c
	@$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIB_PATH)
	@echo "fdf cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "fdf deleted"

re: fclean all
