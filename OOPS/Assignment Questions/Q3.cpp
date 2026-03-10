#include<iostream>
#include<string>

using namespace std;

class Person{
protected:
    string name;
    int age;


public:
    

    Person(string n, int a){
        name = n;
        age = a;
    }

};

class Student : public Person{
public:
    string StdId;

    Student(string n, int a, string SI):Person(n,a){
        StdId = SI;
    }

    void displayStudentInfo(){
        cout<<name<<", "<<age<<", "<<StdId<<"\n";
    }

};


int main(){
    Student s1("Aloukik",12,"S1234");
    s1.displayStudentInfo();
    return 0;

}