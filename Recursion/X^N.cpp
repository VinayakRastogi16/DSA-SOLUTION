#include<iostream>
using namespace std;

int powerOfN(int x,int n){ //homework
    if (n == 0)
    {
        return 1;
    }

    return x * powerOfN(x, n-1);
    

}

int pow(int x,int n){ // O(logn)
    if (n == 0)
    {
        return 1;
    }

    int halfPow = pow(x, n/2);
    int halfPowSquare = halfPow * halfPow;

    if(n%2 != 0){
        //odd
        return x*halfPowSquare;
    }

    return halfPowSquare;
    

}

int main(){

    cout<<pow(2,4)<<endl;

    return 0;
}