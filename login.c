#include  <unistd.h>
#include  <sys/types.h>       /* basic system data types */
#include  <sys/socket.h>      /* basic socket definitions */
#include  <netinet/in.h>      /* sockaddr_in{} and other Internet defns */
#include  <arpa/inet.h>       /* inet(3) functions */
#include  <netdb.h>           /*gethostbyname function */

#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <signal.h>
#include <time.h>

#define MAXLINE 1024
char *encrypt(const char *input);
void repost(int t);
void post(int sockfd);
void resetTimer();
void printSysCurrentTime();
//void tellme(int i);
int fd;
char *name;
char *pwd;
static const char *servInetAddr = "222.24.19.190";
static const int servPort = 8080;
struct sockaddr_in servaddr;
//char serialNo[20];

struct post_msg {
    char *userip;
    char *basip;
    char *userDevPort;
    char *userStatus;
    char *serialNo;
    char *language;
};

struct post_msg repost_msg = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

int main(int argc, char **argv)
{
    name = argv[1];
    pwd = encrypt(argv[2]);

    fd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(servPort);
    inet_pton(AF_INET, servInetAddr, &servaddr.sin_addr);

    post(fd);

    resetTimer();
    signal(SIGALRM, repost);
    //signal(SIGPIPE, tellme);

    while (1) {
        pause();
    }
    printf("hope not run here\n");

    close(fd);

    exit(0);
}
/*
void tellme(int i)
{
    printf("tellme : SIGPIPE\n");
}
*/
void post(int sockfd)
{
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        return ;
    }

    char data[1836];
    char buf[128];
    char *head = "POST /portal/pws?t=li HTTP/1.1\r\nHost: 222.24.19.190:8080\r\nUser-Agent: Mozilla/5.0\r\nAccept: application/json, text/javascript, */*; q=0.01\r\nAccept-Language: en-US,en;q=0.5\r\nAccept-Encoding: gzip, deflate\r\nContent-Type: application/x-www-form-urlencoded; charset=UTF-8\r\nX-Requested-With: XMLHttpRequest\r\nReferer: http:\/\/222.24.19.190:8080/portal/index_default.jsp\r\nContent-Length: %d\r\nConnection: keep-alive\r\nCache-Control: no-cache\r\n\r\n";

    char *content_fmt_1 = "userName=%s&userPwd=%s&serviceType=";
    //char *content_fmt_2 = "&serviceType=&isSavePwd=on&userurl=http%3A%2F%2Fwww.baidu.com&userip=202.117.132.109&basip=&language=Chinese&portalProxyIP=222.24.19.190&portalProxyPort=50200&dcPwdNeedEncrypt=1&assignIpType=0&appRootUrl=http%3A%2F%2F222.24.19.190:8080%2Fportal%2FmanualUrl=&manualUrlEncryptKey=rTCZGLy2wJkfobFEj0JF8A%3D%3D";
    //char *content_fmt_2 = "&language=Chinese&portalProxyIP=222.24.19.190&portalProxyPort=50200&dcPwdNeedEncrypt=1&assignIpType=0&manualUrlEncryptKey=rTCZGLy2wJkfobFEj0JF8A%3D%3D";
    //printf("%s\n", pwd);

    sprintf(buf, content_fmt_1, name, pwd);
    free(pwd);

    //strcat(buf, content_fmt_2);
    //printf("%s\n", buf);
    int contentLength = strlen(buf);
    sprintf(data, head, contentLength);

    //sprintf(data, head, contentLength);
    strcat(data, buf);

    if (write(sockfd, data, strlen(data)) < 0) {
        perror("post write");
    }

    char recvbuf[2048];
    while (1) {
        int ret = recv(sockfd, recvbuf, 256, 0);
        //printf("recv:%d\nbuf : %s\n", ret, recvbuf);
        if (ret < 0) {
            perror("post recv");
            close(sockfd);
            return ;
        } else if (ret == 0) {
            // shutdown
            //printf("shutdown\n");
            close(sockfd);
            break;
        }
        //printf("recvbuf = %s\n", recvbuf);
        //        char *data_start = strchr(recvbuf, '{');
        //        data_start++;   // data_start位于 { 第一个位置。
        //        char *start = data_start, *end = start;


        //        // errorNumber
        //        start = strchr(start, ':');
        //        end = strchr(start, ',');

        //        // heartBeatCyc
        //        start = strchr(start, ':');
        //        end = strchr(start, ',');

        //        // heartBeatTimeoutMaxTime
        //        start = strchr(start, ':');
        //        end = strchr(start, ',');

        //        // userDevPort
        //        start = strchr(start, ':');
        //        end = strchr(start, ',');

        //        // userStatus
        //        start = strchr(start, ':');
        //        end = strchr(start, ',');

        //        // serialNo
        //        start = strchr(start, ':');
        //        end = strchr(start, ',');

        //        repost_msg.serialNo = malloc(10);
        //        strncpy(repost_msg.serialNo, start + 1, end - start - 1);
        //        printf("repost_msg.serialNo:%s\n", repost_msg.serialNo);

        //        // ifNeedModifyPwd
        //        start = strchr(start, ':');
        //        end = strchr(start, ',');

        //        // browserUrl
        //        start = strchr(start, ':');
        //        end = strchr(start, ',');

        //        // clientPrivateIp
        //        start = strchr(start, ':');
        //        end = strchr(start, ',');

        //        repost_msg.userip = malloc(16);
        //        strncpy(repost_msg.userip, start + 1, end - start - 1);
        //        printf("repost_msg.userip:%s\n", repost_msg.userip);

        //        // nasIp
        //        // clientLanguage
        //        // ifTryUsePopup Window
        //        // portalLink

        char *pos = strstr(recvbuf, "serialNo\":");
        if (pos != NULL) {
            repost_msg.serialNo = malloc(10);
            pos = strchr(pos, ':');
            char *pos_end = strchr(pos, ',');
            //printf("No length = %d\n", pos_end - pos);
            strncpy(repost_msg.serialNo, pos + 1, pos_end - pos - 1);
            repost_msg.serialNo[pos_end - pos - 1] = '\0';
            //printf("repost_msg.serialNo=%s\n", repost_msg.serialNo);
        }

        pos = strstr(recvbuf, "clientPrivateIp\":");
        if (pos != NULL) {
            repost_msg.userip = malloc(16);
            pos = strchr(pos, ':');
            //pos += 10;
            char *pos_end = strchr(pos, ',');
            //printf("No length = %d\n", pos_end - pos);
            strncpy(repost_msg.userip, pos + 1, pos_end - pos - 1);
            repost_msg.userip[pos_end - pos - 1] = '\0';
            //printf("repost_msg.userip=%s\n", repost_msg.userip);
        }
    }
    //write(sockfd, data, index);

    // http head
    /*
        POST /portal/pws?t=li HTTP/1.1\r\n\
        Host: 222.24.19.190:8080\r\n\
        User-Agent: Mozilla/5.0\r\n\
        Accept: application/json, text/javascript, *\/*; q=0.01\r\n\
        Accept-Language: en-US,en;q=0.5\r\n\
        Accept-Encoding: gzip, deflate\r\n\
        Content-Type: application/x-www-form-urlencoded; charset=UTF-8\r\n\
        X-Requested-With: XMLHttpRequest\r\n\
        Referer: http:\/\/222.24.19.190:8080/portal/index_default.jsp\r\n\
        Content-Length: 345\r\n\
        Connection: keep-alive\r\n\
        Pragma: no-cache\r\n\
        Cache-Control: no-cache\r\n\
        \r\n
*/
    // content
    /*
                userName=1203210053
                userPwd=NzUzOTUx
                serviceType=
                isSavePwd=on
                userurl=http://www.baidu.com
                userip=202.117.132.109
                basip=
                language=Chinese
                portalProxyIP=222.24.19.190
                portalProxyPort=50200
                dcPwdNeedEncrypt=1
                assignIpType0
                appRootUrl=http://222.24.19.190:8080/portal/manualUrl=
                manualUrlEncryptKey=rTCZGLy2wJkfobFEj0JF8A%3D%3D
*/
}

void repost(int t)
{
    //printf("repost\n");

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        return ;
    }

    char data[1836];
    char buf[128];
    //"POST /portal/pws?t=hb HTTP/1.1\r\nHost: 222.24.19.190:8080\r\nUser-Agent: Mozilla/5.0\r\nAccept: application/json, text/javascript, */*; q=0.01\r\nAccept-Language: en-US,en;q=0.5\r\nAccept-Encoding: gzip, deflate\r\nContent-Type: application/x-www-form-urlencoded; charset=UTF-8\r\nX-Requested-With: XMLHttpRequest\r\nReferer: http:\/\/222.24.19.190:8080/portal/index_default.jsp\r\nContent-Length: %d\r\nConnection: keep-alive\r\nCache-Control: no-cache\r\n\r\n";
    char *head = "POST /portal/pws?t=hb HTTP/1.1\r\nHost: 222.24.19.190:8080\r\nUser-Agent: Mozilla/5.0\r\nAccept: application/json, text/javascript, */*; q=0.01\r\nAccept-Language: en-US,en;q=0.5\r\nAccept-Encoding: gzip, deflate\r\nContent-Type: application/x-www-form-urlencoded; charset=UTF-8\r\nX-Requested-With: XMLHttpRequest\r\nContent-Length: %d\r\nConnection: keep-alive\r\nCache-Control: no-cache\r\n\r\n";

    // userip
    // basip
    // userDevPort
    // userStatus
    // serialNo
    // language
    // e_d

    //    char *content_fmt_1 = "userDevPort=Old_center1-vlan-09-0132%40vlan&userStatus=99&serialNo=%s&language=Chinese&e_d=";
    char *content_mid = "userDevPort=Old_center1-vlan-09-0132%40vlan&userStatus=99&";
    char *content_end = "language=Chinese&e_d=";
    //userip=202.117.132.109&userDevPort=Old_center1-vlan-09-0132%40vlan&userStatus=99&serialNo=14977&language=Chinese&e_d=
    strcpy(buf, "");
    if (repost_msg.userip) {
        sprintf(data, "userip=%s&", repost_msg.userip);
        strcat(buf, data);
    }
    strcat(buf, content_mid);
    if (repost_msg.serialNo) {
        sprintf(data, "serialNo=%s&", repost_msg.serialNo);
        strcat(buf, data);
    }
    strcat(buf, content_end);

    int contentLength = strlen(buf);
    sprintf(data, head, contentLength);
    //sprintf(data, head, 0);

    strcat(data, buf);
    //strcat(data, content_fmt_1);
    //printf("ready to write, %d\n%s\n", strlen(data), data);

    if (send(fd, data, strlen(data), 0) < 0) {
        perror("repost send");
    }

    resetTimer();
    //printSysCurrentTime();
}

void resetTimer()
{
    alarm(10 * 60);
}

char *encrypt(const char *input) {
    char *keyStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    char *output;
    output = malloc(128);

    char chr1, chr2, chr3, enc1, enc2, enc3, enc4;
    int i = 0;
    int length = strlen(input);
    int n = 0;
    while (i < length) {
        chr1 = input[i++];
        chr2 = input[i++];
        chr3 = input[i++];

        enc1 = chr1 >> 2;
        enc2 = ((chr1 & 3) << 4) | (chr2 >> 4);
        enc3 = ((chr2 & 15) << 2) | (chr3 >> 6);
        enc4 = chr3 & 63;

        output[n++] = keyStr[(int)enc1];
        output[n++] = keyStr[(int)enc2];

        if (!chr2) {
            output[n++] = '%';
            output[n++] = '3';
            output[n++] = 'D';
            output[n++] = '%';
            output[n++] = '3';
            output[n++] = 'D';
            //enc3 = enc4 = 64;
        } else if (!chr3) {
            //enc4 = 64;
            output[n++] = keyStr[(int)enc3];
            output[n++] = '%';
            output[n++] = '3';
            output[n++] = 'D';
        } else{
            output[n++] = keyStr[(int)enc3];
            output[n++] = keyStr[(int)enc4];
        }
    }
    return output;
}

void printSysCurrentTime()
{
    time_t cur = time(NULL);
    time(&cur);
    char *curstr = ctime(&cur);
    printf("%s\n", curstr);
}
