#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <pthread.h>
using namespace std;
int Sum = 0;
void *countGold(void *p) {

int i;

for (i = 0; i < 10000000; i++) 
{

 Sum += i;

}


return NULL;
}

int main() {
  pthread_t thread1, thread2;
  pthread_create(&thread1, NULL, countGold, NULL);
  pthread_create(&thread2, NULL, countGold, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  cout<<"total sum:  "<<Sum<<endl;
  
  
  cout<<"\n\nIssue in the above Code"<<endl;
  cout<<"Sum variable is access by both the threads beacause it a Globle variable\n";
  cout<<"therefore both the threads are accessing the Sum variable at the same time."<<endl;
  cout<<"Here the Race condition will accur because code is allowing both the threads to update the value of sum"<<endl;
 
  
  return 0;
  

  }

