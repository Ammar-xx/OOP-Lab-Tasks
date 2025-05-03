#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream sen("sensor_log.txt");
    cout<<"Current Position of Pointer: "<<sen.tellp()<<endl;
    sen<<"Sensor 1: 25.5 C\n";
    cout<<"Current Position of Pointer: "<<sen.tellp()<<endl;
    sen<<"Sensor 2: 98.1 %RH\n";
    cout<<"Current Position of Pointer: "<<sen.tellp()<<endl;

    sen.close();
}