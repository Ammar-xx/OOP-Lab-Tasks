#include <iostream>
using namespace std;

class Fraction {
	private:
    	int numerator;
    	int denominator;

    	int gcd(int a, int b) 
		{
        	while (b!=0) 
			{
            	int temp = b;
            	b = a % b;
            	a = temp;
        	}
        	return a;
    	}

    	void simplify() 
		{
        	int g=gcd(numerator, denominator);
        	numerator=numerator/g;
        	denominator=denominator/g;
    	}

	public:
    	Fraction(int num,int denom) 
		{
        	numerator = num;
        	denominator = denom;
        	simplify();
    	}

    	Fraction operator+(Fraction other) 
		{
        	int num=numerator*other.denominator+other.numerator*denominator;
        	int denom=denominator*other.denominator;
        	return Fraction(num,denom);
    	}

    	Fraction operator-(Fraction other)  
		{
        	int num=numerator*other.denominator-other.numerator*denominator;
        	int denom=denominator*other.denominator;
        	return Fraction(num, denom);
    	}

    	Fraction operator*(Fraction other) 
		{
        	return Fraction(numerator * other.numerator, denominator * other.denominator);
    	}

    	Fraction operator/(Fraction other) 
		{
        	return Fraction(numerator * other.denominator, denominator * other.numerator);
    	}

    	friend ostream& operator<<(ostream& out, Fraction f) 
		{
        	out << f.numerator << "/" << f.denominator;
        	return out;
    	}
};

int main() 
{
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    Fraction sum=f1+f2;
    Fraction diff=f1-f2;
    Fraction prod=f1*f2;
    Fraction quot=f1/f2;

    cout<<"f1+f2= "<<sum<<endl;
    cout<<"f1-f2= "<<diff<<endl;
    cout<<"f1*f2= "<<prod<<endl;
    cout<<"f1/f2= "<<quot<<endl;

}
