#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int cntSubArr(vector<int>& arr, int k){
    unordered_map<int, int> mp;
    mp[0]=1;
    int sum =0;
    int ans = 0;

    for(int i = 0; i<arr.size(); i++){
        sum+=arr[i];

        if(mp.count(sum- k)){
            ans += mp[sum-k];
        }

        if(mp.count(sum)){
            mp[sum]++;
        }else{
            mp[sum] = 1;
        }
    }
    
    return ans;
}

int main(){
    vector<int> arr = {10, 2, -2, -20, 10};
    cout<<cntSubArr(arr, -10)<<endl;
    return 0;
}