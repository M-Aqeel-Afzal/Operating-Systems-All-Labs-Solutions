#include<iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
using namespace std;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
struct BankAccounts{
    double account1=0;
    double account2=0;
	double A_Deposit=0;
	double A_Withdrawn=0;
};
void* Deposit(void* arg){
    BankAccounts *obj=(BankAccounts* )arg;
    pthread_mutex_lock(&mut);
	obj->account1 = obj->account1+obj->A_Deposit;
	obj->account2 = obj->account2+obj->A_Deposit;
    pthread_mutex_unlock(&mut);
    cout<<"Your amount after the deposition in account 1 ("<<obj->account1<<") "<<endl;
    cout<<"Your amount after the deposition in account 2 is ("<<obj->account1<<") "<<endl;
    pthread_exit(NULL);
}
void* Withdrawn(void* arg){
    BankAccounts *obj=(BankAccounts* )arg;
    pthread_mutex_lock(&mut);
	obj->account1 = obj->account1 - obj->A_Withdrawn;
	obj->account2 = obj->account2 - obj->A_Withdrawn;
    pthread_mutex_unlock(&mut);
    cout<<"\nYour amount after the withdrawn in account 1  ("<<obj->account1<<") "<<endl;
    cout<<"Your amount after the withdrawn  in account 2 ("<<obj->account1<<") "<<endl;
    pthread_exit(NULL);
}
int main()
{
    BankAccounts obj;
	pthread_t tid;
	int ret;
	int ret2;
    cout<<"Taking input for both Accounts"<<endl<<endl;
    cout<<"Enter deposit amount: ";
	cin>>obj.A_Deposit;
	cout<<"Enter Withdrawn account: ";
	cin>>obj.A_Withdrawn;
    cout<<endl<<endl;
    ret=pthread_create(&tid,NULL,Deposit,(void*)&obj);
    pthread_join(tid, NULL);
    if(ret != 0) {

            perror("pthread_join failed");                
    }    
    else
    {
        Withdrawn(&obj);
        ret2=pthread_cancel(tid);
        if(ret2 != 0) {
            perror("Thread Cancelled");                
        }   
        else
        {
            cout<<"Thread isn't Cancelled"<<endl;
        }
	}
}
