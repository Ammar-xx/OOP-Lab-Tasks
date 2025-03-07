#include <iostream>
using namespace std;
class Person{
	public:
		string name;
		int age;
		Person(string n,int a)
		{
			name=n;
			age=a;
		}
		void displayDetails()
		{
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
		}
};
class Teacher:virtual public Person{
	public:
		string subject;
		Teacher(string n,int a,string s):Person(n,a)
		{
			subject=s;
		}
		void displayDetails()
		{
			cout<<"Subject: "<<subject<<endl;
		}
};
class Researcher:virtual public Person{
	public:
		string researchArea;
		Researcher(string n,int a,string ra):Person(n,a)
		{
			researchArea=ra;
		}
		void displayDetails() {
			cout<<"Research Area: "<<researchArea<<endl;
		}
};
class Professor:public Researcher,public Teacher{
	public:
		int publications;
		Professor(string n,int a,string s,string ra,int p):Person(n,a),Teacher(n,a,s),Researcher(n,a,ra)
		{
			publications=p;
		}
		void displayDetails() 
		{
			Person::displayDetails();
			Teacher::displayDetails();
        	Researcher::displayDetails();
			cout<<"Publications: "<<publications<<endl;
		}
};
int main()
{
	Professor p("John",40,"Chemistry","Extinct Animal Fossils",5);
	p.displayDetails();
}