#include <iostream>
#include <string>
using namespace std;

class Librarian;

class Book {
	private:
    	string title;
    	float price;

	public:
    	Book(string t,float p):title(t),price(p) {}
    	friend class Librarian;
};

class Librarian {
public:
    void displayBook(Book b) 
	{
        cout << "Title: " << b.title << endl;
        cout << "Price: $" << b.price << endl;
    }

    void applyDiscount(Book& b,float percentage) 
	{
        b.price=b.price-b.price*(percentage / 100);
    }
};

int main() 
{
    Book book("OOP", 50.0);
    Librarian lib;

    lib.displayBook(book);
    lib.applyDiscount(book, 10);
    cout<<"After applying discount:"<<endl;
    lib.displayBook(book);
}
