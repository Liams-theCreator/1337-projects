CC = cc
FLAGS = -Werror -Wextra -Wall

CLIENT_SRC = client.c utils.c
CLIENT_BNS = client_bonus.c utils.c
CLIENT_OBJ = client.o utils.o
CLIENT_OBS = client_bonus.o utils.o
CLIENT_X = client

SERVER_SRC = server.c utils.c
SERVER_BNS = server_bonus.c utils.c
SERVER_OBJ = server.o utils.o
SERVER_OBS = server_bonus.o utils.o
SERVER_X = server

PRINTF_OBJ = printf/libftprintf.a

all: $(CLIENT_X) $(SERVER_X)


$(CLIENT_X): $(CLIENT_OBJ)
	$(CC) $(FLAGS) -o $(CLIENT_X) $(CLIENT_OBJ) $(PRINTF_OBJ)

$(SERVER_X): $(SERVER_OBJ)
	$(CC) $(FLAGS) -o $(SERVER_X) $(SERVER_OBJ) $(PRINTF_OBJ)

client.o: client.c
	$(CC) $(FLAGS) -c client.c

server.o: server.c
	$(CC) $(FLAGS) -c server.c

utils.o: utils.c
	$(CC) $(FLAGS) -c utils.c

bonus: utils.o
	$(CC) $(FLAGS) -c client_bonus.c
	$(CC) $(FLAGS) -o client client_bonus.o utils.o $(PRINTF_OBJ)
	$(CC) $(FLAGS) -c server_bonus.c
	$(CC) $(FLAGS) -o server server_bonus.o utils.o $(PRINTF_OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(CLIENT_X) $(SERVER_X)

re: fclean all

reb: fclean bonus

.PHONY: all bonus clean fclean re reb
