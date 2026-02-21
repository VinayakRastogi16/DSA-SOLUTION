#include <iostream>

using namespace std;

int funcInt(){
    int *ptr = new int;
    *ptr = 123;

    cout<<*ptr<<endl;

    delete ptr;
    return 0;
}

int main(){
    funcInt();

    return 0;
}