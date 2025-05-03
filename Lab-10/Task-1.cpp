#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream out("vehicles.txt");
    if(out.is_open()==0)
    {
        cout<<"Error opening file\n";
        return 1;
    }
    string txt;
    while(getline(out,txt))
    {
        cout<<txt<<endl;
    }

    out.close();
}