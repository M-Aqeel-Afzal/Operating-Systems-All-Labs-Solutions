#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<iostream>
#include <unistd.h>
#include <fcntl.h> 
#include <pthread.h>

using namespace std;

void *thread_creating(void *ptr)
{
	cout<<"Thread: "<<(long int)ptr<<endl;
       
        pthread_exit(NULL);
}

int main()
{

        pthread_t threads_array[5];

        long thread_id;
        for(thread_id = 1; thread_id <= 5; thread_id++) {
                int temp;
                temp =  pthread_create(&threads_array[thread_id], NULL, &thread_creating, (void*)thread_id);
                if(temp!= 0) 
		{
                        cout<<"Threat is not created"<<endl;
                        exit(1);
                }
        }

        pthread_exit(0);
        return 0;
}
