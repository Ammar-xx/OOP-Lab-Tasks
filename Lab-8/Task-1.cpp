#include <iostream>
using namespace std;

class Humidity;

class Temperature {
	private:
    	float temp;

	public:
    	Temperature(float t):temp(t) {}
    	friend float calculateHeatIndex(const Temperature&, const Humidity&);
};

class Humidity {
	private:
    	float humidityPercent;

	public:
    	Humidity(float h):humidityPercent(h) {}
    	friend float calculateHeatIndex(const Temperature&, const Humidity&);
};

float calculateHeatIndex(const Temperature& temper,const Humidity& hum) 
{
    float heat=temper.temp+0.33*hum.humidityPercent-0.7;
    return heat;
}

int main() 
{
    Temperature temper(32);
    Humidity hum(70);

    float heat=calculateHeatIndex(temper,hum);
    cout<<"Calculated Heat Index: "<<heat<<" degree celsius."<<endl;

}
