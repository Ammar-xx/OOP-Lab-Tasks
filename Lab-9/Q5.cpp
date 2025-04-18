#include <iostream>
using namespace std;

class Activity{
	public:
		virtual void calculateCaloriesBurned()=0;
};

class Running:public Activity{
	protected:
		double distance;
		double time;
	public:
		Running(double d,double t):distance(d),time(t){}
		
		void calculateCaloriesBurned()
		{
			double calories=distance*(30+0.5*(distance/(time/60)));
			cout<<"Calories Burned: "<<calories<<endl;
		}
};

class Cycling:public Activity{
	protected:
		double speed;
		double time;
	public:
		Cycling(double s,double t):speed(s),time(t){}
		
		void calculateCaloriesBurned()
		{
			double calories=speed*time;
			cout<<"Calories Burned: "<<calories<<endl;
		}
};

int main()
{
	Running r(6.05,20.5);
	r.calculateCaloriesBurned();
	Cycling c(15.20,0.55);
	c.calculateCaloriesBurned();
}