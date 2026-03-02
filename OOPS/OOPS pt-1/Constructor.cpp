#include<iostream>
#include<string>

using namespace std;



class Car{

    string name;
    string color;

    public:

        Car(){  //constructor overloading
            cout<<"Constructor w/o params.\n";
        }

        Car(string name, string color){  //constructor overloading
            this->name = name;
            (*this).color = color;
            cout<<"Object created! Constructor called!\n";

        }

        void start(){
            cout<<"Car started!"<<endl;

        }

        void stop(){
            cout<<"Car stopped!"<<endl;
        }

        string getVal(){
            return name;
        }

};

int main(){
    Car c0;
    Car c1("BMW", "Pink");
    Car c2("Porche", "Black");

    return 0;

}