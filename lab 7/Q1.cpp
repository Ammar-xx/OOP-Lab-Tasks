#include <iostream>
using namespace std;

class Account{
	protected:
		long int accNo;
		int balance;
		string accHolderName;
	public:
		Account(long int a,double b,string n):accNo(a),balance(b),accHolderName(n){}
		
		void deposit(double amount)
		{
			balance+=amount;
			cout<<"Amount deposited successfully\n";
		}
		virtual void withdraw(int amount)
		{
			if(balance>=amount)
			{
				balance-=amount;
				cout<<"Amount withdrawn successfully\n";
			}
			else
			{
				cout<<"Not enough funds\n";
			}
		}
		
		virtual void calculateInterest()
		{
			cout<<"Calculating interest\n";
		}
		
		virtual void printStatement()
		{
			cout<<"Printing transaction history\n";
		}
		
		void getAccountInfo()
		{
			cout<<"Account Number: "<<accNo<<endl;
			cout<<"Account Holder Name: "<<accHolderName<<endl;
			cout<<"Balance: "<<balance<<endl;
		}
};

class SavingsAccount:public Account{
	protected:
		double interestRate;
		int minimumBalance;
	public:
		SavingsAccount(long int a,int b,string n,double r,int mb):Account(a,b,n),interestRate(r),minimumBalance(mb){}
		
		void calculateInterest() override
		{
        	double interest=balance*(interestRate/100);
        	balance+=interest;
        	cout << "Interest added: " << interest << " New Balance: " << balance << endl;
		}
		void printStatement()
		{
			cout<<"Printing savings account transaction history\n";
		}
		void withdraw(int amount) override
		{
			if(balance>amount)
			{
				if(balance-amount>=minimumBalance)
				{
					balance-=amount;
					cout<<"Amount withdrawn successfully\n";
				}
				else
				{
					cout<<"Unable to withdraw as the balance would become less than the minimum limit\n";
				}
			}
			else
			{
				cout<<"Not enough funds\n";
			}
		}
};

class CheckingAccount:public Account{
	protected:
		int overdraftlimit;
	public:
		CheckingAccount(long int a,int b,string n,double odl):Account(a,b,n),overdraftlimit(odl){}
		
		void calculateInterest() override
		{
        	cout<<"Checking Accounts donot have interest\n";
		}
		void printStatement()
		{
			cout<<"Printing checking account transaction history\n";
		}
		void withdraw(int amount) override 
		{
        if ((balance-amount)>=-overdraftlimit) 
		{
            balance -= amount;
            cout << "Amount withdrawn successfully. New Balance: " << balance << endl;
        } 
		else 
		{
            cout << "Withdrawal denied! Overdraft limit exceeded." << endl;
        }
    }
};

class FixedDepositAccount:public Account{
	protected:
		string maturityDate;
		double fixedInterestRate;
	public:
		FixedDepositAccount(long int a,int b,string n,string date,double rate):Account(a,b,n),maturityDate(date),fixedInterestRate(rate){
		}
		void calculateInterest() override
		{
        	double interest=balance*(fixedInterestRate/100);
        	balance+=interest;
        	cout << "Interest added: " << interest << " New Balance: " << balance << endl;
		}
		void printStatement() override
		{
			cout<<"Printing fixed deposit account transaction history\n";
		}
};

int main() {
    SavingsAccount savings(478235,5000,"Muhammad Ammar",3.5,1000);
    FixedDepositAccount fixed(478236, 10000, "Ismail","2026-12-31",5.0);
    CheckingAccount checking(478238,2000,"John",500);

    cout << "Outputs for Savings Account" << endl;
    savings.getAccountInfo();
    savings.deposit(500);
    savings.withdraw(3000);
    savings.calculateInterest();
    savings.printStatement();
    cout << endl << endl << "Outputs for Fixed Deposit Account" << endl;
    fixed.getAccountInfo();
    fixed.deposit(5000);
    fixed.withdraw(100);
    fixed.calculateInterest();
    fixed.printStatement();
    cout<< "Outputs for Checking Account" << endl;
    checking.getAccountInfo();
    checking.deposit(500);
    checking.withdraw(3000);
    checking.calculateInterest();
    checking.printStatement();

}