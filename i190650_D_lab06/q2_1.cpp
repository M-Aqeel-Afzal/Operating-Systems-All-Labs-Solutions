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
int file1=mkfifo("fifo3",0777);
int arr[3]={0,0,0};
int fd=open("fifo2",O_RDONLY);
cout<<"read"<<endl;
char s1[100];
//reading
read(fd,s1,100);
cout<<s1;
char ch;
int charts=0,words=0,lines=0;
//counting
for(int i=0;i<100;i++)
{
if(s1[i]=='.')
lines++;
if(s1[i]==' ')
words++;
charts++;
if(s1[i]==NULL)
break;
}
//storing in int array
arr[0]=charts;
arr[1]=words;
arr[2]=lines;
close(fd);




//back write

int fd1=open("fifo3",O_WRONLY);
cout<<"open agin"<<endl;

write(fd1,arr,12);
cout<<"written agian"<<endl;
close(fd1);



return 0;
}


