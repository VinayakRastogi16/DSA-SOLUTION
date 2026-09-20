#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int connectRopes(vector<int>& r){
    priority_queue<int, vector<int>, greater<int>> pq(r.begin(), r.end());
    int cost = 0;

    while(pq.size()>1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        cost += min1+min2;

        pq.push(min1+min2);
    }

    return cost;
}


int main(){
    vector<int> ropes = {4, 3, 2, 6};

    cout<<"min cost = "<<connectRopes(ropes)<<endl;

    return 0;
}