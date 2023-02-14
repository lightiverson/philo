VPATH =		src: \
			includes
NAME =		philo
MAIN =		obj/main.o
OBJECTS =	obj/ft_atoi.o \
			obj/ft_calloc.o \
			obj/ft_itoa.o \
			obj/ft_mini.o \
			obj/ft_strdup.o \
			obj/philos_last_meal.o \
			obj/philos.o \
			obj/setter_getter_cont.o \
			obj/setter_getter.o \
			obj/shared.o \
			obj/state_cont.o \
			obj/state.o \
			obj/timestamp.o \
			obj/utils.o \
			obj/validate.o
HEADERS =	ft_mini.h \
			philos.h \
			setter_getter.h \
			shared.h \
			state.h \
			structs.h \
			timestamp.h \
			utils.h \
			validate.h
CFLAGS ?=	-Wall -Wextra -Werror -O3
LDFLAGS ?=

all :	$(NAME)

$(NAME) : $(MAIN) $(OBJECTS)
	$(CC) -o $(NAME) $(MAIN) $(OBJECTS) $(LDFLAGS)

obj/%.o : %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) -I ./includes $(CFLAGS) -c -o $@ $<

clean :
	rm -rf obj

fclean : clean
	rm -f $(NAME)

re : fclean all

docker-pwd-thread:
	docker run \
	-it \
	--rm \
	--init \
	-v "$$PWD:/pwd" \
	--cap-add=SYS_PTRACE \
	--security-opt seccomp=unconfined \
	-e CFLAGS="-Wall -Wextra -fsanitize=thread -g -O1" \
	-e LDFLAGS="-fsanitize=thread -g -O1" \
	ubuntu-philo sh -c "cd /pwd; bash"

docker-pwd-leak:
	docker run \
	-it \
	--rm \
	--init \
	-v "$$PWD:/pwd" \
	--cap-add=SYS_PTRACE \
	--security-opt seccomp=unconfined \
	-e CFLAGS="-Wall -Wextra -fsanitize=leak -g" \
	-e LDFLAGS="-fsanitize=leak -g" \
	ubuntu-philo sh -c "cd /pwd; bash"

.PHONY : all clean fclean re