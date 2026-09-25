#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void unionFun(vector<int>& arr1,vector<int>& arr2){
    unordered_set<int> s;

    for(int i :arr1){
        s.insert(i);
    }

    for(int i: arr2){
        s.insert(i);
    }

    for(int i: s){
        cout<<i<<" ";
    }
}

void intersection(vector<int>& arr1,vector<int>& arr2){
    unordered_set<int> s;

    for(int i :arr1){
        s.insert(i);
    }

    for(int i: arr2){
        if(s.find(i)!=s.end()){
            cout<<i<<" ";
            s.erase(i);
        }
    }
}

int main(){
    vector<int> arr1 = {7,3,9};
    vector<int> arr2 = {6,3,9,2,9,4};

    unionFun(arr1,arr2);
    cout<<endl;
    intersection(arr1,arr2);
    cout<<endl;
    return 0;
}