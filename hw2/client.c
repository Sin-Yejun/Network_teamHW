#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <sys/select.h>
#define BUFSIZE 30
#define NICK_SIZE 30

void error_handling(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <ip> <port> <nickname>\n", argv[0]);
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

    fd_set reads, temps;
    int fd_max;
	
    FD_ZERO(&reads);
    FD_SET(0, &reads); // 0 is file descriptor of stdin
    FD_SET(sock, &reads);
    fd_max = sock;
    
    while (1) {
	temps = reads;
    	if (select(fd_max+1, &temps, 0, 0, NULL) == -1)
        	error_handling("select() error");
	if (FD_ISSET(sock, &temps)) {
        	// Receive message from server
        	memset(message, 0, sizeof(message));
		int str_len = read(sock, message, sizeof(message));
       		if (str_len == -1)
            		error_handling("read() error");
		message[str_len] = '\0';
        	printf("%s", message);

    	}	
	if (FD_ISSET(0, &temps)) {
        	// Send message to server
	        memset(message, 0, sizeof(message));
	      	fgets(message, sizeof(message), stdin);
	        int len = strlen(message);
	        if(message[len-1] == '\n')
	            message[len-1]='\0';
	        if (strcmp(message, "Q\0") == 0){
	            break;
	        }
 	       write(sock, message, strlen(message)+1);
  	}	

    }

    close(sock);

   return 0;
}

