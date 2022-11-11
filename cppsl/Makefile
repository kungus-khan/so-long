NAME = so_long

SRCP = utils/format_one.c utils/format_two.c utils/ft_printf.c utils/prt_utils.c

SRC = so_long.c utils/a_utils.c utils/clr_utils.c utils/mp_utils.c utils/utils.c \
      utils/mp_counter.c utils/get_next_line.c utils/get_next_line_utils.c \
      utils/mp_validation.c utils/mp_mlx.c utils/mp_hooks.c ${SRCP}

GCCF = gcc -Wall -Werror -Wextra

BS = -D BUFFER_SIZE=1

OBJ := ${SRC:c=o}

${NAME} : ${OBJ}
	make -C mlx
	$(GCCF) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

%.o : %.c
	${GCCF} ${BS} -Imlx -c $< -o $@

all : ${NAME}

clean :
	@rm ${OBJ}
	make clean -C mlx

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re