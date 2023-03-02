#include <iostream>
#include <chrono>
#include <thread>
#include<time.h>
using namespace std;
struct arrays{                           //array

    int arr[100];
    
};

    
void* thread1(void* arg){             //thread1
	arrays *obj=(arrays* )arg;
    for(int i=0;i<50;i++)
       { 
	if(obj->arr[i]==2)
	{cout<<"thread1 founded"<<endl;
	 pthread_exit((char *)"yes");}
	}

   
 pthread_exit((char *)"no");

 
}

void* thread2(void* arg){             //thread2
	arrays *obj=(arrays* )arg;
    for(int i=50;i<100;i++)
       {
	if(obj->arr[i]==2)
	{cout<<"thread2 founded"<<endl;
	 pthread_exit((char *)"yes");}
	}

   
 pthread_exit((char *)"no");
 
}


int main()
{
  void* result; 
arrays obj;
srand(time(0));
 cout<<"Genrating 100 Rundom values"<<endl<<endl;
for(int i=0;i<100;i++)                       //genrating rundom array
{obj.arr[i]=((1+rand())%20);
cout<<obj.arr[i]<<"   ";
}
cout<<endl<<endl<<endl;
    pthread_t id[2];          
    
      	pthread_create(&id[0],NULL,thread1,(void*)&obj);         //thread 1 creation
	pthread_join(id[0],&result);
	if(((char*)result)=="yes")                              //condition to check that value is founded
	{
	cout<<"thread1 is Cancelling other threads"<<endl;
	pthread_cancel(id[1]);
	pthread_exit(NULL);
	
	}
	
	pthread_create(&id[1],NULL,thread2,(void*)&obj);        //thread 1 creation
pthread_join(id[1],&result);                                      //condition to check that value is founded
	if(((char*)result)=="yes") 
	{cout<<"thread 2 is Cancelling other threads"<<endl;
	pthread_cancel(id[0]);
	pthread_exit(NULL);
	
	
	}
cout<<"Not found"<<endl;
	
  
return 0;
}
