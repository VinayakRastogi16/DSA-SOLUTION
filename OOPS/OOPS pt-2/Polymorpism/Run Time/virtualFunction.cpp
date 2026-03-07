#include<iostream>
#include<string>
using namespace std;


class Parent{
    public:
        virtual void hello(){
            cout<<"Parent class says hello\n";
        }
};

class Child: public Parent{
    public:
        void hello(){
            cout<<"Child class says hello\n";
        }

};


int main(){
    Child c1;
    Parent c2;
    Parent *ptr;

    ptr = &c1;
    ptr->hello();

    return 0;
}