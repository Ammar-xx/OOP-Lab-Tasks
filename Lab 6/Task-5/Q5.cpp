#include <iostream>
using namespace std;

class Device{
	public:
		int deviceID;
		bool status;
		Device(int id,bool s)
		{
			deviceID=id;
			status=s;
		}
		void displayDetails()
		{
			cout<<"Device ID: "<<deviceID<<endl;
			if(status)
			{
				cout<<"Status: Available"<<endl;
			}
			else
			{
				cout<<"Status: Unavailable"<<endl;
			}
		}
};
class SmartPhone:virtual public Device{
	public:
		float screensize;
		SmartPhone(int id,bool s,float ss):Device(id,s)
		{
			screensize=ss;
		}
		void displayDetails()
		{
			cout<<"Screen Size: "<<screensize<<endl;
		}
};
class SmartWatch:virtual public Device{
	public:
		bool heartRateMonitor;
		SmartWatch(int id,bool s,bool hrm):Device(id,s)
		{
			heartRateMonitor=hrm;
		}
		void displayDetails()
		{
			if(heartRateMonitor)
			{
				cout<<"heart Rate Monitor: ON"<<endl;
			}
			else
			{
				cout<<"heart Rate Monitor: OFF"<<endl;
			}
		}
};
class SmartWearable:public SmartPhone,public SmartWatch{
	public:
		int stepCounter;
		SmartWearable(int id,bool s,float ss,bool hrm,int count):Device(id,s),SmartPhone(id,s,ss),SmartWatch(id,s,hrm)
		{
			stepCounter=count;
		}
		void displayDetails()
		{
			Device::displayDetails();
			SmartPhone::displayDetails();
			SmartWatch::displayDetails();
			cout<<"Step Count: "<<stepCounter<<endl;
		}
};
int main()
{
	SmartWearable sw(101,true,6.5,true,10000);
    sw.displayDetails();
}