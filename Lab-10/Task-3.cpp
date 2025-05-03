#include <iostream>
#include <fstream>
#include <string>
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
        int num=stoi(year);
        cout<<"Year Integar value for vehicle #"<<i<<" "<<num<<endl;
        i++;
    }

    out.close();
}