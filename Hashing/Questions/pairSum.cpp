#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> pairSum(vector<int> arr, int t){
    unordered_map<int, int> mp;
    for(int i = 0; i<arr.size(); i++){
        int diff = t-arr[i];

        if(mp[diff]){
            return {mp[diff], i};
        }

        mp[arr[i]] = i;
    }

    return {-1, -1};
    
}

int main(){
    vector<int> arr = {1, 2, 7, 11, 15, 5, 9};

    int t = 9;

    vector<int> ans = pairSum(arr, t);

    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}