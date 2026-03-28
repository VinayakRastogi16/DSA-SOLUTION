#include<iostream>
#include<climits>
using namespace std;

int powerOfN(int x,int n){ //homework
    if (n == 0)
    {
        return 1;
    }

    return x * powerOfN(x, n-1);
    

}

double solve(double x, long long n) {
    if (n == 0) return 1;

    double half = solve(x, n / 2);

    if (n % 2 == 0) return half * half;
    return x * half * half;
}

double myPow(double x, int n) {
    long long N = n;

    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    return solve(x, N);
}

int main(){

    cout<<myPow(1.21231,912309103)<<endl;

    return 0;
}