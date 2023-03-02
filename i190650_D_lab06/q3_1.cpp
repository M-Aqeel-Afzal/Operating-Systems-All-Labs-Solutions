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
int file1=mkfifo("fifo4",0777);
int fd=open("fifo4",O_RDONLY);

char s1[100];
//reading
read(fd,s1,100);
cout<<s1;

cout<<"my name is"<<endl;
cin.getline(s1,100);
int file=mkfifo("fifo5",0777);

int fd1=open("fifo5",O_WRONLY);
write(fd1,s1,100);
close(fd1);


return 0;
}

