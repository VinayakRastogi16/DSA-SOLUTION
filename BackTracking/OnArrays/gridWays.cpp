#include<iostream>
#include<vector>
#include<string>

using namespace std;

int factorial(int n){ //O(n+m)
    if(n==0||n==1){
        return n;
    }

    return n*factorial(n-1);

}

int gridWays(int n, int m){ //O(2^(n+m))
    if (m==0&&n==0)
    {
        return 1;
    }

    if (n<0 || m <0)
    {
        return 0;
    }
    
    
    int v1 = gridWays(n-1,m);
    int v2 = gridWays(n,m-1);

    return v1+v2;
}

int main(){
    int n =4;
    int m =4;
    string steps;
    int back = gridWays(n,m);
    int numerator = factorial(((n-1)+(m-1)));
    int denominator1 = factorial(n-1);
    int denominator2 = factorial(m-1);
    int ans = numerator/(denominator1*denominator2);
    cout<<"No. of Ways = "<<ans<<endl;
    cout<<"No. of Ways = "<<back<<endl;

    return 0;
}