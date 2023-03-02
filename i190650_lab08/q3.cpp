#include <iostream>
#include <pthread.h>
#include <string>
using namespace std;
void *printing_fun( void* ptr )
{
     
    cout << endl <<  *(string*)ptr << endl;
    
}


int main()
{
    pthread_t thread1, thread2;

    string msj1 = "Hello i am Thread 1";
    string msj2 = "Hello i am Thread 2";

    int  n1,n2;

     n1 = pthread_create( &thread1, NULL, printing_fun,  &msj1);
     n2 = pthread_create( &thread2, NULL, printing_fun,  &msj2);



     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL);

    return 0;
}

