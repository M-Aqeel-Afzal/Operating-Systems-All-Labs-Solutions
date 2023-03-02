#include<iostream>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<sys/wait.h>
#include <pthread.h>
using namespace std;
struct file{
	char *filename=new char[20];	
};
void* thread_1(void* arg){
	file *f=(file* )arg;
	char *buf=new char[20000];
	int stream = open(f->filename, O_RDONLY);
	 read(stream, buf,20000);
int count=0;
int i=0;
while(buf[i]!='\0')
{count++;
i++;
}
    cout<<"thread 1 counting of total characters given file: "<<count<<endl; 
}
void* thread_2(void* arg){
	file *f=(file* )arg;
	char *buf=new char[20000];
	int stream = open(f->filename, O_RDONLY);
	 read(stream, buf,20000);
  int count=0;
int i=0;
while(buf[i]!='\0')
{count++;
i++;
}
    cout<<"thread 2 counting of total characters given file: "<<count<<endl; 
}
int main()
{
        file obj1,obj2;
	pthread_t id1,id2;
	
obj1.filename="long.txt";
obj2.filename="small.txt";
	
    
	pthread_create(&id1,NULL,thread_1,(void*)&obj1);
	pthread_create(&id2,NULL,thread_2,(void*)&obj2);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	
    pthread_exit(NULL);
	
}

