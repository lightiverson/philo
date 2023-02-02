NAME =		philo
MAIN =		obj/main.o
OBJECTS =	obj/philos_last_meal.o \
			obj/philos.o \
			obj/setter_getter.o \
			obj/shared.o \
			obj/state_cont.o \
			obj/state.o \
			obj/timestamp.o \
			obj/utils.o \
			obj/validate.o
HEADERS =	philos.h \
			setter_getter.h \
			shared.h \
			state.h \
			structs.h \
			timestamp.h \
			utils.h \
			validate.h
CFLAGS ?=	-Wall -Wextra -Werror
LDFLAGS ?=

all :		libft $(NAME)

libft:
	make -C libft

$(NAME) : $(MAIN) $(OBJECTS)
	$(CC) -o $(NAME) $(MAIN) $(OBJECTS) libft/libft.a $(LDFLAGS)

obj/%.o : %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	make clean -C libft
	rm -rf obj

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all

docker-pwd:
	docker run --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it --rm --init -v "$$PWD:/pwd"  ubuntu-philo sh -c "cd /pwd; bash"

.PHONY : all clean fclean re libft