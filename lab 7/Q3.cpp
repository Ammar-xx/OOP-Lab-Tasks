#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double a,string code,string symbol,double rate):amount(a), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() 
	{
        return amount*exchangeRate;
    }

    virtual double convertTo(Currency &targetCurrency)
	{
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency.exchangeRate;
    }

    virtual void displayCurrency() 
	{
        cout<<"Displaying currency\n";
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() override 
	{
        cout << "US Dollar: " << currencySymbol << amount << endl;
    }
    double convertToBase() override 
	{
        cout << "Amount converted to base " << currencyCode << " " << currencySymbol << amount * exchangeRate << endl;
        return amount * exchangeRate;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}
	
	double convertToBase() override 
	{
        cout << "Amount converted to base " << currencyCode << " " << currencySymbol << amount * exchangeRate << endl;
        return amount * exchangeRate;
    }
    void displayCurrency() override 
	{
        cout << "Euro: " << currencySymbol << amount << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs", 0.012) {}
	
	double convertToBase() override 
	{
        cout << "Amount converted to base " << currencyCode << " " << currencySymbol << amount * exchangeRate << endl;
        return amount * exchangeRate;
    }
    void displayCurrency() override {
        cout << "Pakistani Rupee: " << currencySymbol << amount << endl;
    }
};

int main() {
    Dollar usd(100);
    Euro eur(50);
    Rupee pkr(5000);

    cout << "Initial Amounts:\n";
    usd.displayCurrency();
    eur.displayCurrency();
    pkr.displayCurrency();

    cout << "\nConversions:\n";
    cout << "50 EUR to USD: $" << eur.convertTo(usd) << endl;
    cout << "5000 PKR to USD: $" << pkr.convertTo(usd) << endl;
    cout << "100 USD to PKR: Rs" << usd.convertTo(pkr) << endl;
}
