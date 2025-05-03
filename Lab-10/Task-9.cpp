#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream text("large_log.txt");

    char c;
    int i=0;
    while (1) 
    {
        if(i==10) break;
        text.get(c);
        cout<<c<<endl;
        cout<<"Current Position of Pointer: "<<text.tellg()<<endl;
        i++;
    }

    text.close();
}