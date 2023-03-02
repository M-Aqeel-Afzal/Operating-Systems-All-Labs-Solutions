#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void* thread_fun(void* arg)
{    
cout<<"Exit  from the thread "<<endl; 
cout<<endl;
 return 0;  
}

int main()
{
   
int temp;
    pthread_t t1[5];
    for(int i=0; i<5; i++)
    {
       
        temp=pthread_create(&t1[i], NULL, &thread_fun, NULL); //creation of threads
        if(temp != 0) {
                perror("pthread_creation failed"); 
                pthread_exit(NULL);      
        
       }
       else 
       {
        cout << "Thread " << i+1 << " Created " <<endl;
       }  
       
        cout << "Thread " << i+1<< " Detached " <<endl; 
        pthread_detach(t1[i]);                            //  detaching  
    }
    
    cout<<endl;
    cout<<"again joining the thread"<<endl;
    cout<<endl;
    
    for(int i=0; i<5; i++)
    {
    temp = pthread_join(t1[i], NULL);              // joining 
    if(temp != 0) {
                perror("join failed");
                
        }    
    
    } 
      
  cout<<"COn't join after detaching :("<<endl;    
  pthread_exit(NULL);
  
return 0;
}


