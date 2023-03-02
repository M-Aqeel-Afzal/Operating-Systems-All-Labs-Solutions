#include <iostream>
#include <pthread.h>
using namespace std;

void* even_Odd_check(void* ptr){
	
	if(*(int*)ptr%2==0)  
    {
        cout<<"Number is even"<<endl;
    }
    else 
    cout<<"Odd number";    
}
int main()
{
	pthread_t thread1_id,thread2_id1;
	int obj1;
	cout << "ENTER Number: "<<endl;
	cin>>obj1;
	pthread_create(&thread1_id,NULL,even_Odd_check,&obj1);
	pthread_join(thread1_id,NULL);
	pthread_exit(NULL);
	
}

