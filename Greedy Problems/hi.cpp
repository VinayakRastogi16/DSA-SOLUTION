#include<iostream>
#include<algorithm>
using namespace std;

int countDigits(long long n) {
        int count = 0;
        // Use abs() if you want to support negative integers safely
        n = std::abs(n); 
        
        do {
            count++;
            n /= 10;
        } while (n > 0);
        
        return count;
    }

    long long sumAndMultiply(int n) {
        long long temp = 0;
        long long x = 0;

        while(n!=0){
            if(n%10==0) continue;
            temp = n%10;
            x += temp*10^countDigits(temp);
        }

        return x;
    }


int main(){
    int n = 10203004;

    cout<<sumAndMultiply(n)<<endl;

    return 0;
}