#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() 
{
    ifstream on("vehicles.txt"); 

    if (!on.is_open()) 
    { 
        cerr << "Error oning file!" << endl;
        return 1; 
    }

    string line;
    while (getline(on, line)) 
    {
        istringstream iss(line);

        string type, id, name, year, extraData, certification;

        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, year, ',');
        getline(iss, extraData, ',');
        getline(iss, certification, ',');

        if(type=="AutonomousCar")
        {
            size_t index=extraData.find(':');
            if(index!=string::npos)
            {
                string data=extraData.substr(index+1);
                float num=stof(data);
                cout<<"Vehicle ID: "<<id<<endl;
                cout<<"Software Version: "<<num<<endl;
            }
        }
        else if(type=="ElectricVehicle")
        {
            size_t index=extraData.find(':');
            if(index!=string::npos)
            {
                string data=extraData.substr(index+1);
                int num=stoi(data);
                cout<<"Vehicle ID: "<<id<<endl;
                cout<<"Battery Capacity: "<<num<<endl;
            }
        }
    }

    on.close(); 
}
