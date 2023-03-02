#include <iostream>
#include <pthread.h>

using namespace std;

struct arrays{

    int arr1[100];
    int arr2[100];
    int size=0;
};
void* addition(void* arg){
	arrays *obj=(arrays* )arg;
    int final_arr[100];
    for(int i=0;i<obj->size;i++)
        final_arr[i]=obj->arr1[i]+obj->arr2[i];

    cout<<"Final array: "<<endl;
    for(int i=0;i<obj->size;i++)
        cout<<final_arr[i]<<"   ";
        cout<<endl;

 pthread_exit(NULL);

}

int main()
{
    arrays obj;
	pthread_t id;

    cout<<"enter size of each array: "<<endl;
    cin>>obj.size;

    cout<<"input for first array "<<endl;
    for(int i=0;i<obj.size;i++)
        cin>>obj.arr1[i];
    
    cout<<"input for second array "<<endl;
    for(int i=0;i<obj.size;i++)
        cin>>obj.arr2[i];

	pthread_create(&id,NULL,addition,(void*)&obj);
	pthread_join(id,NULL);
    return 0;
}
