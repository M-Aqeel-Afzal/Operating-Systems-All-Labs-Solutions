#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
//#inlcude <sys /types.h>
#include<errno.h>
using namespace std;
int main(int argc[],char*argv[]){
// Program using Multipile pipes architecture  for addition program

int fd[3][2];
int i;

for(i=0;i<3;i++){
    if(pipe(fd[i])<0)
    {
        cout<<"erro"<<endl;

    }
}

pid_t id=fork();
if(id==0){
    close(fd[0][1]);
    close(fd[1][0]);
    close(fd[2][0]);
    close(fd[2][1]);
    int x;
    if(read(fd[0][0],&x,sizeof(int))<0){
        return 1;

    }
    cout<<"Adding 4\n";
    x+=4;
    cout<<"After adding 4 : "<<x<<endl;
    if(write(fd[1][1],&x,sizeof(int))<0){
        return 2;

    }
    close(fd[0][0]);
    close(fd[1][1]);
    return 0;

}

pid_t id1=fork();
if(id1==0){
    close(fd[0][0]);
    close(fd[0][1]);

    close(fd[1][1]);
    close(fd[2][0]);
    int x;
    if(read(fd[1][0],&x,sizeof(int))<0){
        return 4;
    }
    cout<<"Adding 5\n";
    x+=5;
    cout<<"After adding 5 : "<<x<<endl;
    if (write(fd[2][1],&x,sizeof(int))<0){
    return 5;
    }

close(fd[1][0]);
close(fd[2][1]);
return 0;

}

// parent process

close(fd[0][0]);
close(fd[1][0]);

close(fd[1][1]);
close(fd[2][1]);

int x=0;
if(write(fd[0][1],&x,sizeof(int))<0){

    return 6;
}
if (read(fd[2][0],&x,sizeof(int))<0){
    return 7;
}
cout<<"The result is : "<<x<<endl;
close(fd[0][1]);
close(fd[2][0]);
waitpid(id,NULL,0);
waitpid(id1,NULL,0);

return 0;
}
