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
char s1[100]="I am aqeel afzal.";

int arr[3];
cout<<endl<<"writinf"<<endl;
int file=mkfifo("fifo2",0777);

int fd=open("fifo2",O_WRONLY);
write(fd,s1,100);
cout<<"written"<<endl;
close(fd);

//reading
int fd1=open("fifo3",O_RDONLY);
cout<<"read agin"<<endl;
read(fd1,arr,12);
cout<<"chars  "<<arr[0]<<endl;
cout<<"words  "<<arr[1]<<endl;
cout<<"lines  "<<arr[2]<<endl;

close(fd1);

return 0;
}

