SERVER = server
CLIENT = client

HEADER = minitalk.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra 

SRC_S = server.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_putchar_fd.c
SRC_C = client.c ft_putstr_fd.c ft_strlen.c ft_atoi.c

OBJ_S = $(SRC_S:%.c=%.o)
OBJ_C = $(SRC_C:%.c=%.o)

all: $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_S) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(SERVER)

$(CLIENT): $(OBJ_C) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(CLIENT)


clean:
	rm -f $(OBJ_C) $(OBJ_S)

fclean:	clean
	rm -f $(OBJ_C) $(OBJ_S) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all re fclean clean
