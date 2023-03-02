#include<iostream>
#include<unistd.h>  
#include<string.h> 
#include<stdlib.h> 
#include<sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;
int main()
{
char s1[100];

cout<<"what is your name"<<endl;
cin.getline(s1,100);
int file=mkfifo("fifo4",0777);

int fd=open("fifo2",O_WRONLY);
write(fd,s1,100);

close(fd);

int file1=mkfifo("fifo5",0777);
int fd1=open("fifo5",O_RDONLY);

char s2[100];
//reading
read(fd1,s2,100);
cout<<s2;
close(fd1);
return 0;
}

