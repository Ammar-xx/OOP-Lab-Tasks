#include <iostream>
using namespace std;

class Currency {
	private:
    	double value;

	public:
    	Currency(double v) : value(v) {}

    	Currency operator-() 
		{
        	return Currency(-value);
    	}

    	Currency operator+(Currency other) 
		{
        	return Currency(value + other.value);
    	}

    	Currency operator-(Currency other)  
		{
        	return Currency(value - other.value);
    	}

    	Currency& operator+=(Currency other) 
		{
        	value += other.value;
        	return *this;
    	}

    	Currency& operator-=(Currency other) 
		{
        	value -= other.value;
        	return *this;
    	}

    	friend ostream& operator<<(ostream& os,Currency c) 
		{
        	os << "$" << c.value;
        	return os;
    	}
};

int main() {
    Currency c1(100.50),c2(50.25);
    Currency total = c1 + c2;
    Currency diff = c1 - c2;
    Currency negated = -c1;

    c1 += c2;
    c2 -= Currency(10.00);

    cout << "Total: " << total << endl;
    cout << "Difference: " << diff << endl;
    cout << "Negated Price1: " << negated << endl;
    cout << "Updated Price1: " << c1 << endl;
    cout << "Discounted Price2: " << c2 << endl;

}
