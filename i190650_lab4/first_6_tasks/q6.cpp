#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
pid_t childpid =fork();
if(childpid==0){
cout<<"I am a child proccess with id "<<getpid()<<endl;
cout<<"The next statement is execl and ls will run"<<endl;
cout<<"\n\nExecve working(cat commond)\n\n"<<endl;
char *env[] = {"export TERM=vt100","PATH=/bin:/usr/bin",NULL};
execle("/bin/cat","cat","a.out",NULL,env);
cout<<"Execlfailed"<<endl;
}
else if(childpid>0){
wait(NULL);
cout<<"\nI am parent process with pid";
cout<<" \n\nfinishing after wait\n"<<getpid()<<endl;



}
return 0;
}
