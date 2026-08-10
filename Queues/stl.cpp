#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<int> q;

    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);

    while(!q.empty()){
        cout<<q.front()<<endl;

        q.pop();
    }

    return 0;
}