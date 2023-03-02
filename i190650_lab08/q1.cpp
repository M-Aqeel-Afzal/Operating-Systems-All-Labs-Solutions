#include <iostream>
#include <pthread.h>

using namespace std;

struct Array{
	int arr1[10];	
};
void* thread1(void* arg){
	Array *arr2=(Array* )arg;
	for(int i=0;i<5;i++){
        cout<<arr2->arr1[i]<<"  ";
    }
    cout<<endl;  
}
void* thread2(void* arg){
	Array *arr2=(Array* )arg;
	for(int i=5;i<10;i++){
        cout<<arr2->arr1[i]<<"  ";
    }
    cout<<endl;  
}
int main()
{
        Array obj;
	pthread_t id1,id2;
	
cout << "Enter 10 Numbers  "<<endl;
    for(int i=0;i<10;i++){
	
	cin>>obj.arr1[i];
    }
	pthread_create(&id1,NULL,thread1,(void*)&obj);
	pthread_create(&id2,NULL,thread2,(void*)&obj);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	
    pthread_exit(NULL);
	
}

