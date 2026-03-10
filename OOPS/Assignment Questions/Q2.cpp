#include<iostream>
#include<string>

using namespace std;

class BankAccount{
    int accountNumber;
    double balance = 0;

public:
    BankAccount(int accNum, double bal){
        accountNumber = accNum;
        balance = bal;
    }

    void deposit(int b){
        balance += b; 
    }

    void withdraw(int b){
        balance -= b;
    }

    float getBalance(){
        return balance; 
    }
};

int main(){
    BankAccount b1(23131,3302.23);
    cout<<b1.getBalance()<<endl;
    b1.deposit(200);
    cout<<b1.getBalance()<<endl;
    b1.withdraw(100);
    cout<<b1.getBalance()<<endl;

    return 0;
}