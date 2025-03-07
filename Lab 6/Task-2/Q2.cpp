#include <iostream>
using namespace std;

class Vehicle {
	public:
    	string brand;
    	int speed;
    	Vehicle(string b,int s) 
		{
    	    brand=b;
        	speed=s;
    	}

	    void displayDetails() 
		{
    	    cout<<"Brand: "<<brand<<endl;
        	cout<<"Speed: "<<speed<<endl;
    	}
};
class Car:public Vehicle {
	public:
    	int seats;
    	Car(string b,int s,int st):Vehicle(b,s)
		{
    		seats=s;
		}
    	void displayDetails() 
		{
    	    Vehicle::displayDetails();  
    	    cout<<"Seats: "<<seats<<endl;
    	}
};
class ElectricCar:public Car {
	public:
    	int batteryLife;
    	ElectricCar(string b, int s, int st, int bl):Car(b,s,st)
		{
    		batteryLife=bl;
    	}
    	void displayDetails() 
		{
    	    Car::displayDetails();
    	    cout<<"Battery Life: "<<batteryLife<<" hours"<<endl;
    	}
};
int main() 
{
    ElectricCar ec("Tesla",250,5,20);
    ec.displayDetails();
}
