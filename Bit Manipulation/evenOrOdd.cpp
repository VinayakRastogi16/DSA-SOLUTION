#include<iostream>
using namespace std;

void oddOrEven(int num){
    if ((num&1) == 0)
    {
        cout<<"even"<<endl;

    }else{
        cout<<"odd"<<endl;
    }
}

int main(){
    int num;
    cout<<"Enter the number to check"<<endl;
    cin>>num;

    oddOrEven(num);
    
    return 0;
}   