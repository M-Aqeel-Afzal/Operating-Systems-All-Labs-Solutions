#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

using namespace std;
int main(){
int id= fork();
char arr[5]={'A','Q','E','E','L'};

if( id>0 ) { 
    cout<<arr[0]<<endl;
	id = fork();
	
    if(id==0){
        cout<<arr[2]<<endl;
		id=fork();

    		if(id>0){
            cout<<arr[3]<<endl;
    		id=fork();	
			  
                if(id>0){
                cout<<arr[4]<<endl;
		
        		}
			}
	}

}
    else if ( id == 0 ) { 
    cout<<arr[1]<<endl;
    }
return 0;
}
