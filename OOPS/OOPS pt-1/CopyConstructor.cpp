#include <iostream>
#include<string>

using namespace std;

class Car{
    public:
    string name;
    string color;
    int *mileage;


    Car(string name, string color){
        (*this).color = color;
        (*this).name = name;
        mileage = new int; //Dynamic allocation
        *mileage = 12;
    }

    Car(Car &original){
        cout<<"Copying...\n";
        name = original.name;
        color = original.color;
        mileage = new int;
        *mileage = *original.mileage;
    }

    ~Car(){
        cout<<"Deletin objects..\n";
    }


};


int main(){

    Car c1("Porche", "Black");
    cout<<c1.name<<endl;
    cout<<c1.color<<endl;
    cout<<*c1.mileage<<endl;
    

    return 0;
}