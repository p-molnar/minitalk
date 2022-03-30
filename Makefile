SERVER_NAME	=	server
CLIENT_NAME	=	client
INCLUDES	=	include
FT_PRINTF	=	ft_printf/libftprintf.a

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

GENERIC_SRC	=	utils.c				\
				errors.c
					
CLIENT_SRC	=	client.c			\
				ft_atoi.c			\

SERVER_SRC	=	server.c

CLIENT_OBJ	=	$(addprefix obj/client/, $(CLIENT_SRC:.c=.o))
SERVER_OBJ	=	$(addprefix obj/server/, $(SERVER_SRC:.c=.o))
GENERIC_OBJ	=	$(addprefix obj/, $(GENERIC_SRC:.c=.o))

RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[1;33m
DEF		=	\033[0m

all:	$(GENERIC_OBJ) $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):	$(SERVER_OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(GENERIC_OBJ) $(FT_PRINTF) -o $(SERVER_NAME)
	@echo "$(GREEN)$(SERVER_NAME) was sucessfully made\n$(DEF)"

$(CLIENT_NAME):	$(CLIENT_OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(GENERIC_OBJ) $(FT_PRINTF) -o $(CLIENT_NAME)
	@echo "$(GREEN)$(CLIENT_NAME) was sucessfully made\n$(DEF)"

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(FT_PRINTF):
	make libftprintf.a --directory=ft_printf

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	@echo "$(GREEN)Object files successfully deleted\n$(DEF)"

fclean:	clean
	make fclean --directory=ft_printf
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	rm -rf obj
	@echo "$(GREEN)Executable file(s) sucessfully deleted\n$(DEF)"

re:	fclean all

norm:
	norminette src

.PHONY: all clean fclean re norm