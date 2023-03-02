#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
using namespace std;
int main()
{
int st=0;
int arr[10]={1,2,3,4,5,6,7,8,9,10};
int id;
id=fork();
if(id==0)
{
cout<<"through Child"<<endl;
for(int i=0;i<5;i++)
{
cout<<arr[i]<<" ";

}
cout<<endl;
exit(st);
}
else if(id>0)
{
int ch=wait(&st);
cout<<"through parent"<<endl;
for(int i=5;i<10;i++)
{
cout<<arr[i]<<" ";

}

cout<<endl;
}




return 0;

}
