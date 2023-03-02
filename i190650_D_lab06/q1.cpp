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
int file=mkfifo("fifo",0777);
int fd=open("fifo",O_WRONLY);
cout<<"open"<<endl;
int x=100;
write(fd,&x,sizeof(int));
cout<<"written"<<endl;
close(fd);


int fd1=open("fifo",O_RDONLY);
cout<<"read agin"<<endl;
read(fd1,&x,sizeof(int));
cout<<x<<endl;
close(fd1);

return 0;
}


