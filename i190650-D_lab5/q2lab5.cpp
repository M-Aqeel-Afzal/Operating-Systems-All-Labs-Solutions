#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fstream>
#include<string>
using namespace std;

int main()
{

int st=0;

int s1,s2;

int id;
int fd[2];
pipe(fd);  

int fd1[2];
pipe(fd1);               //pipe is used to get value from child
id=fork();




if(id==0)
{

close(fd[1]);
cout<<"i am Child\n"<<endl;
cout<<"please enter a string to cancatenate "<<endl;
cin>>s1;
read(fd[0],&s2,sizeof(s2));
s2=s2+s1;
cout<<s2<<endl;
write(fd1[1],&s2,sizeof(s2));
exit(st);
}




else if(id>0)
{
string s3;
close(fd[0]);
cout<<" I am parent\n\n "<<endl;
s3="hello";
cout<<"the string is:  "<<s3<<endl;

write(fd[1],&s3,sizeof(s3));
int ch=wait(&st);
cout<<"return to parent"<<endl;
close(fd1[1]);
read(fd1[0],&s3,sizeof(s3));
                        



}






return 0;

}
