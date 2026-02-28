#include<iostream>
using namespace std;

void setIthBit(int num, int i, int val){
    //clear
    int bitMask = (1<<i);
    num = num&(~bitMask);


    num = num| (val<<i);


    cout<<num<<endl;
}

int main(){

    setIthBit(7,2,0);
    setIthBit(7,3,1);

    return 0;
}