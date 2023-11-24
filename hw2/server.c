#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <string.h>
#define BUFSIZE 50
#define MAX_CLIENT 1024
#define NICK_SIZE 50

void error_handling(const char *message){
	perror(message);
	exit(1);
}

char nicknames[MAX_CLIENT][NICK_SIZE];

int main(int argc, char **argv){
	int serv_sock;
	struct sockaddr_in serv_addr;
	fd_set reads, temps;
	int fd_max;
	char message[BUFSIZE];
	int str_len;
	if(argc!=2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));
    
	if(bind(serv_sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)))
		error_handling("bind() error");
	if(listen(serv_sock, 5) == -1)
		error_handling("listen() error");
	FD_ZERO(&reads);
	FD_SET(serv_sock, &reads);
	fd_max = serv_sock;
	while(1)
	{
		int fd, str_len;
		int clnt_sock;
		socklen_t clnt_len;
		struct sockaddr_in clnt_addr;
		temps = reads;

		if (select(fd_max+1, &temps, NULL, NULL, NULL) == -1)
			error_handling("select() error");

		for (fd = 3; fd < fd_max+1; fd++) // Usually fd 0 is stdin, fd 1 is stdout
		{
			if (FD_ISSET(fd, &temps))
			{   
				if (fd == serv_sock) { // connect request from a client
					clnt_len = sizeof(clnt_addr);
					clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_len);

                    read(clnt_sock, nicknames[clnt_sock], NICK_SIZE); // 닉네임 읽기
					printf("connected client: %s\n", nicknames[clnt_sock]);

                    // Notify new participants of current participants.
                    int cnt = 0;
                    char tmp[BUFSIZE];
                    for (int i = 3; i < fd_max+1; i++) {
                        if (FD_ISSET(i, &reads) && i != serv_sock && i != clnt_sock) {
                            if(cnt == 0) {
                                strcpy(tmp, "\n[ Notice ] Who's currently in the chat\n");
                                write(clnt_sock, tmp, BUFSIZE);
                            }
                            sprintf(tmp, "%d : %s\n", cnt+1, nicknames[i]);
                            write(clnt_sock, tmp, NICK_SIZE);
                            cnt++;
                        }
                    }
                    if(cnt == 0) {
                        strcpy(tmp, "\n[ Notice ] No one has joined the chat.\n\n");
                        write(clnt_sock, tmp, BUFSIZE);
                    }
                    else {
                        sprintf(tmp, "A total of %d user is in the chat.\n\n", cnt);
                        write(clnt_sock, tmp, BUFSIZE);
                    }

                    FD_SET(clnt_sock, &reads);
                    // printf("set %d\n", clnt_sock);
					if (fd_max < clnt_sock)
						fd_max = clnt_sock;

                    // Notify other users of your chat participation
                    for (int i = 3; i < fd_max+1; i++) {
                        if (FD_ISSET(i, &reads) && i != serv_sock && i != clnt_sock) {
                            sprintf(tmp, "[ Notice ] %s joined the chat.\n\n", nicknames[clnt_sock]);
                            write(i, tmp, NICK_SIZE);
                        }
                    }

				} else {
					str_len = read(fd, message, BUFSIZE);
					if(str_len == 0) { // connection close
						char buf[BUFSIZE+NICK_SIZE] = {0,};
						printf("* User left: %s\n", nicknames[fd]);
						FD_CLR(fd, &reads);	

						// Notify other users of your chat participation
						for (int i = 3; i < fd_max+1; i++) {
							if (FD_ISSET(i, &reads) && i != serv_sock && i != fd) {
								sprintf(buf, "\n[ Notice ] %s left the chat.\n\n", nicknames[fd]);
								write(i, buf, NICK_SIZE);
							}
						}
					} else {
						printf("%s : %s\n", nicknames[fd], message);
						//write(fd, message, strlen(message));
						char msg_with_id[BUFSIZE + NICK_SIZE + 4]; // +4 for " : " and null terminator
						int i;
						for (i = 3; i < fd_max+1; i++) {
                            if (FD_ISSET(i, &reads) && i != serv_sock) {
								if(i == fd)
									sprintf(msg_with_id, "me : %s\n", message);
								else
									sprintf(msg_with_id, "%s : %s\n", nicknames[fd], message);
                                write(i, msg_with_id, strlen(msg_with_id));
                            }
                        }
						memset(message, 0, sizeof(message));
					}
				}
			} //if(FD_ISSET(fd, &temps))
		} //for(fd=3; fd<fd_max+1; fd++)
	} //while(1)
}
