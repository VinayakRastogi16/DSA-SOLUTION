#include<iostream>
#include<string>

using namespace std;

class A{
    int real;
    int img;

public:
    A(int r, int i){
        real = r;
        img = i;
    }

    void operator +(A  &obj2){
        
        int r = this->real + obj2.real;
        int i = this->img + obj2.img;
        A obj3(r,i);
        cout<<"res = ";
        obj3.display();
    }
    void display(){
        cout << real << "+" << img << "i\n";
    }

};

int main(){
    A obj1(1,2);
    A obj2(3,4);
    obj1+obj2;
}

