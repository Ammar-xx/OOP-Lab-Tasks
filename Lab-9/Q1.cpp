#include <iostream>
using namespace std;

class Vehicle{
	protected:
		string model;
		double rate;
	public:
		Vehicle(string m,double r):	model(m),rate(r){}
		
		virtual double dailyRate()=0;
		
		virtual void display()=0;
};

class Car:public Vehicle{
	public:
		Car(string m,double r):Vehicle(m,r){}
		
		double dailyRate()
		{
			return rate;
		}
		
		void display()
		{
			cout<<"Car Model: "<<model<<endl;
			cout<<"Car Rate: "<<rate<<endl;
		}
};

class Bike:public Vehicle{
	public:
		Bike(string m,double r):Vehicle(m,r){}
		
		double dailyRate()
		{
			return rate;
		}
		
		void display()
		{
			cout<<"Bike Model: "<<model<<endl;
			cout<<"Bike Rate: "<<rate<<endl;
		}
};

int main()
{
	Car c("Mercedes C-180",100000.50);
	cout<<"The daily rate of the car is "<<c.dailyRate()<<endl;
	c.display();
	Bike b("Yamaha",11000.35);
	cout<<"The daily rate of the bike is "<<b.dailyRate()<<endl;
	b.display();
}