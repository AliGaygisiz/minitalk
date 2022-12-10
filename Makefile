NAME = program

SERVER = server

CLIENT = client

CC = gcc

LIBFT = ./ft_printf/libftprintf.a

CFLAGS = -Wall -Werror -Wextra

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	make bonus -C ./ft_printf
	$(CC) $(CFLAGS) server.c $(LIBFT) -o $(SERVER)

$(CLIENT):
	make bonus -C ./ft_printf
	$(CC) $(CFLAGS) client.c $(LIBFT) -o $(CLIENT)

clean:
	make fclean -C ./ft_printf

fclean: clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re: fclean all

.PHONY: all flean clean re
