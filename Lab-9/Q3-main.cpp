#include <iostream>
#include "Book.h"
using namespace std;

int main() 
{
    Book b("2006", "Henry Cavill", "1234567890147");

    cout<<"Book Details:"<<endl;
    cout<<"Title: "<<b.getTitle()<<endl;
    cout<<"Author: "<<b.getAuthor()<<endl;
    cout<<"ISBN: "<<b.getISBN()<<endl;
}
