#include<iostream> 
using namespace std;

int clearRange(int n, int i, int j){
    int left = (~0)<<(j+1);
    int right = (1<<i) - 1;
    int bitMask = left|right;

    n = n&bitMask;

    return n;
    

}

int main(){
    cout<<clearRange(15,1,3)<<"\n";
    return 0;
}