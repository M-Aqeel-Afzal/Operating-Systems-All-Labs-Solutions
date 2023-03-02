#include<iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
using namespace std;
struct accounts{                    //accounts 
    double account_balance=0;
	double deposit=0;
	double withdraw=0;
};
void* Deposit_fun(void* arg){                      //deposite 
    accounts *obj=(accounts* )arg;
	obj->account_balance = obj->account_balance+obj->deposit;
    cout<<"Amount after the deposition is: "<<obj->account_balance<<endl;
}
void* Withdrawn_fun(void* arg){                   // withdraw
    accounts *obj=(accounts* )arg;
	obj->account_balance = obj->account_balance - obj->withdraw;
    cout<<"Amount after the withdrawn is: "<<obj->account_balance<<endl;
}
int main()
{
    accounts obj;
	pthread_t tid;
	int temp1;
	int temp2;
    cout<<"Enter deposite amount: ";
	cin>>obj.deposit;
	cout<<"\nEnter withdraw amount: ";
	cin>>obj.withdraw;
    	cout<<endl;
    temp1=pthread_create(&tid,NULL,Deposit_fun,(void*)&obj);
    pthread_join(tid, NULL);
    if(temp1 != 0) {

            perror("join failed");                
    }    
    else
    {
        Withdrawn_fun(&obj);
        temp2=pthread_cancel(tid);
        if(temp2 != 0) {
            perror("Thread Cancelled");                
        }   
        else
        {
            cout<<"Thread is not Cancelled"<<endl;
        }
	}
    
    pthread_join(tid, NULL);
}
