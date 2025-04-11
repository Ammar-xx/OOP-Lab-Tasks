#include <iostream>
#include <string>
using namespace std;

class Teacher;

class Student {
	private:
    	string name;
    	int grades[3];

	public:
    	Student(string n, int g1, int g2, int g3):name(n) 
		{
        	grades[0]=g1;
        	grades[1]=g2;
        	grades[2]=g3;
    	}

    friend class Teacher;
    friend float calculateAverageGrade(Student s);
};

class Teacher {
	public:
    	void displayGrades(Student s) 
		{
        	cout << "Student: " << s.name << endl;
        	cout << "Grades: " << s.grades[0] << ", " << s.grades[1] << ", " << s.grades[2] << endl;
    	}

    	void updateGrade(Student& s,int index,int g) 
		{
        	if (index>=0 && index<3) 
			{
            	s.grades[index]=g;
        	}
    	}
};

float calculateAverageGrade(Student s) 
{
	double avg=(s.grades[0] + s.grades[1]+s.grades[2]) / 3.0;
    return avg;
}

int main() 
{
    Student std("Ammar", 80, 90, 85);
    Teacher t;

    t.displayGrades(std);
    cout << "Average: "<<calculateAverageGrade(std)<<endl;

    t.updateGrade(std,1,95);

    cout<<"After updating grade:"<<endl;
    t.displayGrades(std);
    cout<<"New Average: "<<calculateAverageGrade(std)<<endl;
}
