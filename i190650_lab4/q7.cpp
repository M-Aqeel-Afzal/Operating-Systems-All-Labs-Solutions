#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int main(int argc, char *argv[])
{

int arr1[5];
char *arr2[] = { NULL };
                                        //input
cout<<"Enter any five numbers: "<<endl;
for(int i=0;i<5;i++)
{
cin>>arr1[i];
}
                                          //sorting
int temp=0;
for (int i=0;i<5;++i)
    {
        for(int j =i+1;j<5;++j)
        {
            if(arr1[i]>arr1[j])
            {
                temp =  arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
        }
    }

                                     ///////sorted arrray
cout<<"sorted array is: "<<endl;
 for (int i=0;i <5;++i)
        cout<<arr1[i]<<endl;
int temp2=0;


                                                 //input to search
cout<<"Please enter the element to search"<<endl;
cin>>temp2;

pid_t childpid =fork();

if(pid_t==0)
    {
        execve(argv[1], cval, arr2);          
            cout<<"exe fail"<<endl;
    }
return 0;
}
