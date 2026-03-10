#include<iostream>
#include<string>
using namespace std;

class Complex{
    int real;
    int img;
    string symbol;

public:
    Complex(int r, int i, string op = "+"){
        real = r;
        img = i;
        symbol = op;

    }

    void show(){
        cout<<real<<symbol<<img<<"i\n";
    }

    void operator -(Complex &c2){
        int realResult = this->real - c2.real;
        int imgResult = this->img - c2.img;
        string operand;
        if (c2.symbol == "+" && this->img < c2.img)
        {
            operand = "+";
        }else if(c2.symbol == "-" && this->img < c2.img){
            operand = "-";
        }else if(this->symbol == "-" && this->img > c2.img){
            operand= "-";
        }else if(this->symbol == "+" && this->img > c2.img){
            operand = "+";
        }else{
            operand = "";
        }
        
        Complex c3(realResult, imgResult);
        c3.show();
    }
};

int main(){
    Complex c1(1,2,"+");
    Complex c2(3,1,"+");
    c1.show();
    c2.show();
    c1-c2;
    return 0;
}