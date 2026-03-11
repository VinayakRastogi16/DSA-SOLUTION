#include<iostream>
#include<string>
using namespace std;

int factorial(int n){ //recurssive func()
    if (n==0)
    {
        return 1;
    }
    

    return n* factorial(n-1);
}


int main(){
    cout<<"4! = "<<factorial(4)<<endl;

    return 0;
}