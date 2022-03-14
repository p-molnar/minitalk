SERVER_NAME	=	server
CLIENT_NAME	=	client
INCLUDES	=	includes

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

CLIENT_SRC	=	client.c
SERVER_SRC	=	server.c

CLIENT_OBJ	=	$(addprefix obj/client/, $(CLIENT_SRC:.c=.o))
SERVER_OBJ	=	$(addprefix obj/server/, $(SERVER_SRC:.c=.o))

all:	$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):	$(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER_NAME)

$(CLIENT_NAME):	$(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT_NAME)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)

fclean:	clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	rm -rf obj

re:	fclean all

.PHONY: all clean fclean re