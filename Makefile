NAME =		philo
MAIN =		obj/main.o
OBJECTS =	obj/state.o \
			obj/timestamp.o
HEADERS =	philo.h \
			structs.h
CFLAGS ?=	-Wall -Wextra -Werror
LDFLAGS ?=
all :		$(NAME)

$(NAME) : $(MAIN) $(OBJECTS)
	$(CC) -o $(NAME) $(MAIN) $(OBJECTS) $(LDFLAGS)

obj/%.o : %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf obj

fclean : clean
	rm -f $(NAME)

re : fclean all

docker-pwd:
	docker run --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it --rm --init -v "$$PWD:/pwd"  ubuntu-philo sh -c "cd /pwd; bash"

.PHONY : all clean fclean re