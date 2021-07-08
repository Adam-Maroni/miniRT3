CC = gcc
FLAGS = -Wall -Werror -Wextra 
BUFFER_SIZE_GNL = 1
MINILIBX_ARCHIVE = miniLibX/libmlx_Linux.a
LIBFT_ARCHIVE = ./libft/libft.a
LIB = $(MINILIBX_ARCHIVE) -lXext -lX11 -lm libft/libft.a
MEM_CHECK = -g -fsanitize=address

RT_FILE = ./rtfiles/1.rt

SRC_GNL = ./gnl/get_next_line.c\
	  ./gnl/get_next_line_utils.c

SRC_UTILS = utils/*.c

SRC_ALL = $(SRC_GNL) $(SRC_UTILS) raytracing/*.c

OUT = minirt

compile_minilibx: $(MINILIBX_ARCHIVE)
	(cd miniLibX/ && make all)
compile_libft: $(LIBFT_ARCHIVE)
	(cd libft/ && make all)


.SILENT:
MAIN = main.c
test: compile_libft compile_minilibx $(SRC_ALL)
	$(CC) $(FLAGS) $(MEM_CHECK) -D BUFFER_SIZE=$(BUFFER_SIZE_GNL) $(SRC_ALL) $(MAIN) -o $(OUT) $(LIB)
	./$(OUT) $(RT_FILE)
gdb_test: compile_libft compile_minilibx $(SRC_ALL)
	$(CC) $(FLAGS) $(MEM_CHECK) -D BUFFER_SIZE=$(BUFFER_SIZE_GNL) $(SRC_ALL) $(MAIN) -o $(OUT) $(LIB)
	gdb --args ./$(OUT) $(RT_FILE)

clean:
	(cd ./libft && make clean)
	rm -rf *.o	
