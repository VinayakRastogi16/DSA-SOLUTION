#include<iostream>
#include<string>

using namespace std;

class A{
    int real;
    int img;

public:
    A(int r=0, int i=0){
        real = r;
        img = i;
    }

    A operator +(A& original){
        
        int r = real + original.real;
    int i = img + original.img;
        return A(r,i);
    }
    void display(){
        cout << real << "+" << img << "i\n";
    }

};

int main(){
    A obj1(1,2);
    A obj2(3,4);
    A obj3;
    obj3 = obj1+obj2;
    obj3.display();
}

