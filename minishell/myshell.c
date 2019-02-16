  1 //这个代码是我们自己来实现一个shell，能够执行一些其它的命令：       
  2 
  3 #include <stdio.h>
  4 #include <stdlib.h>
  5 #include <string.h>
  6 #include <unistd.h>
  7 #include <sys/wait.h>
  8 #include <sys/types.h>
  9 #include <sys/stat.h>
 10 #include <fcntl.h>
 11 
 12 void do_parse(char* buf, char* argv[]) {
 13     if (buf == NULL) {
 14         return;
 15     }   
 16     if (argv == NULL) {
 17         return; 
 18     }   
 19     int i;
 20     int argc = 0;
 21     int status = 0;
 22     
 23     for(i = 0; buf[i]; i++) {
 24         if(!isspace(buf[i]) && status == 0) {
 25             argv[argc++] = buf+i;
 26             status = 1;
 27         } else if(isspace(buf[i])) {
 28             status = 0;
 29             buf[i] = '\0';
 30         }   
 31     }   
 32     argv[argc] = NULL;
 33 }   
 34 
 35 int has_pipe(char* argv[]) {
 36     int i = 1;
 37     //argv[0]是第一个命令                                           
 38     while(argv[i] != NULL) {
 39         if (strcmp(argv[i], "|") == 0) {
 40             argv[i] = NULL;
 41             return i+1;
 42         }
 43         i++;
 44     }
 45     return 0;
 46 }
 47 
 48 int main () {
 49     char* argv[32] = {NULL};
 50     int argc = 0;
 51     char buf[1024] = {0};
 52 
 53     //管道的两个操作符
 54     char* tmp1[8];
 55     char* tmp2[8];
 56     int fd[2];
 57     int ret;
 58     while (1) {
 59         printf("myshell> ");
 60         scanf("%[^\n]%*c", buf);
 61         do_parse(buf, argv);
 62         ret = has_pipe(argv);
 63 
 64         if (ret) {
 65             int i = 0;
 66             int j = ret;
 67             while (argv[i] != NULL){
 68                 tmp1[i] = argv[i];
 69                 i++;
 70             }
 71             tmp1[i] = NULL;
 72             i = 0;
 73             while (argv[j] != NULL){
 74                 tmp2[i++] = argv[j++];
 75             }
 76             tmp2[i] = NULL;
 77 
 78             //创建进程来执行管道
 79             pid_t pid_p;
 80             int fd[2] = {0};
 81             if(pipe(fd) < 0) {
 82                 perror("pipe error: ");
 83                 exit(EXIT_FAILURE);
 84             }
 85             pid_p = fork();
 86             if (pid_p < 0) {
 87                 perror("pid_p error:");
 88                 exit(EXIT_FAILURE);
 89             }else if (pid_p == 0) {
 90                 dup2(fd[0], 0);
 91                 close(fd[1]);
 92                 execvp(tmp2[0], tmp2);
 93             }else {
 94                 dup2(fd[1], 1);
 95                 close(fd[0]);
 96                 execvp(tmp1[0],tmp1);
 97                 wait(NULL);
 98             }
 99         }
100         else
101         {
102             pid_t pid = fork();
103             if (pid == -1)
104             {
105                 perror("pid error: ");
106                 exit(EXIT_FAILURE);
107             }
108             else if (pid == 0)
109             {
110                 execvp(argv[0], argv);
111             }
112             else {
113                 wait(NULL);
114             }
115         }
116         memset(buf, 0, 1024);
117     }
118     return 0;
119 }  