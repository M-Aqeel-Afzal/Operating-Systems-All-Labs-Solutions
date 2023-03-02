#include <iostream>
#include <pthread.h>

using namespace std;

struct student{
	string name;
	string rollno;
	double absolute;	
};
void* grading(void* arg){
	student *obj=(student* )arg;
		double total=obj->absolute;
string grade;
        if(total>=90)
	grade="A+";
	else if(total<=89&&total>=86)
	grade="A";
	else if(total<=85&&total>=82)
	grade="A-";
	else if(total<=81&&total>=78)
	grade="B+";
	else if(total<=77&&total>=74)
	grade="B";
	else if(total<=73&&total>=70)
	grade="B-";
	else if(total<=69&&total>=66)
	grade="C+";
	else if(total<=65&&total>=62)
	grade="C";
	else if(total<=61&&total>=58)
	grade="C-";
	else if(total<=57&&total>=54)
	grade="D+";
	else if(total<=53&&total>=50)
	grade="D";
	else if(total<50)
	grade="F";
cout<<"Absolute of student: "<<grade<<endl;
	
}

int main()
{
        student obj;
	pthread_t id1,id2;
	cout<<"enter name"<<endl;
	cin>>obj.name;
cout<<"enter Roll Number"<<endl;
	cin>>obj.rollno;
cout<<"enter absolutes"<<endl;
	cin>>obj.absolute;
  
cout<<"Name of student: "<<obj.name<<endl;
cout<<"Roll Number of student: "<<obj.rollno<<endl;

	pthread_create(&id1,NULL,grading,(void*)&obj);
	

    pthread_exit(NULL);
	
}

