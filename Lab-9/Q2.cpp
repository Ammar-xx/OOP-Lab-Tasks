#include <iostream>
using namespace std;

class SmartDevice{
	public:
		
		virtual void turnOn()=0;
		virtual void turnOff()=0;
		virtual bool getStatus()=0;
};

class LightBulb:public SmartDevice{
	private:
		bool isOn;
		int brightness;
	public:
		LightBulb(bool io,int b):isOn(io),brightness(b){}
		
		void turnOn()
		{
			if(!isOn)
			{
				isOn=true;
			}
			else
			{
				cout<<"The bulb is already on\n";
			}
		}
		void turnOff()
		{
			if(isOn)
			{
				isOn=false;	
			}
			else
			{
				cout<<"The bulb is already off\n";
			}
		}
		bool getStatus()
		{
			return isOn;
		}
};

class Thermostat:public SmartDevice{
	private:
		bool isOn;
		double temperature;
	public:
		Thermostat(bool io,double t):isOn(io),temperature(t){}
		
		void turnOn()
		{
			if(!isOn)
			{
				isOn=true;
			}
			else
			{
				cout<<"The Thermostat is already on\n";
			}
		}
		void turnOff()
		{
			if(isOn)
			{
				isOn=false;	
			}
			else
			{
				cout<<"The Thermostat is already off\n";
			}
		}
		bool getStatus()
		{
			return isOn;
		}
};

int main()
{
	LightBulb lb(false,30);
	lb.turnOn();
	cout<<"Lightbulb status: ";
	if(lb.getStatus())
	{
		cout<<"ON\n";
	}
	else
	{
		cout<<"OFF\n";
	}
	lb.turnOff();
	cout<<"Lightbulb status: ";
	if(lb.getStatus())
	{
		cout<<"ON\n";
	}
	else
	{
		cout<<"OFF\n";
	}
	Thermostat t(true,32.7);
	t.turnOff();
	cout<<"Thermostat status: ";
	if(t.getStatus())
	{
		cout<<"ON\n";
	}
	else
	{
		cout<<"OFF\n";
	}
	t.turnOn();
	cout<<"Thermostat status: ";
	if(t.getStatus())
	{
		cout<<"ON\n";
	}
	else
	{
		cout<<"OFF\n";
	}
}