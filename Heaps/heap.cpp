#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Heap{
    vector<int> vec;

    void heapify(int i){

        if(i>=vec.size())return;

        int l =2*i+1;
        int r =2*i+2;

        int maxI = i;

        if(l<vec.size() && vec[l]>vec[maxI]){
            maxI = l;
        }

        if(r<vec.size() && vec[r]>vec[maxI]){
            maxI = r;
        }

        swap(vec[i], vec[maxI]);

        if(maxI!=i){
            heapify(maxI);
        }

    }

public:

void push(int val){
    vec.push_back(val);

    int x = vec.size()-1;
    int pI = (x-1)/2;

    while(pI>=0 && vec[x]>vec[pI]){ // O(log n)
        swap(vec[x], vec[pI]);

        x = pI;
        pI = (x-1)/2;
    }
}

void pop(){
    swap(vec[0], vec[vec.size()-1]);

    vec.pop_back();

    heapify(0);
}

int top(){
    return vec[0];
}

bool empty(){
    return vec.size()==0;
}

};

int main(){
    Heap h;

    h.push(9);
    h.push(4);
    h.push(8);
    h.push(1);
    h.push(2);
    h.push(5);

    while(!h.empty()){
        cout<<h.top()<<endl;
        h.pop();
    }

    return 0;
}