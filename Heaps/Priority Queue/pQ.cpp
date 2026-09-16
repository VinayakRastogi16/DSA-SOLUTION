#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(9);
    pq.push(2);
    pq.push(10);

    while(!pq.empty()){
        cout<<"top "<<pq.top()<<endl;
        pq.pop();
    }

    return 0;
}