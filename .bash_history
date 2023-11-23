ls
clear
ls
ls -l
ls -a
pwd
cd ../
ls
pwd
home
ls
cd ljw
cd s21800239
ls
clear
logout
ls
vim socket.c
vi socket.c
ls
echo socket.c
clear
logout
ls
vi socket.c
ls
cat socket.c
vi netinet/in.h
ls
ls -l
vi echo_server.c
ls
rm socket.c
ls
clear
logout
ls
vi becho_server.c
ls
./select
ls
vi select
./select
vi select
ls
clear
rm select
ls
gcc becho_server.c -o server
ls
vi becho.server
ls
vi becho_server.c
becho_server.c: In function ‘main’:
becho_server.c:8:21: error: storage size of ‘serv_addr’ isn’t known
  struct sockaddr_in serv_addr;
                     ^
becho_server.c:9:21: error: storage size of ‘clnt_addr’ isn’t known
  struct sockaddr_in clnt_addr;
                     ^
becho_server.c:13:3: warning: incompatible implicit declaration of built-in function ‘printf’ [enabled by default]
   printf("Usage : %s <port>\n", argv[0]);
   ^
becho_server.c:14:3: warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]
   exit(1);
   ^
becho_server.c:17:19: error: ‘PF_INET’ undeclared (first use in this function)
  serv_sock=socket(PF_INET, SOCK_DGRAM, 0);
                   ^
becho_server.c:17:19: note: each undeclared identifier is reported only once for each function it appears in
becho_server.c:17:28: error: ‘SOCK_DGRAM’ undeclared (first use in this function)
  serv_sock=socket(PF_INET, SOCK_DGRAM, 0);
                            ^
becho_server.c:20:2: warning: incompatible implicit declaration of built-in function ‘memset’ [enabled by default]
  memset(&serv_addr, 0, sizeof(serv_addr));
  ^
becho_server.c:21:23: error: ‘AF_INET’ undeclared (first use in this function)
  serv_addr.sin_family=AF_INET;
                       ^
becho_server.c:22:34: error: ‘INADDR_ANY’ undeclared (first use in this function)
  serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
                                  ^
becho_server.c:33:3: warning: incompatible implicit declaration of built-in function ‘printf’ [enabled by default]
   printf("수신 번호 : %d \n", num++);
   ^
vi becho.server
clear
ls
vi becho_server.c
gcc becho_server.c -o server
vi becho_server.c
gcc becho_server.c -o server
./server 9190
./server 52156
./server 9190
./server 51234
vi becho_server.c
./server 50005
ls
vi echo_server.c
gcc echo_server.c -o hserver
vi echo_server.c
gcc echo_server.c -o hserver
vi echo_server.c
gcc echo_server.c -o hserver
./hserver 9190
./hserver 55123
ls
./server 55124
ls

./server 55124
./server 55124ls
ls
vi becho_server.c
vi echo_server.c
clear
ls
vi becho_server.c
ls -a
clear
ls
vi recho_server.c
gcc recho_server.c -o rserver
vi recho_server.c
gcc recho_server.c -o rserver
vi becho_server
vi becho_server.c
vi recho_server.c
vi becho_server.c
vi recho_server.c
gcc recho_server.c -o rserver
./rserver 55125
ls
rm recho_server.c
vi recho_server.c
gcc recho_server.c -o rserver
./rserver 55125
ls
vi recho_server.c
gcc recho_server.c -o rserver
./rserver 55125
ls
vi recho_server.c
clear
ls
vi sserver.c
gcc sserver.c -o sserver
./server 55126
vi sserver.c
gcc sserver.c -o sserver
./server 55126
ls
vi sserver.c
ls
gcc sserver.c -o sserver
./sserver 55852
vi dserver.c
gcc dserver.c -o dserver
./dserver 55987
ls
vi sserverc
rm sserver.c
vi sserver.c
gcc sserver.c -o sserver
vi sserver.c
gcc sserver.c -o sserver
./sserver 55258
ls
./client 127.0.0.1 50123
ls
logout
ls
vi select.c
ls
clear
ls
gcc select.c -o select
vi select.c
gcc select.c -o select
vi select.c
gcc select.c -o select
clear
gcc select.c -o select
vi select.c
gcc select.c -o select
clear
gcc select.c -o select
vi select.c
gcc select.c -o select
clear
gcc select.c -o select
vi select.c
gcc select.c -o select
clear
./select 50123
ls
rm dserver hserver rserver server sserver
ls
./select 50123
clear
./select 50123
logout
ls
vi select.c
ls
ls -a
rm *.c.swp
rm *.swp
rm *.*.swp
rm .*.*.swp
ls -a
clear
ls
vi select.c
ls -a
clear
ls
gcc select.c -o select
./server 55123
./select 55123
vi select.c
ls
vi select.c
gcc select.c -o select
./select 55123
vi select.c
gcc select.c -o select
vi select.c
gcc select.c -o select
./select 55123
vi select.c
gcc select.c -o select
clear
./select 55123
ls
vi select.c
clear
ls
gcc select.c -o select
./select 55123
vi select.c
gcc select.c -o select

./select 55125
vi select.c
clear
gcc select.c -o select
vi select.c
gcc select.c -o select
./server 55125
clear
./select 55456
vi select.c
clear
ls
gcc select.c -o select
./select 55456
clear
ls
vi select.c
./select 55456
vi select.c
gcc select.c -o select
clear
./select 55456
ls
clear
./client 127.0.0.1 55456
vi select.c
clear
ls
gcc select.c -o select
ls
clear
./select 55456
clear
gcc client.c -o client
./client 127.0.0.1 55125
vi client.c
clear
ls
vi client.c
gcc client.c -o client
./select 55456
./client 127.0.0.1 55456
ls
vi client.c
gcc client.c -o client
vi client.c
clear
gcc client.c -o client
vi client.c
gcc client.c -o client
gcc select.c -o server
clear
./server 55125
vi select.c
gcc select.c -o server
./server 55125
ls
vi select.c
clear
./client 127.0.0.1 50505
clear
./client 127.0.0.1 55555
vi server.c
vi select.c
gcc client.c -o client
./client 127.0.0.1 55555
ls
vi select.c
vi client.c
ls
gcc select.c -o server
gcc client.c -o client
./server 50505
ls -l
clear
./server 50505
./server 50510
clear
./server 55555
clear
ls
clear
gcc select.c -o server
clear
./server 55555
clear
./server 55555
logout
clear
ls
se -l
ls -l
clear
./client 127.0.0.1 50505
clear
./client 127.0.0.1 55555
clear
./client 127.0.0.1 55555
clear
./client 127.0.0.1 55555
lougout
logout
ls
clear
./client 127.0.0.1 55555
clear
./client 127.0.0.1 55555
Q
clear
./client 127.0.0.1 55555
Q
logout
clear
./client 127.0.0.1 50505
vi client.c
./client 127.0.0.1 50510
clear
vi client.c
gcc client.c -o client
./client 127.0.0.1 50510
vi client.c
gcc client.c -o client
./client 127.0.0.1 50510
vi client.c
gcc client.c -o client
./client 127.0.0.1 50510
vi client.c
gcc client.c -o client
./client 127.0.0.1 50510
clear
./client 127.0.0.1 55555
clear
./client 127.0.0.1 55555
Q
clear
./client 127.0.0.1 55555
Q
logout
ls
clear
./client 127.0.0.1 55555
clear
./client 127.0.0.1 55555
logout
ls
clear
ls
mkdir teamproj
ls
cd teamproj
ls
cd ../
ls
mkdir hw2
s
rm teamproj
rmdir teamproj
ls
clear
ls
cd hw2
ls
clear
cd ../
ls
vi select.c
cd ../
ls
cd s21900402
ls
clear
git init
git --version
ls
clear
git config --global user.name Sin-Yejun
git config --global user.email 21900402@handong.ac.kr
git init
ls
git remote add origin https://github.com/Sin-Yejun/Network_teamHW
ls
git add hw2
git add select.c
git add client.c
git config --list
git status
git remote -v
git checkout -b main
git push origin master
git push origin main
git commit select.c
git commit -m "select"
git push
git push origin master
git push origin main
git push -f origin main
git pull origin main
git -f push origin
git push origin
git push -f origin
git push origin main
git remote add origin https://github.com/Sin-Yejun/Network_teamHW.git
git push origin main
clear
git push origin main
logout
