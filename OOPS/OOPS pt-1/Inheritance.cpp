#include<iostream>
#include<string>
using namespace std;

class Animal{ //Parent class
public:
    string color;
    void eat(){
        cout<<"eats\n";

    }

    void breathe(){
        cout<<"breathes\n";
    }
};

class Fish : public Animal{ //Single inheritance
public:
    int fins;

    void swim(){
        cout<<"Can Swim\n";
    }
};

class Mammal : public Animal{ //MLI
public:
    void bloodType(){
        cout<<"Warm\n";
    }
};

class Dog : public Mammal{ //MLI
public:
    void Sound(){
        cout<<"Barks\n";
    }
};


class Teacher{
public:
    float salary;
    string subject;
};

class Student{
    public:
        int roll_no;
        float cgpa;

};


class TA : public Teacher, public Student{
public:
    string name;
};




int main(){
    TA ta1;

    ta1.cgpa = 9.1;
    ta1.roll_no = 207;
    ta1.salary = 15000;
    ta1.subject = "DSA";
    ta1.name = "Vinayak";


    cout<<ta1.cgpa<<"\n"<<ta1.roll_no<<"\n"<<ta1.salary<<"\n"<<ta1.subject<<"\n"<<ta1.name<<endl;


    return 0;
}