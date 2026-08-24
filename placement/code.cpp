#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;

int maxSum(vector<int>& nums){
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i = 0; i<nums.size(); i++){
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if(sum<0){
            sum = 0;
        }
    }

    return maxSum;
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int ans = maxSum(nums);
    
    cout<<ans<<endl;

    return 0;
}