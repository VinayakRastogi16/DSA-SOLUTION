#include<iostream>
#include<string>
using namespace std;

class A{

public:

    string d;

    void print(int a,int b){
        cout<<"numerical"<<endl;
    }

    void print(string b){
        cout<<"hello\n";
    }

};

int main(){
    A c1;

    c1.print(1,2);
    c1.print("Hello");

    return 0;
}