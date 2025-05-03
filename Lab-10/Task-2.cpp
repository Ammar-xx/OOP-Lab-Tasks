#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream out("vehicles.txt");
    if(out.is_open()==0)
    {
        cout<<"Error opening file\n";
        return 1;
    }
    string txt,id,type,name,year,extraData,certification;
    int i=1;
    while(getline(out,txt))
    {
        istringstream stream(txt);
        getline(stream,type,',');
        getline(stream,id,',');
        getline(stream,name,',');
        getline(stream,year,',');
        getline(stream,extraData,',');
        getline(stream,certification,',');
        cout<<"Vehicle #"<<i<<" Info:\n";
        cout<<"Type: "<<type<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"Extra data: "<<extraData<<endl;
        cout<<"Certification: "<<certification<<endl;
        i++;
    }

    out.close();
}