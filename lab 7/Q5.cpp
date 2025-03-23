#include <iostream>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string date, string id, string p):title(t), publicationDate(date), uniqueID(id), publisher(p) {}

    virtual void displayInfo() 
	{
        cout<<"Title: "<<title<<endl;
		cout<<"Publication Date: "<<publicationDate<<endl;
        cout<<"Unique ID: "<<uniqueID<<endl;
		cout<<"Publisher: "<<publisher<<endl;
    }

    void checkOut() {
        cout << title << " checked out." << endl;
    }

    void returnItem() {
        cout << title << " returned." << endl;
    }
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string date, string id, string p, string auth, string isbn, int pages):Media(t, date, id, p), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override 
	{
        Media::displayInfo();
        cout<<"Author: "<<author<<endl; 
		cout<<"ISBN: "<<ISBN<<endl; 
        cout<<"Pages: "<<numberOfPages<<endl;
    }
};

class DVD : public Media {
    string director;
    double duration, rating;
public:
    DVD(string t, string pubDate, string id, string pub, string dir, double dur, double rate):Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override 
	{
        Media::displayInfo();
        cout<<"Director: "<<director<<endl;
		cout<<"Duration: "<<duration<<" hours\n"<<endl;
		cout<<"Rating: "<<rating<<endl;
    }
};

class CD : public Media {
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t,string pubDate,string id,string pub,string art,int tracks,string gen):Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override 
	{
        Media::displayInfo();
        cout<<"Artist: "<<artist<<endl;
		cout<<"Tracks: "<<numberOfTracks<<endl;
        cout<< "\nGenre: " <<genre<<endl;
    }
};

class Magazine:public Media{
    int issueNumber;
	public:
    Magazine(string t,string pubDate,string id,string pub,int issue):Media(t,pubDate,id,pub),issueNumber(issue) {}

    void displayInfo() override
	{
        Media::displayInfo();
        cout<<"Issue Number: "<<issueNumber<<endl;
    }
};

void searchMedia(string title) 
{
    cout << "Searching media by title: "<<title<<endl;
}

void searchMedia(string author,int dummy) 
{
    cout << "Searching books by author: "<<author<<endl;
}

void searchMedia(int year) 
{
    cout << "Searching media by publication year: "<<year<<endl;
}

int main() 
{
    Book b("C++ Programming", "2022", "B101", "TechPub", "John Doe", "123456789", 500);
    DVD d("Inception", "2010", "D202", "Warner Bros", "Christopher Nolan", 2.5, 9.0);
    CD c("Thriller", "1982", "C303", "Epic Records", "Michael Jackson", 9, "Pop");
    Magazine m("National Geographic", "2023", "M404", "NatGeo", 57);
    b.displayInfo();
    d.displayInfo();
    c.displayInfo();
    m.displayInfo();
    b.checkOut();
    d.returnItem();
    searchMedia("C++ Programming");
    searchMedia("John Doe", 0);
    searchMedia(2022);
}
