#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> StockSpanner(vector<int>& stock, vector<int>& span){
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for(int i =1; i < stock.size(); i++){
        int currPrice = stock[i];
        while(!s.empty() && stock[s.top()] <= currPrice){
            s.pop();
        }

        if(s.empty()){
            span[i] = i+1;
        }
        else{
            int prevHigh = s.top();

            span[i] = i - s.top();
        }

        s.push(i);
    }

    return span;

}


int main(){

    vector<int> stock = {100,80,60,70,60,85,100};
    vector<int> span = {0,0,0,0,0,0,0};

    StockSpanner(stock, span);

    for(auto& x : span){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}