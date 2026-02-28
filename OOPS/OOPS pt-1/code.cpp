#include<iostream>

using namespace std;

class Student{
    string name;
    public:
    
    float cgpa;

    //Member functions

    void getPercentage(){
        cout<<cgpa*10<<"\n";
    }
};


int main(){
    Student s1;
    // s1.name = "Vinayak";

    s1.cgpa = 7.91;

    cout<<s1.cgpa<<endl;
    s1.getPercentage();
    // cout<<s1.name<<endl;
    return 0;
}