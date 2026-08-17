#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int indianCoins(vector<int>& coins, int V){

    int n = coins.size();
    int ans = 0;
    for(int i = n-1; i>=0 && V>0; i--){
        if(V>= coins[i]){
            ans+= V/coins[i];
            V = V%coins[i];
        }
    }

    return ans;
}

int main(){
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int V= 590;

    cout<<indianCoins(coins, V)<<endl;
    return 0;
}