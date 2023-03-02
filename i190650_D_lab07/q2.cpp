#include <iostream>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
using namespace std;
int main()
{
int old_fd,new_fd;
char str[10];
old_fd=open("temp.txt",O_CREAT|O_RDONLY,0777);          //openning file
read(old_fd,str,5);                                 //reading 5 charactars from opened file
write(1,str,5);                      //printing on screen
cout<<endl;


int f2=open("temp1.txt",O_CREAT|O_WRONLY| O_APPEND,0777);             //openning file to append
dup2(f2,1);                                 //calling dup2
write(f2,str,5);                            //appending file
close(f2);
return 0;
}
