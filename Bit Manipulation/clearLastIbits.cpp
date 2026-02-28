#include<iostream>
using namespace std;

void clearIbits(int num, int i){
    int bitMask = (~0)<<i;

    num = num&bitMask;

    cout<<num<<endl;
}

int main(){
    clearIbits(15,2);

    return 0;
}
