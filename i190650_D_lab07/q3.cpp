#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include<string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include<sys/stat.h>
//#inlcude <sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<time.h>
using namespace std;
int  main(int argc[],char *argv[]){

        pid_t pid;
        int pipe1[2];
        pipe(pipe1);
        pid=fork();
        if(pid==0)
        {
            
            close(pipe1[0]);
            dup2(pipe1[1],1);
            close(pipe1[1]);
            int f1=open("temp3.txt",O_CREAT|O_RDONLY,0777);
            dup2(f1,0);
            close(f1);
            execlp("/bin/cat","cat",NULL);
        }
        else if (pid>0)
        {
            //wait(NULL);
            pid=fork();
                if(pid==0){
                   
                    close(pipe1[1]);
                    dup2(pipe1[0],0);
                    close(pipe1[0]);
                    int f2=open("output.txt",O_CREAT|O_WRONLY,0777);
                    dup2(f2,1);
                    close(f2);
                    execlp("sort","sort",NULL);
                }
                 else if(pid>0){
			wait(NULL);
                     /*
                     close(pipe1[1]);
                     dup2(pipe1[0],0);
                     close(pipe1[0]);
                     int f2=open("temp4.txt",O_CREAT|O_WRONLY,0777);
                     dup2(f2,1);
                     close(f2);
                     execlp("wc","wc",NULL);*/
                 }
            close(pipe1[1]);
            close(pipe1[0]);
            
        }

}
