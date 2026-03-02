#include<iostream>
#include <string>
using namespace std;

class Student{
    string name;
    public:
    
    float cgpa;

    //Member functions

    void getPercentage(){
        cout<<cgpa*10<<"\n";
    }

    //Setters
    void setName(string nameVal){
        name = nameVal;
    }

    //getters
    string getName(){
        return name;
    }
};


int main(){
    Student s1;
    // s1.name = "Vinayak";
    s1.setName("Vinayak");
    cout<<s1.getName()<<endl;
    return 0;
}