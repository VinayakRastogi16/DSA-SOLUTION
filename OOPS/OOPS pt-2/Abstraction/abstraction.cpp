#include<iostream>
#include<string>
using namespace std;

class Shape{ //abstract class
public:
    virtual void draw() = 0; //pure virtual function, abstract function

};


class Circle : public Shape{
public:
    void draw(){
        cout<<"Draws Circle\n";
    }

};

class Square : public Shape{
public:
    void draw(){
        cout<<"Draws Square\n";
    }

};

class Triangle : public Shape{
public:
    void draw(){
        cout<<"Draws Triangle\n";
    }

};

int main(){
    Circle c1;
    Square s1;
    Triangle t1;

    c1.draw();
    t1.draw();
    s1.draw();

    return 0;
}
