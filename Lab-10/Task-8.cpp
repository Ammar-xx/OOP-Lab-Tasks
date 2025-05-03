#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream con("config.txt");
    if(!con)
    {
        cout<<"Error opening file\n";
        return 1;
    }
    con<<"AAAAA";
    con<<"BBBBB";
    con<<"CCCCC";

    con.close();

    fstream conf("config.txt",ios::in | ios::out);
    conf.seekp(5,ios::beg);
    conf<<"XXXXX";

    conf.close();

    ifstream out("config.txt");
    string line;
    getline(out,line);

    cout<<line<<endl;

}