NAME =		philo
MAIN =		obj/main.o
OBJECTS =	obj/state.o \
			obj/timestamp.o
HEADERS =	philo.h \
			structs.h
all :		$(NAME)

$(NAME) : $(MAIN) $(OBJECTS)
	$(CC) -o $(NAME) $(MAIN) $(OBJECTS)

obj/%.o : %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $<

clean :
	rm -rf obj

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re