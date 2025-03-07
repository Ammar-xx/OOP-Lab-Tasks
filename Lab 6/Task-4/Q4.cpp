#include <iostream>
using namespace std;
class Account{
	public:
		long int accNo;
		float balance;
		Account(long int an,float b)
		{
			accNo=an;
			balance=b;
		}
		void displayDetails()
		{
			cout<<"Account Number: "<<accNo<<endl;
			cout<<"Balance: "<<balance<<endl;
		}
};
class SavingsAccount:virtual public Account{
	public:
		float interestRate;
		SavingsAccount(long int an,float b,float ir):Account(an,b)
		{
			interestRate=ir;
		}
		void displayDetails()
		{
			Account::displayDetails();
			cout<<"Interest Rate: "<<interestRate<<"%"<<endl;
		}
};
class CheckingAccount:virtual public Account{
	public:
		float overdraftlimit;
		CheckingAccount(long int an,float b,float odl):Account(an,b)
		{
			overdraftlimit=odl;
		}
		void displayDetails()
		{
			Account::displayDetails();
			cout<<"Over Draft Limit: "<<overdraftlimit<<endl;
		}
};

int main()
{
	SavingsAccount s(123456789,25000,2.5);
	s.displayDetails();
	CheckingAccount c(123456789,30,3.25);
	c.displayDetails();
}