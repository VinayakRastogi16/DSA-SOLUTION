#include<iostream>
#include<string>
using namespace std;

class A{
public:
    A(){
        cout<<"Parent Constructor\n";
    }

    ~A(){
        cout<<"Parent Destructor\n";
    }
};


class B : public A{
public:
    B(){
        cout<<"Child Constructor\n";
    }

    ~B(){
        cout<<"Child Destructor\n";
    }
};



int main(){
    B b1;

    return 0;
}