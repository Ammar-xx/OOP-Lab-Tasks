#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    ifstream out("data_records.txt");
    out.seekg(20,ios::beg);

    string line;
    getline(out,line);
    cout<<line<<endl;
    out.close();
}