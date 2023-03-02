#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

int main()
{

int st=0;
int arr1[5],arr2[5];
int sum1=0,sum2=0;
int arr[10];
cout<<"Please enter 10 numbers"<<endl;
for(int i=0;i<10;i++)             //input from user
cin>>arr[i];
int id;
int fd[2];
pipe(fd);               //pipe is used to get value from child
id=fork();




if(id==0)
{

close(fd[0]);
cout<<"through Child"<<endl;
for(int i=0;i<5;i++)                  //summing for child
{
arr1[i]=arr[i];
sum1=sum1+arr1[i];
}
cout<<endl;
write(fd[1],&sum1,sizeof(id));
cout<<"\nsum in child is: "<<sum1<<endl;         //printing for child
exit(st);
}




else if(id>0)
{
int ch=wait(&st);
cout<<"through parent"<<endl;
for(int i=5;i<10;i++)             //summing for parent
{

arr2[i]=arr[i];
sum2=sum2+arr2[i];


}
cout<<"\nsum in parent is: "<<sum2<<endl;              //printing forparent
cout<<endl;
close(fd[1]);
read(fd[0],&sum1,sizeof(sum1));
sum1=sum1+sum2;                            //total summing
cout<<"total sum is :"<<sum1<<endl;
}




return 0;

}
