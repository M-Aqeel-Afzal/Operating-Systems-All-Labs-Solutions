#include <iostream>
#include <chrono>
#include <thread>


using namespace std;

void* thread_fun(void* arg)
{    
cout<<"\n>>>>>>>>>>>>>>>>>>      Running\n "<<endl; 
 return 0;  
}

int main()
{
   

    pthread_t t1[5];
    for(int i=0; i<5; i++) //creation of five threads
    {
        cout << "\nThread " << i+1 << " Creation\n " <<endl;
        pthread_create(&t1[i], NULL, &thread_fun, NULL); 
        pthread_join(t1[i], NULL);                         // joining of threads  
        cout<<"\nThread "<<i+1<<" has been joined \n"<<endl;
    }
    
  pthread_exit(NULL);
  
return 0;
}

