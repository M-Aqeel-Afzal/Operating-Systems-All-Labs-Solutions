 
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
using namespace std;
sem_t chairs, b_chair;
int n=0;
void* BarberCutting(void* argv){
    sem_wait(&chairs);
n++;
cout<<"customer entering "<<n<<endl;
sleep(1);
sem_wait(&b_chair);
sem_post(&chairs);
cout<<"barber is cutting hair of customer "<<n<<endl;
sleep(1);
sem_post(&b_chair);
pthread_exit(NULL);
}
int main(){
    sem_init(&chairs,0,5);
    sem_init(&b_chair,0,1);
    cout<<" barber wake up\n";
    pthread_t tid[7];
    for(int i=0;i<7;i++){
        pthread_create(&tid[i], NULL, BarberCutting,NULL);
        pthread_join(tid[i],NULL);
    }
    cout<<"Barber Sleeping again\n";
return 0;
}


