#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int maxLen(vector<int>& arr){
    unordered_map<int, int> mp;

    mp[0]=-1;
    int sum = 0;
    int len = 0;

    for(int j = 0; j<arr.size(); j++){
        sum += arr[j];

        if(mp.count(sum)){
            int currLen = j-mp[sum];
            len = max(len, currLen);
        }else{
            mp[sum] = j;
        }
    }

    return len;
}

int main(){
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};
    cout<<maxLen(arr)<<endl;
    return 0;
}