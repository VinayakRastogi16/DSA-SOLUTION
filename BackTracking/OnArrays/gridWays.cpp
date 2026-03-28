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

int gridWays(int r, int c, int n, int m, string steps){ //O(2^(n+m))
    if (r==n-1&&c==m-1)
    {
        cout<<steps<<endl;
        return 1;
    }

    if (r>=n || c >=m)
    {
        return 0;
    }
    
    
    int v1 = gridWays(r,c+1,n,m, steps+'R');
    int v2 = gridWays(r+1,c,n,m, steps+'D');

    return v1+v2;
}

int main(){
    int n =4;
    int m =4;
    string steps;
    int back = gridWays(0,0,n,m,steps);
    int numerator = factorial(((n-1)+(m-1)));
    int denominator1 = factorial(n-1);
    int denominator2 = factorial(m-1);
    int ans = numerator/(denominator1*denominator2);
    cout<<"No. of Ways = "<<ans<<endl;
    cout<<"No. of Ways = "<<back<<endl;

    return 0;
}