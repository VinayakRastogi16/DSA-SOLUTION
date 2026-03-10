#include<iostream>
using namespace std;

class Example{

public:
    Example(){
        cout<<"Constructor\n";
    }

    ~Example(){
        cout<<"Destructor\n";
    }

};

int main(){

    int a = 0;
    if (a==0)
    {
        static Example e1;
    }

    cout<<"Code running\n";
    
    return 0;
}