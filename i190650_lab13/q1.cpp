#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include<unistd.h>

using namespace std;

sem_t waitingchairs, Ta;
sem_t TA_available;
bool TA_sleeping=false;
bool flag=false;

void checking(int st){
    if(!TA_sleeping)
        cout<<"Student "<<st<<" is waking up the TA.\n "<<endl;
    TA_sleeping=true;

    cout<<"Student "<<st<<" is entered the TA Office\n "<<endl;
    cout<<"TA is checking the assignment of the student: "<<st <<endl;
    sleep(1);
}

void* student(void*arg){
    int st=*(int*)arg;
    cout<<"Student "<<st<<" is want the TA But TA is busy\n "<<endl;
    sem_wait(&waitingchairs);
    cout<<"Student "<<st<<" is sitting on the chair.\n "<<endl;
    while(!flag){
        sem_wait(&TA_available);
        cout<<"Ta is not available but Student "<<st<<" is waiting for TA\n"<<endl;
        sem_post(&TA_available);
        cout<<"TA entered the room \n";
        flag=true;
    }
    sem_wait(&Ta);
    sem_post(&waitingchairs);
    checking(st);
    cout<<"Student "<<st<<" leave the TA's room\n"<<endl;
    sem_post(&Ta);
    pthread_exit(NULL);

}


int main(){
    
    pthread_t tid[5];

    sem_init(&waitingchairs,0,3);
    sem_init(&Ta,0,1);
    sem_init(&TA_available,0,1);

    int ids[5];

    for(int i=0,j=1;i<5;i++,j++)
        ids[i]=j;
for(int i=4;i>=0;i--)
pthread_create(&tid[i],NULL,&student,(void*)&ids[i]);

for(int i=4;i>=0;i--)
        pthread_join(tid[i],NULL);
      
    cout<<"TA  sleeps Again "<<endl;
}
