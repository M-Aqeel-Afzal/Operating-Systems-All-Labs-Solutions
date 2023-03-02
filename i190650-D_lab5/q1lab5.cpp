#include <iostream>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>

using namespace std;


int main()
{
   
   int flag=0;
   int sum=0;
   int fd[2];
   int exeption= pipe(fd); 
   int num;
   cout<<"Enter the size "<<endl;
   cin>>num;   
   int arr[num];
   cout<<"Enter values of array"<<endl;
   for(int i=0;i<num;i++)
   {
   cin>>arr[i];
   
   }
   

pid_t processid=fork();

if(processid>0)
{
pid_t childid=wait(&flag);
int flag1=0;

pid_t newprocess=fork();
if(newprocess>0)
{

pid_t newchildid=wait(&flag1);
int childsum1=0,childsum=0;
close(fd[1]);
read(fd[0],&childsum,sizeof(childsum));

for(int i=num/2;i<num;i++)
{

childsum1+=arr[i];

}
cout<<"prent sum is:"<<childsum1<<endl;
childsum=childsum+childsum1;
cout<<"final sum is "<<childsum<<endl;

}
else {
int newchildsum=0;
read(fd[0],&newchildsum,sizeof(newchildsum));
for(int i=num/3;i<num/2;i++)
{

newchildsum+=arr[i];

}
cout<<"child 1 sum is:"<<newchildsum<<endl;
close(fd[0]);
write(fd[1],&newchildsum,sizeof(newchildsum));
exit(flag1);
}

}

else
{

int childsum=0;

for(int i=0;i<num/3;i++)
{

childsum+=arr[i];

}
cout<<"child 0 sum is:"<<childsum<<endl;
close(fd[0]);
write(fd[1],&childsum,sizeof(childsum));
exit(flag);
}


return 0;
}
