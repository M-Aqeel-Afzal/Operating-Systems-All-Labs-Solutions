#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include<iostream>
using namespace std;

int count = 0;
sem_t Mtx;
void* f1(void * arg);
int main(int argc, char* argv[]){
   if(argc != 2){
     cout<<"pass file name"<<endl;
      exit(1);
   }
   sem_init(&Mtx, 0, 1);
   
   pthread_t id1;
   pthread_create(&id1, NULL, f1, (void*)argv[1]);
   pthread_join(id1, NULL);

    sem_destroy(&Mtx);  
  cout<<"total of characters count: "<<count<<endl;
 
   return 0;
}
void* f1(void* args){
 
   char* filename = (char*)args;
   char ch;
   int fd = open(filename, O_RDONLY);

     
   while((read(fd, &ch, 1)) != 0){ 
       sem_wait(&Mtx);
	   count++;
	   sem_post(&Mtx);
   }
   
   close(fd);

   pthread_exit(NULL);
}
