#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#define BUFSIZE 30
#define NICK_SIZE 30

void error_handling(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <ip> <port> <nickname>", argv[0]);
        exit(1);
    }

    int sock;
    struct sockaddr_in serv_addr;
    char message[BUFSIZE];
    char nickname[NICK_SIZE];

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket() error");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error");

    strncpy(nickname, argv[3], NICK_SIZE);
    write(sock, nickname, NICK_SIZE); // 닉네임 보내기

    while (1) {
        printf("Input message (Q to quit): ");
        fgets(message, sizeof(message), stdin);
	int len = strlen(message);
        if (len > 0 && message[len - 1] == '\n') {
            message[len - 1] = '\0';
        }
        if (strcmp(message, "Q") == 0){
            break;
        }

        write(sock, message, strlen(message));

        int str_len = read(sock, message, sizeof(message) - 1);
        if (str_len == -1)
            error_handling("read() error");

        message[str_len] = 0;
        printf("Message from server: %s", message);

    }

    close(sock);

    return 0;
}

