#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int distinct(vector<int>& arr){
    unordered_set<int> s;

    for(int i : arr){
        s.insert(i);
    }

    return s.size();
}

int main(){
    vector<int> arr = {4,3,1,5,6,3,2,6,6,7,9,8,9,5,2,6};

    cout<<distinct(arr)<<"\n";

    return 0;
}