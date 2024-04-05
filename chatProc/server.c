#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define CLNT_MAX 10
#define BUFFSIZE 200

int g_clnt_socks[CLNT_MAX]; // client 소켓을 모아놓은 배열
int g_clnt_count = 0; // client 수
pthread_mutex_t g_mutex;

void send_all_clnt(char* msg, int my_sock){
    pthread_mutex_lock(&g_mutex);
    for(int i = 0; i < g_clnt_count; i++){ // g_clnt_count만큼 반복하기 때문에 send_all이 되는 것.
        if(g_clnt_socks[i] != my_sock){
            printf("send msg: %s", msg);
            write(g_clnt_socks[i], msg, strlen(msg)+1); // **send가 가능하면 send도 사용해보자.
        }
    }
    pthread_mutex_unlock(&g_mutex);
}

void* clnt_connection(void* arg){ // 클라이언트 connect하는 start_routine
    int clnt_sock = (int)arg;
    int str_len = 0;
    char msg[BUFFSIZE];
    int i;

    while(1){
        str_len = read(clnt_sock, msg, sizeof(msg));
        if(str_len == -1){
            printf("clnt[%d] close\n", clnt_sock);
            break;
        }
        send_all_clnt(msg, clnt_sock); // **소켓을 넣어서 보내는 이유를 파악해보자.
        printf("%s\n", msg); // **사용자 아이디도 있어야 하므로 버그 가능(수정 필요)
    }
    
    pthread_mutex_lock(&g_mutex);
    for(i = 0; i < g_clnt_count; i++){
        if(clnt_sock == g_clnt_socks[i]){
            for(; i < g_clnt_count - 1; i++){
                g_clnt_socks[i] = g_clnt_socks[i+1];
                break;
            }//end for
        }//end if
    }//end for
    pthread_mutex_unlock(&g_mutex);
    close(clnt_sock);
    pthread_exit(0);
    
    return NULL;
}

void* client_handler(void*);

int main(int argc, char ** argv){
    int serv_sock;
    int clnt_sock;

    pthread_t t_thread;
    
    struct sockaddr_in clnt_addr;
    int clnt_addr_size;

    pthread_mutex_init(&g_mutex, NULL);

    struct sockaddr_in serv_addr;
    serv_sock = socket(PF_INET, SOCK_STREAM, 0); // socket 생성
    // PF_INET=IPv4, SOCK_STREAM=TCP, 0=1,2번째 인덱스에 따라 프로토콜이 결정됨(TCP)

    serv_addr.sin_family = AF_INET; // 소켓 bind 설정
    // AF_INET=address IPv4로 설정할 때 사용
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 소켓 bind할 때 어떤 주소로 할 지 설정
    // htonl=호스트의 오더 방식을 네트워크오더 (long)방식으로 변경, INADDR_ANY=현재 PC의 IP주소
    serv_addr.sin_port=htons(7090);
    // 7989=임의의 포트 번호

    // bind 함수는 소켓의 정보를 구별하기 위해 소켓의 정보를 담는다.
    if(bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1){
        printf("bind error\n");
    }

    if(listen(serv_sock, 5) == -1){ // 5=대기할 수 있는 유저의 큐 크기
        printf("listen error\n");
    }

    char buff[200]; // client 메시지가 담긴 배열
    int recv_len = 0; // 메시지 길이
    while(1){
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
                    // accept로 client의 정보(IP주소)를 넘김.
                    // 여기에 담긴 IP로 사용자를 관리할 수 있음
        pthread_mutex_lock(&g_mutex);
         g_clnt_socks[g_clnt_count++] = clnt_sock;
        pthread_mutex_unlock(&g_mutex);

        pthread_create(&t_thread, NULL, clnt_connection, (void*)clnt_sock);
    }

    return 1;
}