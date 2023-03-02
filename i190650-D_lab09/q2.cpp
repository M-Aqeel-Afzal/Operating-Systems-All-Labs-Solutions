#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void* thread_fun(void*)
{
    
cout<<"Thread runing"<<endl<<endl; 
 
}

int main()
{
   

    pthread_t id[5];          //  creating five threads. 
    for(int i=0; i<5; i++)
    {
       cout << "thread: " << i+1 << " is creating "<<endl <<endl; 
       pthread_create(&id[i], NULL, &thread_fun, NULL); 
       cout << "Thread " << i+1 << "  detached "<<endl <<endl; 
       pthread_detach(id[i]);                                    //detaching
    }
    
    for(int i=0; i<5; i++)  
    {
         pthread_join(id[i], NULL);                            //joining 
    }
    
  pthread_exit(NULL);
  
return 0;
}
