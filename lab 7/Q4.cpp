#include <iostream>
using namespace std;

class Person{
protected:
    string name,address,phoneNumber,email;
    int id;
public:
    Person(string n,int i,string a,string p,string e):name(n), id(i),address(a),phoneNumber(p),email(e) {}

    virtual void displayInfo() 
	{
        cout<<"Name: "<<name<<endl;
		cout<<"ID: "<<id<<endl;
		cout<<"Address: "<<address<<endl;
		cout<<"Phone: "<<phoneNumber<<endl;
		cout<<"Email: "<<email<<endl;
    }

    void updateInfo(string a,string p,string e) 
	{
        address=a;
        phoneNumber=p;
        email=e;
    }
};

class Student : public Person {
    string course1,course2;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, int i, string a, string p, string e, double g, int year):Person(n, i, a, p, e), GPA(g), enrollmentYear(year) {}

    void enrollCourses(string c1, string c2) 
	{
        course1=c1;
        course2=c2;
    }

    void displayInfo() override 
	{
        Person::displayInfo();
        cout<<"GPA: "<<GPA<<endl;
		cout<<"Enrollment Year: " <<enrollmentYear<<endl;
		cout<<"Courses: " << course1 << ", " << course2 << endl;
    }
};

class Professor : public Person {
    string department, course1, course2;
    double salary;
public:
    Professor(string n, int i, string a, string p, string e, string d, double s):Person(n,i,a,p,e),department(d),salary(s) {}

    void setCourses(string c1, string c2) 
	{
        course1=c1;
        course2=c2;
    }

    void displayInfo() override 
	{
        Person::displayInfo();
        cout<<"Department: "<<department<<endl;
		cout<<"Salary: "<<salary<<endl;
        cout<<"Courses Taught: "<<course1<<", "<<course2<<endl;
    }
};

class Staff : public Person {
    string department, position;
    double salary;
public:
    Staff(string n,int i,string a,string p,string e,string d,string pos,double s):Person(n,i,a,p,e),department(d),position(pos),salary(s) {}

    void displayInfo() override 
	{
        Person::displayInfo();
        cout<<"Department: "<<department<<endl; 
		cout<<"Position: "<<position<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

class Course {
    string courseId, courseName, instructor, schedule;
public:
    Course(string id, string name, string inst, string sch):courseId(id), courseName(name), instructor(inst), schedule(sch) {}

    void registerStudent(Student &s) 
	{
        cout<<"Student registered in "<<courseName<<endl;
    }

    void calculateGrades() 
	{
        cout<<"Calculating grades for "<<courseName<<endl;
    }
};

int main() {
    Student s("Ammar", 101, "123 St", "1234567890", "ammar@gmail.com", 3.8, 2023);
    s.enrollCourses("Math", "Physics");
    
    Professor p("Shahid", 201, "456 St", "9876543210", "shahid@gmail.com", "Calculus", 85000);
    p.setCourses("Math", "Chemistry");
    
    Staff st("John", 301, "789 St", "5555555555", "john@mail.com", "Admin", "Manager", 60000);
    
    Course c("C101", "Math", "Dr. Smith", "MWF 9AM");
    
    s.displayInfo();
    p.displayInfo();
    st.displayInfo();
    c.registerStudent(s);
    c.calculateGrades();
}
