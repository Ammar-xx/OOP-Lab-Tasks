#include <iostream>
using namespace std;

class PaymentMethod{
	public:
		virtual void processPayment(double amount)=0;
};

class CreditCard:public PaymentMethod{
	protected:
		string cardNumber;
	public:
		CreditCard(string cn):cardNumber(cn){}
		
		void processPayment(double amount)
		{
			cout<<"Processing credit card payment of Rs."<<amount<<"\nCredit card number: "<<cardNumber<<endl;
		}
};

class DigitalWallet:public PaymentMethod{
	protected:
		double balance;
	public:
		DigitalWallet(double b):balance(b){}
		
		void processPayment(double amount)
		{
			if(balance>=amount)
			{
				balance-=amount;
				cout<<"Your new DigitalWallet balance: "<<balance<<endl;
			}
			else
			{
				cout<<"Not enough balance\n";
			}
		}
};

int main()
{
	CreditCard cc("123-456-789");
	cc.processPayment(825.30);
	DigitalWallet dw(200000.365);
	dw.processPayment(35000);
}