#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


int main()
{

int array[10];
cout<<"Please enter 10 numbers"<<endl;
for(int i=0 ;i<10;i++)
{
cin>>array[i];

}
    int n = fork(); 
   int i=0;
    if (n > 0) { 
    cout<<"\t\ttrough parrent \n"; 
     cout<<" Even \n";
        for (i = 0; i < 10; i++) { 
            if (array[i] % 2 == 0) 
                cout<<"even \n"<<array[i];
        } 
       
       
    } 
 
    else { 
cout<< "\ttrougn child \n"; 
     cout<<" Odd \n";
        for (i = 0; i < 10; i++) { 
            if (array[i] % 2 != 0) 
                 cout<<"odd \n"<<array[i];
        } 
       
        
    } 
    return 0; 
} 
