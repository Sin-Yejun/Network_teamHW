#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

void error_handling(char *message);

int main(int argc, char **argv) {
    int serv_sock;
    char message[BUFSIZE];
    int str_len, addr_size;
    struct sockaddr_in serv_addr, from_addr;

    if (argc != 2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (serv_sock == -1)
        error_handling("UDP 소켓 생성 오류");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() 오류");
    int num = 1;
    while (1) {
        addr_size = sizeof(from_addr);
        str_len = recvfrom(serv_sock, message, BUFSIZE, 0, (struct sockaddr *)&from_addr, &addr_size);
        message[str_len] = 0;
        printf("Message %d: %s\n", num++,  message);
    }

    close(serv_sock);

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}

