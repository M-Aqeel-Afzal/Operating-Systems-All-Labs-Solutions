
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<iostream>
 #include<sys/wait.h>
using namespace std;
int main()
{
int fd1;
 cout<<"parent process "<<getpid()<<endl;      //printing id to screen
 int fd = open("temp2.txt",O_WRONLY);      //openning file to write
 
 int pid = fork(); //fork call
                      
 if(pid==0){
 fd1= dup(1); 
 dup2(fd,1);        //redirecting standrad output to file
 
 cout<<"child 1 "<<getpid()<<endl;     //printing in file
 
 
 dup2(fd1,1);               //restoring to standrad output
 }
else if(pid>0)
{
wait(NULL);
 cout<<"parent Process "<<getpid()<<endl;
 cout<<endl;
 
 close(fd);
}
 
    return 0;
}
