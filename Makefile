SERVER_NAME	=	server
CLIENT_NAME	=	client
INCLUDES	=	includes
FT_PRINTF	=	ft_printf/libftprintf.a

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

CLIENT_SRC	=	client.c		\
				errors.c		\
				ft_atoi.c

SERVER_SRC	=	server.c

CLIENT_OBJ	=	$(addprefix obj/client/, $(CLIENT_SRC:.c=.o))
SERVER_OBJ	=	$(addprefix obj/server/, $(SERVER_SRC:.c=.o))

all:	$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):	$(SERVER_OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(FT_PRINTF) -o $(SERVER_NAME)

$(CLIENT_NAME):	$(CLIENT_OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(FT_PRINTF) -o $(CLIENT_NAME)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(FT_PRINTF):
	make libftprintf.a --directory=ft_printf

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)

fclean:	clean
	make fclean --directory=ft_printf
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	rm -rf obj

re:	fclean all

.PHONY: all clean fclean re